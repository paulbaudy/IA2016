/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReset_values_by_default;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QTextEdit *log;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QCheckBox *checkBoxCook;
    QFrame *frame;
    QFormLayout *formLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *sbGold;
    QSpinBox *sbFatigue;
    QSpinBox *sbBank;
    QCheckBox *checkBoxFatigue;
    QCheckBox *checkBoxThirst;
    QSpinBox *sbThirst;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QCheckBox *checkBoxKissed;
    QCheckBox *checkBoxGold;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QSpinBox *sbBeauty;
    QLabel *label_8;
    QSpinBox *sbBored;
    QLabel *label_5;
    QLabel *label_7;
    QSpinBox *sbGold_2;
    QCheckBox *checkBoxSweat;
    QCheckBox *checkBoxBoredom;
    QFrame *frame_2;
    QLabel *Bank;
    QLabel *Mine;
    QLabel *Home;
    QLabel *Bar;
    QLabel *Piano;
    QLabel *Toilets;
    QLabel *Bob;
    QLabel *Elsa;
    QLabel *Jessica;
    QMenuBar *menuBar;
    QMenu *menuResert_values_by_default;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 516);
        actionReset_values_by_default = new QAction(MainWindow);
        actionReset_values_by_default->setObjectName(QStringLiteral("actionReset_values_by_default"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(8);
        progressBar->setInvertedAppearance(false);

        gridLayout->addWidget(progressBar, 3, 1, 1, 1);

        log = new QTextEdit(centralWidget);
        log->setObjectName(QStringLiteral("log"));

        gridLayout->addWidget(log, 4, 1, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        checkBoxCook = new QCheckBox(groupBox_2);
        checkBoxCook->setObjectName(QStringLiteral("checkBoxCook"));

        gridLayout_3->addWidget(checkBoxCook, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 2, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton);


        gridLayout->addWidget(frame, 3, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sbGold = new QSpinBox(groupBox);
        sbGold->setObjectName(QStringLiteral("sbGold"));

        gridLayout_2->addWidget(sbGold, 3, 1, 1, 1);

        sbFatigue = new QSpinBox(groupBox);
        sbFatigue->setObjectName(QStringLiteral("sbFatigue"));

        gridLayout_2->addWidget(sbFatigue, 2, 1, 1, 1);

        sbBank = new QSpinBox(groupBox);
        sbBank->setObjectName(QStringLiteral("sbBank"));

        gridLayout_2->addWidget(sbBank, 4, 1, 1, 1);

        checkBoxFatigue = new QCheckBox(groupBox);
        checkBoxFatigue->setObjectName(QStringLiteral("checkBoxFatigue"));

        gridLayout_2->addWidget(checkBoxFatigue, 2, 3, 1, 1);

        checkBoxThirst = new QCheckBox(groupBox);
        checkBoxThirst->setObjectName(QStringLiteral("checkBoxThirst"));

        gridLayout_2->addWidget(checkBoxThirst, 1, 3, 1, 1);

        sbThirst = new QSpinBox(groupBox);
        sbThirst->setObjectName(QStringLiteral("sbThirst"));

        gridLayout_2->addWidget(sbThirst, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        checkBoxKissed = new QCheckBox(groupBox);
        checkBoxKissed->setObjectName(QStringLiteral("checkBoxKissed"));

        gridLayout_2->addWidget(checkBoxKissed, 5, 1, 1, 1);

        checkBoxGold = new QCheckBox(groupBox);
        checkBoxGold->setObjectName(QStringLiteral("checkBoxGold"));

        gridLayout_2->addWidget(checkBoxGold, 3, 3, 1, 1);

        label_3->raise();
        label_2->raise();
        label->raise();
        label_6->raise();
        label_9->raise();
        checkBoxFatigue->raise();
        checkBoxThirst->raise();
        sbBank->raise();
        sbGold->raise();
        sbFatigue->raise();
        sbThirst->raise();
        checkBoxKissed->raise();
        checkBoxGold->raise();

        gridLayout->addWidget(groupBox, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        sbBeauty = new QSpinBox(groupBox_3);
        sbBeauty->setObjectName(QStringLiteral("sbBeauty"));

        gridLayout_4->addWidget(sbBeauty, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        sbBored = new QSpinBox(groupBox_3);
        sbBored->setObjectName(QStringLiteral("sbBored"));

        gridLayout_4->addWidget(sbBored, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        sbGold_2 = new QSpinBox(groupBox_3);
        sbGold_2->setObjectName(QStringLiteral("sbGold_2"));

        gridLayout_4->addWidget(sbGold_2, 2, 1, 1, 1);

        checkBoxSweat = new QCheckBox(groupBox_3);
        checkBoxSweat->setObjectName(QStringLiteral("checkBoxSweat"));

        gridLayout_4->addWidget(checkBoxSweat, 0, 2, 1, 1);

        checkBoxBoredom = new QCheckBox(groupBox_3);
        checkBoxBoredom->setObjectName(QStringLiteral("checkBoxBoredom"));

        gridLayout_4->addWidget(checkBoxBoredom, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 2, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Bank = new QLabel(frame_2);
        Bank->setObjectName(QStringLiteral("Bank"));
        Bank->setGeometry(QRect(20, 10, 81, 61));
        Bank->setPixmap(QPixmap(QString::fromUtf8("images/bank-512.png")));
        Bank->setScaledContents(true);
        Mine = new QLabel(frame_2);
        Mine->setObjectName(QStringLiteral("Mine"));
        Mine->setGeometry(QRect(210, 10, 71, 61));
        Mine->setPixmap(QPixmap(QString::fromUtf8("images/gold_mine-128.png")));
        Mine->setScaledContents(true);
        Home = new QLabel(frame_2);
        Home->setObjectName(QStringLiteral("Home"));
        Home->setGeometry(QRect(20, 170, 81, 71));
        Home->setPixmap(QPixmap(QString::fromUtf8("images/home.png")));
        Home->setScaledContents(true);
        Bar = new QLabel(frame_2);
        Bar->setObjectName(QStringLiteral("Bar"));
        Bar->setGeometry(QRect(210, 180, 81, 71));
        Bar->setPixmap(QPixmap(QString::fromUtf8("images/Cocktail-512.png")));
        Bar->setScaledContents(true);
        Piano = new QLabel(frame_2);
        Piano->setObjectName(QStringLiteral("Piano"));
        Piano->setGeometry(QRect(290, 220, 51, 51));
        Piano->setPixmap(QPixmap(QString::fromUtf8("images/Music-Piano-icon.png")));
        Piano->setScaledContents(true);
        Toilets = new QLabel(frame_2);
        Toilets->setObjectName(QStringLiteral("Toilets"));
        Toilets->setGeometry(QRect(350, 220, 41, 51));
        Toilets->setPixmap(QPixmap(QString::fromUtf8("images/Toilets_unisex.svg.png")));
        Toilets->setScaledContents(true);
        Bob = new QLabel(frame_2);
        Bob->setObjectName(QStringLiteral("Bob"));
        Bob->setGeometry(QRect(20, 220, 41, 41));
        Bob->setPixmap(QPixmap(QString::fromUtf8("images/Transparent_Minion_Bob_PNG_Picture.png")));
        Bob->setScaledContents(true);
        Elsa = new QLabel(frame_2);
        Elsa->setObjectName(QStringLiteral("Elsa"));
        Elsa->setGeometry(QRect(70, 210, 61, 51));
        Elsa->setPixmap(QPixmap(QString::fromUtf8("images/elsa-frozen-disney-03.png")));
        Elsa->setScaledContents(true);
        Elsa->setWordWrap(false);
        Jessica = new QLabel(frame_2);
        Jessica->setObjectName(QStringLiteral("Jessica"));
        Jessica->setGeometry(QRect(220, 230, 61, 51));
        Jessica->setPixmap(QPixmap(QString::fromUtf8("images/waitress.png")));
        Jessica->setScaledContents(true);

        gridLayout->addWidget(frame_2, 0, 1, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 21));
        menuResert_values_by_default = new QMenu(menuBar);
        menuResert_values_by_default->setObjectName(QStringLiteral("menuResert_values_by_default"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuResert_values_by_default->menuAction());
        menuResert_values_by_default->addAction(actionReset_values_by_default);
        menuResert_values_by_default->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Miner in the west", 0));
        actionReset_values_by_default->setText(QApplication::translate("MainWindow", "Reset values by default", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        log->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Elsa", 0));
        label_4->setText(QApplication::translate("MainWindow", "Cooking", 0));
        checkBoxCook->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Options", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Launch", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Bob", 0));
        checkBoxFatigue->setText(QString());
        checkBoxThirst->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Lipstick", 0));
        label_2->setText(QApplication::translate("MainWindow", "Fatigue", 0));
        label->setText(QApplication::translate("MainWindow", "Gold", 0));
        label_3->setText(QApplication::translate("MainWindow", "Thirst", 0));
        label_6->setText(QApplication::translate("MainWindow", "Bank", 0));
        checkBoxKissed->setText(QString());
        checkBoxGold->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Jessica", 0));
        label_8->setText(QApplication::translate("MainWindow", "Sweat", 0));
        label_5->setText(QApplication::translate("MainWindow", "Gold", 0));
        label_7->setText(QApplication::translate("MainWindow", "Boredom", 0));
        checkBoxSweat->setText(QString());
        checkBoxBoredom->setText(QString());
        Bank->setText(QString());
        Mine->setText(QString());
        Home->setText(QString());
        Bar->setText(QString());
        Piano->setText(QString());
        Toilets->setText(QString());
        Bob->setText(QString());
        Elsa->setText(QString());
        Jessica->setText(QString());
        menuResert_values_by_default->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
