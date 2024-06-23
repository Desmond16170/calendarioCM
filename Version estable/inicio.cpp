#include "inicio.h"
#include "ui_inicio.h"
#include "usuario.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>

inicio::inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    // Asumiendo que tu QTabWidget se llama tabWidget
    ui->tabWidget->setTabText(0, "Login");
    ui->tabWidget->setTabText(1, "Sign Up");

    // Cargar usuarios desde el archivo
    loadUsersFromFile();

    // Conectar los botones con sus respectivas funciones
    connect(ui->loginButton, &QPushButton::clicked, this, &inicio::on_loginButton_clicked);
    connect(ui->signUpButton, &QPushButton::clicked, this, &inicio::on_signUpButton_clicked);
    connect(ui->checkBoxs, &QCheckBox::stateChanged, this, &inicio::on_checkBox_stateChanged);
    connect(ui->checkBox_2, &QCheckBox::stateChanged, this, &inicio::on_checkBox_2_stateChanged);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_loginButton_clicked()
{
    performLogin();
}

void inicio::on_signUpButton_clicked()
{
    performSignUp();
}

void inicio::on_checkBox_stateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->loginPasswordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->loginPasswordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

void inicio::on_checkBox_2_stateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->signUpPasswordLineEdit->setEchoMode(QLineEdit::Normal);
        ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->signUpPasswordLineEdit->setEchoMode(QLineEdit::Password);
        ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

void inicio::performLogin()
{
    QString username = ui->loginUsernameLineEdit->text();
    QString password = ui->loginPasswordLineEdit->text();

    // Verificar si el usuario está registrado
    for (const Usuario &usuario : usuarios) {
        if (usuario.getNombreUsuario() == username && usuario.validarContrasena(password)) {
            QMessageBox::information(this, "Login", "Inicio de sesión exitoso");
            emit loginSuccessful(new Usuario(usuario));  // Emitir la señal con el usuario logueado
            return;
        }
    }

    // Si no se encuentra el usuario
    QMessageBox::warning(this, "Login", "Nombre de usuario o contraseña incorrectos");
}

void inicio::performSignUp()
{
    QString username = ui->signUpUsernameLineEdit->text();
    QString password = ui->signUpPasswordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Sign Up", "Las contraseñas no coinciden");
        return;
    }

    // Verificar si el usuario ya está registrado
    for (const Usuario &usuario : usuarios) {
        if (usuario.getNombreUsuario() == username) {
            QMessageBox::warning(this, "Sign Up", "El nombre de usuario ya está en uso");
            return;
        }
    }

    // Registrar el nuevo usuario
    Usuario nuevoUsuario(username, password);
    usuarios.append(nuevoUsuario);
    saveUserToFile(nuevoUsuario);
    qDebug() << "Usuario registrado:" << username << password;
    QMessageBox::information(this, "Sign Up", "Registro exitoso");
}

void inicio::loadUsersFromFile()
{
    QFile file("usuarios.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 2) {
            Usuario usuario(fields[0], fields[1]);
            usuarios.append(usuario);
        }
    }
    file.close();
}

void inicio::saveUserToFile(const Usuario &usuario)
{
    QFile file("usuarios.log");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << usuario.getNombreUsuario() << "," << usuario.getContrasena() << "\n";
    file.close();
}
