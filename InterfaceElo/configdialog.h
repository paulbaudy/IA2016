#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include "configuration.h"


namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(configuration* cf, QWidget *parent = 0);
    ~ConfigDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigDialog *ui;
    configuration *cf;
};

#endif // CONFIGDIALOG_H
