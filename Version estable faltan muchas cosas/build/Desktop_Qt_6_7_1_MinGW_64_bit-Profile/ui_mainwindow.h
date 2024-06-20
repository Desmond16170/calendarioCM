/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *button_descifrar_flujo_2;
    QPushButton *button_controlar_peso_2;
    QPushButton *button_nada_2;
    QPushButton *button_seguir_periodo_2;
    QPushButton *button_mejorar_vida_sexual_2;
    QPushButton *button_entender_cuerpo_2;
    QPushButton *button_seguir_embarazo_2;
    QPushButton *button_quedarme_embarazada_2;
    QLabel *label_2;
    QPushButton *pushButton_9;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(466, 760);
        MainWindow->setMinimumSize(QSize(466, 760));
        MainWindow->setMaximumSize(QSize(466, 760));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 210, 401, 511));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        button_descifrar_flujo_2 = new QPushButton(gridLayoutWidget);
        button_descifrar_flujo_2->setObjectName("button_descifrar_flujo_2");
        button_descifrar_flujo_2->setMinimumSize(QSize(160, 90));
        button_descifrar_flujo_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_descifrar_flujo_2, 0, 1, 1, 1);

        button_controlar_peso_2 = new QPushButton(gridLayoutWidget);
        button_controlar_peso_2->setObjectName("button_controlar_peso_2");
        button_controlar_peso_2->setMinimumSize(QSize(160, 90));
        button_controlar_peso_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_controlar_peso_2, 2, 1, 1, 1);

        button_nada_2 = new QPushButton(gridLayoutWidget);
        button_nada_2->setObjectName("button_nada_2");
        button_nada_2->setMinimumSize(QSize(160, 90));
        button_nada_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_nada_2, 3, 1, 1, 1);

        button_seguir_periodo_2 = new QPushButton(gridLayoutWidget);
        button_seguir_periodo_2->setObjectName("button_seguir_periodo_2");
        button_seguir_periodo_2->setMinimumSize(QSize(160, 90));
        button_seguir_periodo_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_seguir_periodo_2, 2, 0, 1, 1);

        button_mejorar_vida_sexual_2 = new QPushButton(gridLayoutWidget);
        button_mejorar_vida_sexual_2->setObjectName("button_mejorar_vida_sexual_2");
        button_mejorar_vida_sexual_2->setMinimumSize(QSize(160, 90));
        button_mejorar_vida_sexual_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_mejorar_vida_sexual_2, 1, 1, 1, 1);

        button_entender_cuerpo_2 = new QPushButton(gridLayoutWidget);
        button_entender_cuerpo_2->setObjectName("button_entender_cuerpo_2");
        button_entender_cuerpo_2->setMinimumSize(QSize(160, 90));
        button_entender_cuerpo_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_entender_cuerpo_2, 3, 0, 1, 1);

        button_seguir_embarazo_2 = new QPushButton(gridLayoutWidget);
        button_seguir_embarazo_2->setObjectName("button_seguir_embarazo_2");
        button_seguir_embarazo_2->setMinimumSize(QSize(160, 90));
        button_seguir_embarazo_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_seguir_embarazo_2, 1, 0, 1, 1);

        button_quedarme_embarazada_2 = new QPushButton(gridLayoutWidget);
        button_quedarme_embarazada_2->setObjectName("button_quedarme_embarazada_2");
        button_quedarme_embarazada_2->setMinimumSize(QSize(160, 90));
        button_quedarme_embarazada_2->setMaximumSize(QSize(160, 90));

        gridLayout_2->addWidget(button_quedarme_embarazada_2, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 150, 121, 41));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(330, 10, 91, 31));
        pushButton_9->setMinimumSize(QSize(0, 0));
        pushButton_9->setMaximumSize(QSize(160, 90));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 80, 141, 41));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button_descifrar_flujo_2->setText(QCoreApplication::translate("MainWindow", "Seguir mi embarazo", nullptr));
        button_controlar_peso_2->setText(QCoreApplication::translate("MainWindow", "Mejorar mi vida Sexual ", nullptr));
        button_nada_2->setText(QCoreApplication::translate("MainWindow", "Nada de lo anterior ", nullptr));
        button_seguir_periodo_2->setText(QCoreApplication::translate("MainWindow", "Descifrar mi flujo ", nullptr));
        button_mejorar_vida_sexual_2->setText(QCoreApplication::translate("MainWindow", "Entender mi cuerpo ", nullptr));
        button_entender_cuerpo_2->setText(QCoreApplication::translate("MainWindow", "Controlar mi peso", nullptr));
        button_seguir_embarazo_2->setText(QCoreApplication::translate("MainWindow", "Seguir mI periodo", nullptr));
        button_quedarme_embarazada_2->setText(QCoreApplication::translate("MainWindow", "Quedarme Embarazada", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Selecciona una opcion ", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "En que podemos ayudarte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
