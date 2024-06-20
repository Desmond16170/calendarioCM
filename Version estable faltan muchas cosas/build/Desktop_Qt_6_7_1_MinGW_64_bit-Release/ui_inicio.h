/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QTabWidget *tabWidget;
    QWidget *SingUpTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *signUpUsernameLineEdit;
    QLineEdit *signUpPasswordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
    QPushButton *signUpButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QCheckBox *checkBoxs;
    QWidget *LoginTab;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *loginUsernameLineEdit;
    QLineEdit *loginPasswordLineEdit;
    QPushButton *loginButton;
    QLabel *label_5;
    QCheckBox *checkBox;

    void setupUi(QWidget *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName("inicio");
        inicio->resize(451, 360);
        tabWidget = new QTabWidget(inicio);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 450, 360));
        tabWidget->setMinimumSize(QSize(450, 360));
        tabWidget->setMaximumSize(QSize(450, 360));
        SingUpTab = new QWidget();
        SingUpTab->setObjectName("SingUpTab");
        verticalLayoutWidget = new QWidget(SingUpTab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 100, 160, 116));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        signUpUsernameLineEdit = new QLineEdit(verticalLayoutWidget);
        signUpUsernameLineEdit->setObjectName("signUpUsernameLineEdit");

        verticalLayout->addWidget(signUpUsernameLineEdit);

        signUpPasswordLineEdit = new QLineEdit(verticalLayoutWidget);
        signUpPasswordLineEdit->setObjectName("signUpPasswordLineEdit");
        signUpPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(signUpPasswordLineEdit);

        confirmPasswordLineEdit = new QLineEdit(verticalLayoutWidget);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(confirmPasswordLineEdit);

        signUpButton = new QPushButton(verticalLayoutWidget);
        signUpButton->setObjectName("signUpButton");

        verticalLayout->addWidget(signUpButton);

        label = new QLabel(SingUpTab);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 100, 49, 16));
        label_3 = new QLabel(SingUpTab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 130, 49, 16));
        label_6 = new QLabel(SingUpTab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 160, 101, 21));
        checkBoxs = new QCheckBox(SingUpTab);
        checkBoxs->setObjectName("checkBoxs");
        checkBoxs->setGeometry(QRect(170, 220, 101, 22));
        tabWidget->addTab(SingUpTab, QString());
        LoginTab = new QWidget();
        LoginTab->setObjectName("LoginTab");
        label_4 = new QLabel(LoginTab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 130, 49, 16));
        verticalLayoutWidget_3 = new QWidget(LoginTab);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(140, 100, 160, 86));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginUsernameLineEdit = new QLineEdit(verticalLayoutWidget_3);
        loginUsernameLineEdit->setObjectName("loginUsernameLineEdit");

        verticalLayout_3->addWidget(loginUsernameLineEdit);

        loginPasswordLineEdit = new QLineEdit(verticalLayoutWidget_3);
        loginPasswordLineEdit->setObjectName("loginPasswordLineEdit");
        loginPasswordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(loginPasswordLineEdit);

        loginButton = new QPushButton(verticalLayoutWidget_3);
        loginButton->setObjectName("loginButton");

        verticalLayout_3->addWidget(loginButton);

        label_5 = new QLabel(LoginTab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 100, 49, 16));
        checkBox = new QCheckBox(LoginTab);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(180, 190, 101, 22));
        tabWidget->addTab(LoginTab, QString());

        retranslateUi(inicio);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QWidget *inicio)
    {
        inicio->setWindowTitle(QCoreApplication::translate("inicio", "Form", nullptr));
        signUpButton->setText(QCoreApplication::translate("inicio", "Login", nullptr));
        label->setText(QCoreApplication::translate("inicio", "User", nullptr));
        label_3->setText(QCoreApplication::translate("inicio", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("inicio", "Confirm Password", nullptr));
        checkBoxs->setText(QCoreApplication::translate("inicio", "Ver contrase\303\261a", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SingUpTab), QCoreApplication::translate("inicio", "Tab 1", nullptr));
        label_4->setText(QCoreApplication::translate("inicio", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("inicio", "Login", nullptr));
        label_5->setText(QCoreApplication::translate("inicio", "User", nullptr));
        checkBox->setText(QCoreApplication::translate("inicio", "Ver contrase\303\261a", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(LoginTab), QCoreApplication::translate("inicio", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
