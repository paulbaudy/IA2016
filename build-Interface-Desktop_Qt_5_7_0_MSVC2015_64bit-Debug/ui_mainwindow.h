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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBoxCook;
    QLabel *label_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QCheckBox *checkBoxThirst;
    QCheckBox *checkBoxFatigue;
    QSpinBox *sbThirst;
    QSpinBox *sbGold;
    QSpinBox *sbBank;
    QSpinBox *sbFatigue;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_7;
    QSpinBox *sbBeauty;
    QSpinBox *sbBored;
    QSpinBox *sbGold_2;
    QProgressBar *progressBar;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 492);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBoxCook = new QCheckBox(groupBox_2);
        checkBoxCook->setObjectName(QStringLiteral("checkBoxCook"));

        gridLayout_3->addWidget(checkBoxCook, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 3, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
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

        checkBoxThirst = new QCheckBox(groupBox);
        checkBoxThirst->setObjectName(QStringLiteral("checkBoxThirst"));

        gridLayout_2->addWidget(checkBoxThirst, 1, 1, 1, 1);

        checkBoxFatigue = new QCheckBox(groupBox);
        checkBoxFatigue->setObjectName(QStringLiteral("checkBoxFatigue"));

        gridLayout_2->addWidget(checkBoxFatigue, 2, 1, 1, 1);

        sbThirst = new QSpinBox(groupBox);
        sbThirst->setObjectName(QStringLiteral("sbThirst"));

        gridLayout_2->addWidget(sbThirst, 1, 2, 1, 1);

        sbGold = new QSpinBox(groupBox);
        sbGold->setObjectName(QStringLiteral("sbGold"));

        gridLayout_2->addWidget(sbGold, 3, 2, 1, 1);

        sbBank = new QSpinBox(groupBox);
        sbBank->setObjectName(QStringLiteral("sbBank"));

        gridLayout_2->addWidget(sbBank, 4, 2, 1, 1);

        sbFatigue = new QSpinBox(groupBox);
        sbFatigue->setObjectName(QStringLiteral("sbFatigue"));

        gridLayout_2->addWidget(sbFatigue, 2, 2, 1, 1);

        label_3->raise();
        label_2->raise();
        label->raise();
        label_6->raise();
        checkBoxThirst->raise();
        checkBoxFatigue->raise();
        sbThirst->raise();
        sbGold->raise();
        sbBank->raise();
        sbFatigue->raise();

        gridLayout->addWidget(groupBox, 0, 3, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        sbBeauty = new QSpinBox(groupBox_3);
        sbBeauty->setObjectName(QStringLiteral("sbBeauty"));

        gridLayout_4->addWidget(sbBeauty, 0, 1, 1, 1);

        sbBored = new QSpinBox(groupBox_3);
        sbBored->setObjectName(QStringLiteral("sbBored"));

        gridLayout_4->addWidget(sbBored, 1, 1, 1, 1);

        sbGold_2 = new QSpinBox(groupBox_3);
        sbGold_2->setObjectName(QStringLiteral("sbGold_2"));

        gridLayout_4->addWidget(sbGold_2, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 3, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(8);
        progressBar->setInvertedAppearance(false);

        gridLayout->addWidget(progressBar, 3, 2, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        graphicsView->setLineWidth(1);

        gridLayout->addWidget(graphicsView, 0, 1, 3, 2);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 4, 1, 2, 3);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addWidget(frame, 3, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Miner in the west", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Elsa", 0));
        checkBoxCook->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Cooking", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Bob", 0));
        label_2->setText(QApplication::translate("MainWindow", "Fatigue", 0));
        label->setText(QApplication::translate("MainWindow", "Gold", 0));
        label_3->setText(QApplication::translate("MainWindow", "Thirst", 0));
        label_6->setText(QApplication::translate("MainWindow", "Bank", 0));
        checkBoxThirst->setText(QString());
        checkBoxFatigue->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Jessica", 0));
        label_5->setText(QApplication::translate("MainWindow", "Gold", 0));
        label_8->setText(QApplication::translate("MainWindow", "Sweat", 0));
        label_7->setText(QApplication::translate("MainWindow", "Boredom", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Miner : Coucou</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Jessica : Salut toi!</p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Options", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Launch", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
