/**
 * @file inicio.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Inicio - Manejo de inicio de sesión y registro de usuarios
 * @brief Esta clase se encarga del manejo del inicio de sesión y registro de usuarios dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include "usuario.h"

namespace Ui {
class inicio;
}

/**
 * @brief La clase inicio maneja el inicio de sesión y el registro de usuarios en la aplicación.
 */
class inicio : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase inicio
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit inicio(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase inicio
     */
    ~inicio();

    /**
     * @brief Obtiene la lista de usuarios registrados.
     * @return Vector de objetos Usuario
     */
    QVector<Usuario> getUsuarios() const;

signals:
    /**
     * @brief Señal emitida cuando el inicio de sesión es exitoso.
     * @param usuario Puntero al objeto Usuario que ha iniciado sesión
     */
    void loginSuccessful(Usuario *usuario);

private slots:
    /**
     * @brief Acción al hacer clic en el botón de inicio de sesión.
     */
    void on_loginButton_clicked();

    /**
     * @brief Acción al hacer clic en el botón de registro.
     */
    void on_signUpButton_clicked();

    /**
     * @brief Acción al cambiar el estado del primer checkbox.
     * @param state Estado del checkbox
     */
    void on_checkBox_stateChanged(int state);

    /**
     * @brief Acción al cambiar el estado del segundo checkbox.
     * @param state Estado del checkbox
     */
    void on_checkBox_2_stateChanged(int state);

private:
    Ui::inicio *ui; ///< Objeto de la interfaz de usuario generada por Qt
    QVector<Usuario> usuarios; ///< Vector de usuarios registrados

    /**
     * @brief Carga los usuarios desde un archivo.
     */
    void loadUsersFromFile();

    /**
     * @brief Guarda un usuario en el archivo.
     * @param usuario Referencia al objeto Usuario a guardar
     */
    void saveUserToFile(const Usuario &usuario);

    /**
     * @brief Realiza la acción de inicio de sesión.
     */
    void performLogin();

    /**
     * @brief Realiza la acción de registro de un nuevo usuario.
     */
    void performSignUp();
};

#endif // INICIO_H
