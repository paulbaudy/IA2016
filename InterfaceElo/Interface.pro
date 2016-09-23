#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T16:24:44
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH +=$$PWD/Common



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    BaseGameEntity.cpp \
    EntityManager.cpp \
    MessageDispatcher.cpp \
    Miner.cpp \
    MinerOwnedStates.cpp \
    MinersWife.cpp \
    MinersWifeOwnedStates.cpp \
    Waitress.cpp \
    WaitressOwnedStates.cpp \
    Common/Time/CrudeTimer.cpp \
    configdialog.cpp

HEADERS  += mainwindow.h \
    BaseGameEntity.h \
    EntityManager.h \
    EntityNames.h \
    Locations.h \
    MessageDispatcher.h \
    MessageTypes.h \
    Miner.h \
    MinerOwnedStates.h \
    MinersWife.h \
    MinersWifeOwnedStates.h \
    Waitress.h \
    WaitressOwnedStates.h \
    Common/Time/CrudeTimer.h \
    configdialog.h \
    configuration.h \
    q_debugstream.h

FORMS    += mainwindow.ui \
    configdialog.ui
