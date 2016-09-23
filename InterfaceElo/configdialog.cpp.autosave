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
}
