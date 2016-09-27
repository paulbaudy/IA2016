#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "q_debugstream.h"

QMutex m_mutex_qlabel;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Init GUI
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    //Redirect Console output to QTextEdit
    Q_DebugStream* dst = new Q_DebugStream(std::cout, ui->log);
    ui->log->setReadOnly(true);
    connect(dst, SIGNAL(emitConsole(QString)), this, SLOT(updateConsole(QString)));

    qRegisterMetaType<location_type>("location_type");

    //define this to send output to a text file (see locations.h)
    #ifdef TEXTOUTPUT
      os.open("output.txt");
    #endif

    //seed random number generator
    srand((unsigned) time(NULL));

    //locations list
    locations[goldmine] = ui->Mine;
    locations[bank] = ui->Bank;
    locations[saloon] = ui->Bar;
    locations[saloonRestroom] = ui->Toilets;
    locations[saloonPiano] = ui->Piano;
    locations[shack] = ui->Home;

    //create a miner
    Bob = new Miner(ent_Miner_Bob, locations, ui->Bob);
    connect(Bob, SIGNAL(newLocation(location_type, QLabel*)), this, SLOT(moveEntity(location_type,QLabel*)));

    //create his wife
    Elsa = new MinersWife(ent_Elsa, locations, ui->Elsa);
    connect(Elsa, SIGNAL(newLocation(location_type, QLabel*)), this, SLOT(moveEntity(location_type, QLabel*)));

    //create the waitress
    Jessica = new Waitress(ent_Jessica, locations, ui->Jessica);
    connect(Jessica, SIGNAL(newLocation(location_type, QLabel*)), this, SLOT(moveEntity(location_type, QLabel*)));


    // Init configuration
    cf.nbIteration = 50;
    cf.stepbystep = false;
    cf.bob_state = Bob->GetFSM()->CurrentState();
    cf.elsa_state = Elsa->GetFSM()->CurrentState();
    cf.jess_state = Jessica->GetFSM()->CurrentState();


    //register them with the entity manager
    EntityMgr->RegisterEntity(Bob);
    EntityMgr->RegisterEntity(Elsa);
    EntityMgr->RegisterEntity(Jessica);


    // init checkbox disabled
    ui->checkBoxThirst->setEnabled(false);
    ui->checkBoxFatigue->setEnabled(false);
    ui->checkBoxGold->setEnabled(false);
    ui->checkBoxKissed->setEnabled(false);
    ui->checkBoxCook->setEnabled(false);
    ui->checkBoxSweat->setEnabled(false);
    ui->checkBoxBoredom->setEnabled(false);

    // Init progressbar
    ui->progressBar->setMaximum(cf.nbIteration);
    ui->progressBar->setMinimum(0);

    // Init thread for GUI update
    updater = new GUIUpdater();
    updater->setIteration(cf.nbIteration);
    updater->setStepByStep(cf.stepbystep);
    connect(updater, SIGNAL(newUpdate()), SLOT(updateGui()));
    connect(updater, SIGNAL(simulationfFinished()), SLOT(endOfSimulation()));
    connect(updater, SIGNAL(finished()), updater, SLOT(deleteLater()));
}

MainWindow::~MainWindow()
{
    //tidy up
    delete ui;
    delete Bob;
    delete Elsa;
    delete Jessica;
}

void MainWindow::moveEntity(location_type loc, QLabel* img) {
    if(locations.contains(loc))
         img->move(locations.value(loc)->x(), locations.value(loc)->y()+50);
}

void MainWindow::updateConsole(QString msg) {
    ui->log->append(msg);
    ui->log->moveCursor(QTextCursor::End);
}

void MainWindow::updateGui() {
    EntityUpdate * t_Bob = new EntityUpdate(Bob);
    connect(t_Bob, SIGNAL(finished()), t_Bob, SLOT(deleteLater()));
    t_Bob->start();
    EntityUpdate * t_Elsa = new EntityUpdate(Elsa);
    connect(t_Elsa, SIGNAL(finished()), t_Elsa, SLOT(deleteLater()));
    t_Elsa->start();
    EntityUpdate * t_Jessica = new EntityUpdate(Jessica);
    connect(t_Jessica, SIGNAL(finished()), t_Jessica, SLOT(deleteLater()));
    t_Jessica->start();

    t_Bob->wait();
    t_Elsa->wait();
    t_Jessica->wait();

    //dispatch any delayed messages
    Dispatch->DispatchDelayedMessages();

    //Update infos
    updateInfos();

    ui->progressBar->setValue(ui->progressBar->value()+1);
}

void MainWindow::updateInfos(){
    // Update Bob
    ui->sbBank->setValue(Bob->Wealth());
    ui->sbGold->setValue(Bob->GoldCarried());
    ui->sbThirst->setValue(Bob->GetThirst());
    ui->sbFatigue->setValue(Bob->GetFatigue());
    ui->checkBoxThirst->setChecked(Bob->Thirsty());
    ui->checkBoxFatigue->setChecked(Bob->Fatigued());
    ui->checkBoxGold->setChecked(Bob->PocketsFull());
    ui->checkBoxKissed->setChecked(Bob->Kissed());

    // Update Elsa
    ui->checkBoxCook->setChecked(Elsa->Cooking());

    // Update Jessica
    ui->sbGold_2->setValue(Jessica->GoldTips());
    ui->sbBeauty->setValue(Jessica->GetSweat());
    ui->sbBored->setValue(Jessica->GetBoredom());
    ui->checkBoxSweat->setChecked(Jessica->isSweaty());
    ui->checkBoxBoredom->setChecked(Jessica->isBored());
}

void MainWindow::setInfosByDefault(){
    //Bob's infos
    Bob->SetWealth(0);
    Bob->SetGoldCarried(0);
    Bob->SetThirst(0);
    Bob->SetFatigue(0);
    Bob->cleanLipstick();
    Bob->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());

    //Elsa's infos
    Elsa->SetCooking(false);
    Elsa->GetFSM()->ChangeState(DoHouseWork::Instance());

    //Jessica's infos
    Jessica->SetGoldTips(0);
    Jessica->SetSweat(0);
    Jessica->SetBoredom(0);
    Jessica->GetFSM()->ChangeState(Bartend::Instance());

    //Clean log
    ui->log->setText("");
}

void MainWindow::setInfosEnabled(bool val){
    ui->pushButton_2->setEnabled(val);
    ui->sbThirst->setEnabled(val);
    ui->sbFatigue->setEnabled(val);
    ui->sbGold->setEnabled(val);
    ui->sbBank->setEnabled(val);
    ui->sbBeauty->setEnabled(val);
    ui->sbBored->setEnabled(val);
    ui->sbGold_2->setEnabled(val);
    ui->actionReset_values_by_default->setEnabled(val);
}

//----------------
// Button events
//----------------
void MainWindow::on_pushButton_clicked()
{
    //Disable infos changes
    setInfosEnabled(false);

    if(cf.stepbystep) {
        updater->doStep();
    }else {
        updater->start();
        ui->pushButton->setEnabled(false);
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    this->setEnabled(false);

    ConfigDialog cfd(&cf, this);
    cfd.show();
    cfd.exec();

    this->setEnabled(true);

    updater->setIteration(cf.nbIteration);
    updater->setStepByStep(cf.stepbystep);

    ui->progressBar->setMaximum(cf.nbIteration);

    if(cf.stepbystep) {
        ui->pushButton->setText("Next");
    }else {
        ui->pushButton->setText("Launch");
    }

    Bob->GetFSM()->ChangeState(cf.bob_state);
    Elsa->GetFSM()->ChangeState(cf.elsa_state);
    Jessica->GetFSM()->ChangeState(cf.jess_state);

    ui->log->setText("");

}

void MainWindow::endOfSimulation() {
    setInfosEnabled(true);
    ui->progressBar->setValue(0);

    if(!cf.stepbystep)
        ui->pushButton->setEnabled(true);

    updater = new GUIUpdater();
    updater->setIteration(cf.nbIteration);
    updater->setStepByStep(cf.stepbystep);
    connect(updater, SIGNAL(newUpdate()), SLOT(updateGui()));
    connect(updater, SIGNAL(simulationfFinished()), SLOT(endOfSimulation()));
    connect(updater, SIGNAL(finished()), updater, SLOT(deleteLater()));
}

//---------------
// Menu events
//---------------

void MainWindow::on_actionReset_values_by_default_triggered()
{
    setInfosByDefault();
    updateInfos();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

//------------------
// Infos events
//------------------
void MainWindow::on_sbThirst_editingFinished()
{
    Bob->SetThirst(ui->sbThirst->value());
}

void MainWindow::on_sbFatigue_editingFinished()
{
    Bob->SetFatigue(ui->sbFatigue->value());
}

void MainWindow::on_sbGold_editingFinished()
{
    Bob->SetGoldCarried(ui->sbGold->value());
}

void MainWindow::on_sbBank_editingFinished()
{
    Bob->SetWealth(ui->sbBank->value());
}

void MainWindow::on_sbBeauty_editingFinished()
{
    Jessica->SetSweat(ui->sbBeauty->value());
}

void MainWindow::on_sbBored_editingFinished()
{
    Jessica->SetBoredom(ui->sbBored->value());
}

void MainWindow::on_sbGold_2_editingFinished()
{
    Jessica->SetGoldTips(ui->sbGold_2->value());
}
