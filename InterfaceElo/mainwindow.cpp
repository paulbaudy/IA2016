#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);


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
    ui->lcdBank->display(Bob->Wealth());
    ui->lcdGold->display(Bob->GoldCarried());
    ui->checkBoxThirst->setChecked(Bob->Thirsty());
    ui->checkBoxFatigue->setChecked(Bob->Fatigued());

    // Update Elsa
    ui->checkBoxCook->setChecked(Elsa->Cooking());

    // Update Jessica
    ui->lcdGoldJess->display(Jessica->GoldTips());

    ui->progressBar->setValue(ui->progressBar->value()+1);

}


void MainWindow::on_pushButton_clicked()
{
    updater->start();

    ui->pushButton_2->setEnabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->setEnabled(false);

    ConfigDialog cf;
    cf.show();
    cf.exec();

    this->setEnabled(true);
}
