/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *bobPlace;
    QLabel *label_3;
    QComboBox *elsaPlace;
    QLabel *label_2;
    QComboBox *jessPlace;
    QLabel *label_5;
    QSpinBox *sb_iteration;
    QLabel *label;
    QCheckBox *cbStep;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(400, 300);
        gridLayout = new QGridLayout(ConfigDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        frame = new QFrame(ConfigDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        bobPlace = new QComboBox(frame);
        bobPlace->setObjectName(QStringLiteral("bobPlace"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bobPlace);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        elsaPlace = new QComboBox(frame);
        elsaPlace->setObjectName(QStringLiteral("elsaPlace"));

        formLayout->setWidget(1, QFormLayout::FieldRole, elsaPlace);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        jessPlace = new QComboBox(frame);
        jessPlace->setObjectName(QStringLiteral("jessPlace"));

        formLayout->setWidget(2, QFormLayout::FieldRole, jessPlace);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        sb_iteration = new QSpinBox(frame);
        sb_iteration->setObjectName(QStringLiteral("sb_iteration"));
        sb_iteration->setMaximum(50);
        sb_iteration->setValue(30);

        formLayout->setWidget(3, QFormLayout::FieldRole, sb_iteration);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        cbStep = new QCheckBox(frame);
        cbStep->setObjectName(QStringLiteral("cbStep"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cbStep);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Options", 0));
        label_4->setText(QApplication::translate("ConfigDialog", "Bob", 0));
        bobPlace->clear();
        bobPlace->insertItems(0, QStringList()
         << QApplication::translate("ConfigDialog", "Shack", 0)
         << QApplication::translate("ConfigDialog", "Goldmine", 0)
         << QApplication::translate("ConfigDialog", "Saloon", 0)
         << QApplication::translate("ConfigDialog", "Bank", 0)
        );
        label_3->setText(QApplication::translate("ConfigDialog", "Elsa", 0));
        elsaPlace->clear();
        elsaPlace->insertItems(0, QStringList()
         << QApplication::translate("ConfigDialog", "Shack", 0)
         << QApplication::translate("ConfigDialog", "Bathroom", 0)
        );
        label_2->setText(QApplication::translate("ConfigDialog", "Jessica", 0));
        jessPlace->clear();
        jessPlace->insertItems(0, QStringList()
         << QApplication::translate("ConfigDialog", "Saloon", 0)
         << QApplication::translate("ConfigDialog", "Restroom", 0)
         << QApplication::translate("ConfigDialog", "Piano", 0)
        );
        label_5->setText(QApplication::translate("ConfigDialog", "Iteration", 0));
        label->setText(QApplication::translate("ConfigDialog", "Step by step", 0));
        cbStep->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
