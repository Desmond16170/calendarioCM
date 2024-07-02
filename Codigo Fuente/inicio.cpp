/**
 * @file inicio.cpp
 * @title Inicio - Implementación
 *  @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase inicio, que maneja el inicio de sesión y el registro de usuarios dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "inicio.h"
#include "ui_inicio.h"
#include "usuario.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

/**
 * @brief Constructor de la clase inicio
 * @param parent Puntero al widget padre
 */
inicio::inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Login");
    ui->tabWidget->setTabText(1, "Sign Up");

    loadUsersFromFile();

    connect(ui->loginButton, &QPushButton::clicked, this, &inicio::on_loginButton_clicked);
    connect(ui->signUpButton, &QPushButton::clicked, this, &inicio::on_signUpButton_clicked);
    connect(ui->checkBoxs, &QCheckBox::stateChanged, this, &inicio::on_checkBox_stateChanged);
    connect(ui->checkBoxs, &QCheckBox::stateChanged, this, &inicio::on_checkBox_2_stateChanged);
}

/**
 * @brief Destructor de la clase inicio
 */
inicio::~inicio()
{
    delete ui;
}

/**
 * @brief Obtiene la lista de usuarios registrados
 * @return Vector de objetos Usuario
 */
QVector<Usuario> inicio::getUsuarios() const {
    return usuarios;
}

/**
 * @brief Slot llamado al hacer clic en el botón de inicio de sesión
 */
void inicio::on_loginButton_clicked()
{
    performLogin();
}

/**
 * @brief Slot llamado al hacer clic en el botón de registro
 */
void inicio::on_signUpButton_clicked()
{
    performSignUp();
}

/**
 * @brief Slot llamado al cambiar el estado del primer checkbox
 * @param state Estado del checkbox
 */
void inicio::on_checkBox_stateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->loginPasswordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->loginPasswordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

/**
 * @brief Slot llamado al cambiar el estado del segundo checkbox
 * @param state Estado del checkbox
 */
void inicio::on_checkBox_2_stateChanged(int state)
{
    if (state == Qt::Checked) {
        ui->signUpPasswordLineEdit->setEchoMode(QLineEdit::Normal);
        ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->signUpPasswordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

/**
 * @brief Realiza la acción de inicio de sesión
 */
void inicio::performLogin()
{
    QString username = ui->loginUsernameLineEdit->text();
    QString password = ui->loginPasswordLineEdit->text();

    for (const Usuario &usuario : usuarios) {
        if (usuario.getNombreUsuario() == username && usuario.validarContrasena(password)) {
            QMessageBox::information(this, "Login", "Inicio de sesión exitoso");
            emit loginSuccessful(new Usuario(usuario));
            return;
        }
    }

    QMessageBox::warning(this, "Login", "Nombre de usuario o contraseña incorrectos");
}

/**
 * @brief Realiza la acción de registro de un nuevo usuario
 */
void inicio::performSignUp()
{
    QString username = ui->signUpUsernameLineEdit->text();
    QString password = ui->signUpPasswordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Sign Up", "Las contraseñas no coinciden");
        return;
    }

    for (const Usuario &usuario : usuarios) {
        if (usuario.getNombreUsuario() == username) {
            QMessageBox::warning(this, "Sign Up", "El nombre de usuario ya está en uso");
            return;
        }
    }

    Usuario nuevoUsuario(username, Usuario::encriptarContrasena(password));
    usuarios.append(nuevoUsuario);
    saveUserToFile(nuevoUsuario);
    qDebug() << "Usuario registrado:" << username << password;
    QMessageBox::information(this, "Sign Up", "Registro exitoso");
}

/**
 * @brief Carga los usuarios desde un archivo
 */
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

/**
 * @brief Guarda un usuario en el archivo
 * @param usuario Referencia al objeto Usuario a guardar
 */
void inicio::saveUserToFile(const Usuario &usuario)
{
    QFile file("usuarios.log");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << usuario.getNombreUsuario() << "," << usuario.getContrasena() << "\n";
    file.close();
}
