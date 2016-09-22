#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "Waitress.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "configuration.h"
#include "configdialog.h"


namespace Ui {
class MainWindow;
}

class GUIUpdater : public QThread {

    Q_OBJECT
    void run() {
        for(int i = 0; i<nbIteration; ++i) {
            emit newUpdate();
            Sleep(1000);
        }

    }
    int nbIteration;
public:
    void setIteration(int nb) {
        nbIteration = nb;
    }

signals:
    void newUpdate();
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateGui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sbThirst_editingFinished();

    void on_sbFatigue_editingFinished();

    void on_sbGold_editingFinished();

    void on_sbBank_editingFinished();

    void on_sbBeauty_editingFinished();

    void on_sbBored_editingFinished();

    void on_sbGold_2_editingFinished();

private:
    Ui::MainWindow *ui;
    configuration cf;

    //create a miner
    Miner* Bob;

    //create his wife
    MinersWife* Elsa;

    //create the waitress
    Waitress* Jessica;

    GUIUpdater *updater;
};



#endif // MAINWINDOW_H
