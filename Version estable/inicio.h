#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <QVector>
#include "usuario.h"

namespace Ui {
class inicio;
}

class inicio : public QWidget
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

signals:
    void loginSuccessful(Usuario *usuario);

private slots:
    void on_loginButton_clicked();
    void on_signUpButton_clicked();
    void on_checkBox_stateChanged(int state);  // Función para manejar el checkbox en la pestaña de inicio de sesión
    void on_checkBox_2_stateChanged(int state);  // Función para manejar el checkbox en la pestaña de registro

private:
    Ui::inicio *ui;
    QVector<Usuario> usuarios;  // Lista de usuarios registrados

    void performLogin();
    void performSignUp();
    void loadUsersFromFile();
    void saveUserToFile(const Usuario &usuario);
};

#endif // INICIO_H
