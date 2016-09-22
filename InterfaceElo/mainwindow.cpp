#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Init GUI
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    // Init configuration
    cf.nbIteration = 30;
    cf.stepbystep = false;


    //define this to send output to a text file (see locations.h)
    #ifdef TEXTOUTPUT
      os.open("output.txt");
    #endif

    //seed random number generator
    srand((unsigned) time(NULL));

    //create a miner
    Bob = new Miner(ent_Miner_Bob);

    //create his wife
    Elsa = new MinersWife(ent_Elsa);

    //create the waitress
    Jessica = new Waitress(ent_Jessica);

    //register them with the entity manager
    EntityMgr->RegisterEntity(Bob);
    EntityMgr->RegisterEntity(Elsa);
    EntityMgr->RegisterEntity(Jessica);


    // init Bob
    ui->checkBoxThirst->setEnabled(false);
    ui->checkBoxFatigue->setEnabled(false);
    ui->checkBoxCook->setEnabled(false);

    ui->progressBar->setMaximum(30);
    ui->progressBar->setMinimum(0);

    updater = new GUIUpdater();
    updater->setIteration(cf.nbIteration);
    connect(updater, SIGNAL(newUpdate()), SLOT(updateGui()));
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

void MainWindow::updateGui() {
    /* ui->progressBar->raise();

    //run Bob and Elsa through a few Update calls
    for (int i=0; i<30; ++i)
    {
      Bob->Update();
      Elsa->Update();
      Jessica->Update();

      //dispatch any delayed messages
      Dispatch->DispatchDelayedMessages();

      Sleep(800);
    } */
    Bob->Update();
    Elsa->Update();
    Jessica->Update();

    //dispatch any delayed messages
    Dispatch->DispatchDelayedMessages();

    // Update Bob
    ui->sbBank->setValue(Bob->Wealth());
    ui->sbGold->setValue(Bob->GoldCarried());
    ui->sbThirst->setValue(Bob->GetThirst());
    ui->sbFatigue->setValue(Bob->GetFatigue());
    ui->checkBoxThirst->setChecked(Bob->Thirsty());
    ui->checkBoxFatigue->setChecked(Bob->Fatigued());

    // Update Elsa
    ui->checkBoxCook->setChecked(Elsa->Cooking());

    // Update Jessica
    ui->sbGold_2->setValue(Jessica->GoldTips());
    ui->sbBeauty->setValue(Jessica->GetSweat());
    ui->sbBored->setValue(Jessica->GetBoredom());

    ui->progressBar->setValue(ui->progressBar->value()+1);
}


void MainWindow::on_pushButton_clicked()
{
    updater->start();

    ui->pushButton_2->setEnabled(false);
    ui->sbThirst->setEnabled(false);
    ui->sbFatigue->setEnabled(false);
    ui->sbGold->setEnabled(false);
    ui->sbBank->setEnabled(false);
    ui->sbBeauty->setEnabled(false);
    ui->sbBored->setEnabled(false);
    ui->sbGold_2->setEnabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->setEnabled(false);

    ConfigDialog cfd(&cf, this);
    cfd.show();
    cfd.exec();

    this->setEnabled(true);

    updater->setIteration(cf.nbIteration);
}

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
