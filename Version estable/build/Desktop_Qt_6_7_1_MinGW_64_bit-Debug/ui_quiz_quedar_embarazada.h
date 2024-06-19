/********************************************************************************
** Form generated from reading UI file 'quiz_quedar_embarazada.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ_QUEDAR_EMBARAZADA_H
#define UI_QUIZ_QUEDAR_EMBARAZADA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Quiz_quedar_embarazada
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QRadioButton *option1RadioButton;
    QRadioButton *option2RadioButton;
    QRadioButton *option3RadioButton;
    QRadioButton *option4RadioButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotonAnterior_2;
    QPushButton *BotonSiguiente_2;
    QPushButton *botonVolver_2;

    void setupUi(QWidget *Quiz_quedar_embarazada)
    {
        if (Quiz_quedar_embarazada->objectName().isEmpty())
            Quiz_quedar_embarazada->setObjectName("Quiz_quedar_embarazada");
        Quiz_quedar_embarazada->resize(466, 760);
        Quiz_quedar_embarazada->setMinimumSize(QSize(466, 760));
        Quiz_quedar_embarazada->setMaximumSize(QSize(466, 760));
        verticalLayoutWidget = new QWidget(Quiz_quedar_embarazada);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 30, 421, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        questionLabel = new QLabel(verticalLayoutWidget);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setMaximumSize(QSize(500, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(12);
        font.setBold(false);
        questionLabel->setFont(font);
        questionLabel->setTabletTracking(false);
        questionLabel->setContextMenuPolicy(Qt::PreventContextMenu);
        questionLabel->setLayoutDirection(Qt::LeftToRight);
        questionLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(16, 131, 214);"));
        questionLabel->setScaledContents(true);
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setWordWrap(true);

        verticalLayout->addWidget(questionLabel);

        option1RadioButton = new QRadioButton(verticalLayoutWidget);
        option1RadioButton->setObjectName("option1RadioButton");
        option1RadioButton->setMinimumSize(QSize(20, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font1.setPointSize(8);
        option1RadioButton->setFont(font1);
        option1RadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(200, 205, 192);\n"
""));

        verticalLayout->addWidget(option1RadioButton);

        option2RadioButton = new QRadioButton(verticalLayoutWidget);
        option2RadioButton->setObjectName("option2RadioButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(option2RadioButton->sizePolicy().hasHeightForWidth());
        option2RadioButton->setSizePolicy(sizePolicy);
        option2RadioButton->setMinimumSize(QSize(20, 40));
        option2RadioButton->setFont(font1);
        option2RadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(200, 205, 192);\n"
""));
#if QT_CONFIG(shortcut)
        option2RadioButton->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        verticalLayout->addWidget(option2RadioButton);

        option3RadioButton = new QRadioButton(verticalLayoutWidget);
        option3RadioButton->setObjectName("option3RadioButton");
        option3RadioButton->setMinimumSize(QSize(20, 40));
        option3RadioButton->setFont(font1);
        option3RadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(200, 205, 192);\n"
""));

        verticalLayout->addWidget(option3RadioButton);

        option4RadioButton = new QRadioButton(verticalLayoutWidget);
        option4RadioButton->setObjectName("option4RadioButton");
        option4RadioButton->setMinimumSize(QSize(20, 40));
        option4RadioButton->setFont(font1);
        option4RadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 46, 54);\n"
"background-color: rgb(36, 49, 59);\n"
"border-top-color: rgb(42, 59, 71);\n"
"border-right-color: rgb(42, 59, 71);\n"
"border-buttom-color: rgb(42, 59, 71);\n"
"border-left-color: rgb(42, 59, 71);\n"
"color: rgb(200, 205, 192);\n"
""));

        verticalLayout->addWidget(option4RadioButton);

        horizontalLayoutWidget = new QWidget(Quiz_quedar_embarazada);
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


        retranslateUi(Quiz_quedar_embarazada);

        QMetaObject::connectSlotsByName(Quiz_quedar_embarazada);
    } // setupUi

    void retranslateUi(QWidget *Quiz_quedar_embarazada)
    {
        Quiz_quedar_embarazada->setWindowTitle(QCoreApplication::translate("Quiz_quedar_embarazada", "Form", nullptr));
        questionLabel->setText(QString());
        option1RadioButton->setText(QString());
        option2RadioButton->setText(QString());
        option3RadioButton->setText(QString());
        option4RadioButton->setText(QString());
        BotonAnterior_2->setText(QCoreApplication::translate("Quiz_quedar_embarazada", "Anterior", nullptr));
        BotonSiguiente_2->setText(QCoreApplication::translate("Quiz_quedar_embarazada", "Siguiente", nullptr));
        botonVolver_2->setText(QCoreApplication::translate("Quiz_quedar_embarazada", " Volver al menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Quiz_quedar_embarazada: public Ui_Quiz_quedar_embarazada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ_QUEDAR_EMBARAZADA_H
