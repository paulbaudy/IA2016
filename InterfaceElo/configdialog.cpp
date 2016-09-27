#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(configuration *cf, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    this->cf = cf;


}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::on_buttonBox_accepted()
{
    cf->nbIteration = ui->sb_iteration->value();
    cf->stepbystep = ui->cbStep->isChecked();

    cf->bob_state = getBobState(ui->bobPlace->currentText());
    cf->elsa_state = getElsaState(ui->elsaPlace->currentText());
    cf->jess_state = getJessicaState(ui->jessPlace->currentText());
}

State<Miner>* ConfigDialog::getBobState(QString text) {
    if(text == "Shack") {
        return GoHomeAndSleepTilRested::Instance();
    }
    if(text == "Goldmine") {
        return EnterMineAndDigForNugget::Instance();
    }
    if(text == "Saloon") {
        return QuenchThirst::Instance();
    }
    if(text == "Bank") {
        return VisitBankAndDepositGold::Instance();
    }
}

State<MinersWife>* ConfigDialog::getElsaState(QString text) {
    if(text == "Shack") {
        return DoHouseWork::Instance();
    }
    if(text == "Bathroom") {
        return VisitBathroom::Instance();
    }
}

State<Waitress>* ConfigDialog::getJessicaState(QString text) {
    if(text == "Saloon") {
        return Bartend::Instance();
    }
    if(text == "Restroom") {
        return EnterRestroomAndMakeUp::Instance();
    }
    if(text == "Piano") {
        return PractisePiano::Instance();
    }
}
