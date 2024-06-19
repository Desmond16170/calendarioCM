/********************************************************************************
** Form generated from reading UI file 'dateselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATESELECTIONDIALOG_H
#define UI_DATESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateSelectionDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;
    QComboBox *dayComboBox;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *dateQuestionLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotonAnterior_2;
    QPushButton *BotonSiguiente_2;
    QPushButton *botonVolver_2;

    void setupUi(QWidget *DateSelectionDialog)
    {
        if (DateSelectionDialog->objectName().isEmpty())
            DateSelectionDialog->setObjectName("DateSelectionDialog");
        DateSelectionDialog->resize(466, 760);
        DateSelectionDialog->setMinimumSize(QSize(466, 760));
        DateSelectionDialog->setMaximumSize(QSize(466, 760));
        gridLayoutWidget = new QWidget(DateSelectionDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 320, 421, 111));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        monthComboBox = new QComboBox(gridLayoutWidget);
        monthComboBox->setObjectName("monthComboBox");

        gridLayout_2->addWidget(monthComboBox, 2, 1, 1, 1);

        yearComboBox = new QComboBox(gridLayoutWidget);
        yearComboBox->setObjectName("yearComboBox");

        gridLayout_2->addWidget(yearComboBox, 2, 2, 1, 1);

        dayComboBox = new QComboBox(gridLayoutWidget);
        dayComboBox->setObjectName("dayComboBox");

        gridLayout_2->addWidget(dayComboBox, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        dateQuestionLabel = new QLabel(DateSelectionDialog);
        dateQuestionLabel->setObjectName("dateQuestionLabel");
        dateQuestionLabel->setGeometry(QRect(20, 110, 419, 100));
        dateQuestionLabel->setMaximumSize(QSize(500, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(12);
        font.setBold(false);
        dateQuestionLabel->setFont(font);
        dateQuestionLabel->setTabletTracking(false);
        dateQuestionLabel->setContextMenuPolicy(Qt::PreventContextMenu);
        dateQuestionLabel->setLayoutDirection(Qt::LeftToRight);
        dateQuestionLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(16, 131, 214);"));
        dateQuestionLabel->setScaledContents(true);
        dateQuestionLabel->setAlignment(Qt::AlignCenter);
        dateQuestionLabel->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(DateSelectionDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 590, 421, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BotonAnterior_2 = new QPushButton(horizontalLayoutWidget);
        BotonAnterior_2->setObjectName("BotonAnterior_2");
        BotonAnterior_2->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(129, 120, 255);\n"
"background-color: rgb(255, 176, 248);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(7, 99, 157);\n"
"border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Anterior.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonAnterior_2->setIcon(icon);

        horizontalLayout->addWidget(BotonAnterior_2);

        BotonSiguiente_2 = new QPushButton(horizontalLayoutWidget);
        BotonSiguiente_2->setObjectName("BotonSiguiente_2");
        BotonSiguiente_2->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(129, 120, 255);\n"
"background-color: rgb(255, 176, 248);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(7, 99, 157);\n"
"border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Siguiente.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonSiguiente_2->setIcon(icon1);

        horizontalLayout->addWidget(BotonSiguiente_2);

        botonVolver_2 = new QPushButton(horizontalLayoutWidget);
        botonVolver_2->setObjectName("botonVolver_2");
        botonVolver_2->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(0, 120, 100);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonVolver_2->setIcon(icon2);

        horizontalLayout->addWidget(botonVolver_2);


        retranslateUi(DateSelectionDialog);

        QMetaObject::connectSlotsByName(DateSelectionDialog);
    } // setupUi

    void retranslateUi(QWidget *DateSelectionDialog)
    {
        DateSelectionDialog->setWindowTitle(QCoreApplication::translate("DateSelectionDialog", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("DateSelectionDialog", "YYYY", nullptr));
        label->setText(QCoreApplication::translate("DateSelectionDialog", "DD", nullptr));
        label_2->setText(QCoreApplication::translate("DateSelectionDialog", "MM", nullptr));
        dateQuestionLabel->setText(QCoreApplication::translate("DateSelectionDialog", "\302\277Cu\303\241ndo fue el primer d\303\255a de tu \303\272ltimo per\303\255odo?", nullptr));
        BotonAnterior_2->setText(QCoreApplication::translate("DateSelectionDialog", "Anterior", nullptr));
        BotonSiguiente_2->setText(QCoreApplication::translate("DateSelectionDialog", "Siguiente", nullptr));
        botonVolver_2->setText(QCoreApplication::translate("DateSelectionDialog", " Volver al menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateSelectionDialog: public Ui_DateSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATESELECTIONDIALOG_H
