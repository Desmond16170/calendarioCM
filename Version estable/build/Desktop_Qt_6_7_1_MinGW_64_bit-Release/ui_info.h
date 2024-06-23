/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *texto;
    QLabel *titulo;
    QLabel *url;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotonAnterior;
    QPushButton *BotonSiguiente;
    QPushButton *botonVolver;

    void setupUi(QWidget *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName("info");
        info->resize(466, 760);
        info->setMinimumSize(QSize(466, 760));
        info->setMaximumSize(QSize(466, 760));
        gridLayoutWidget = new QWidget(info);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 130, 421, 441));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        texto = new QLabel(gridLayoutWidget);
        texto->setObjectName("texto");

        gridLayout->addWidget(texto, 1, 0, 1, 1);

        titulo = new QLabel(gridLayoutWidget);
        titulo->setObjectName("titulo");

        gridLayout->addWidget(titulo, 0, 0, 1, 1);

        url = new QLabel(gridLayoutWidget);
        url->setObjectName("url");

        gridLayout->addWidget(url, 2, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(info);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 570, 421, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BotonAnterior = new QPushButton(horizontalLayoutWidget);
        BotonAnterior->setObjectName("BotonAnterior");
        BotonAnterior->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(129, 120, 255);\n"
"background-color: rgb(255, 176, 248);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(7, 99, 157);\n"
"border-radius: 5px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Anterior.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonAnterior->setIcon(icon);

        horizontalLayout->addWidget(BotonAnterior);

        BotonSiguiente = new QPushButton(horizontalLayoutWidget);
        BotonSiguiente->setObjectName("BotonSiguiente");
        BotonSiguiente->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(129, 120, 255);\n"
"background-color: rgb(255, 176, 248);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(7, 99, 157);\n"
"border-radius: 5px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Siguiente.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonSiguiente->setIcon(icon1);

        horizontalLayout->addWidget(BotonSiguiente);

        botonVolver = new QPushButton(horizontalLayoutWidget);
        botonVolver->setObjectName("botonVolver");
        botonVolver->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 1px;\n"
";\n"
"background-color: rgb(0, 120, 100);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        botonVolver->setIcon(icon2);

        horizontalLayout->addWidget(botonVolver);


        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QWidget *info)
    {
        info->setWindowTitle(QCoreApplication::translate("info", "Form", nullptr));
        texto->setText(QString());
        titulo->setText(QString());
        url->setText(QString());
        BotonAnterior->setText(QCoreApplication::translate("info", "Anterior", nullptr));
        BotonSiguiente->setText(QCoreApplication::translate("info", "Siguiente", nullptr));
        botonVolver->setText(QCoreApplication::translate("info", " Volver al menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
