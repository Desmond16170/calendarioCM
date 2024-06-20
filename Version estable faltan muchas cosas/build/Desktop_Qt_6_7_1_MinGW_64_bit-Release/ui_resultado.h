/********************************************************************************
** Form generated from reading UI file 'resultado.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTADO_H
#define UI_RESULTADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resultado
{
public:
    QLabel *contadorLabel;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Resultado)
    {
        if (Resultado->objectName().isEmpty())
            Resultado->setObjectName("Resultado");
        Resultado->resize(466, 760);
        Resultado->setMinimumSize(QSize(466, 760));
        Resultado->setMaximumSize(QSize(466, 760));
        Resultado->setWindowFilePath(QString::fromUtf8(""));
        contadorLabel = new QLabel(Resultado);
        contadorLabel->setObjectName("contadorLabel");
        contadorLabel->setGeometry(QRect(80, 430, 311, 101));
        calendarWidget = new QCalendarWidget(Resultado);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 90, 441, 331));
        calendarWidget->setMaximumSize(QSize(999, 999));

        retranslateUi(Resultado);

        QMetaObject::connectSlotsByName(Resultado);
    } // setupUi

    void retranslateUi(QWidget *Resultado)
    {
        Resultado->setWindowTitle(QCoreApplication::translate("Resultado", "Form", nullptr));
        contadorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Resultado: public Ui_Resultado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTADO_H
