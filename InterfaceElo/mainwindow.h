#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMap>
#include <QRect>
#include <QMutex>

#include <fstream>
#include <time.h>
#include <thread>

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


class EntityUpdate : public QThread {
    Q_OBJECT
    void run() {
        entity->Update();
    }

    BaseGameEntity* entity;
public:
    EntityUpdate(BaseGameEntity* entity) {
        this->entity = entity;
    }
};

class GUIUpdater : public QThread {

    Q_OBJECT
    void run() {
        for(int i = 0; i<nbIteration; ++i) {
            emit newUpdate();
            Sleep(1000);
        }
        emit simulationfFinished();
        Sleep(1000);
    }

    int nbIteration;
    int currentIteration = 0;
    bool stepByStep;
public:
    void setIteration(int nb) {
        nbIteration = nb;
    }
    void setStepByStep(bool val) {
        stepByStep = val;
    }

    void doStep() {
        if(stepByStep && currentIteration<nbIteration) {
            emit newUpdate();
            currentIteration++;

            if(currentIteration==nbIteration) {
                emit simulationfFinished();
            }

        }
    }

signals:
    void newUpdate();
    void simulationfFinished();
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateGui();
    void updateInfos();
    void setInfosByDefault();
    void setInfosEnabled(bool val = true);
    void endOfSimulation();
    void moveEntity(location_type loc, QLabel* img);
    void updateConsole(QString msg);

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

    void on_actionQuit_triggered();

    void on_actionReset_values_by_default_triggered();

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
    QMap<location_type, QLabel*> locations;

};



#endif // MAINWINDOW_H
