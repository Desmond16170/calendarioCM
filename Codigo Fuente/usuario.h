/**
 * @file usuario.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Usuario - Manejo de información y autenticación de usuarios
 * @brief Esta clase se encarga de manejar la información y la autenticación de los usuarios dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <QVector>
#include <QDate>

/**
 * @brief La clase Usuario maneja la información y la autenticación de un usuario en la aplicación.
 */
class Usuario {
public:
    /**
     * @brief Constructor de la clase Usuario
     * @param nombreUsuario Nombre del usuario
     * @param contrasena Contraseña del usuario
     */
    Usuario(const QString &nombreUsuario, const QString &contrasena);

    /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario
     */
    QString getNombreUsuario() const;

    /**
     * @brief Obtiene la contraseña del usuario.
     * @return Contraseña del usuario
     */
    QString getContrasena() const;

    /**
     * @brief Valida la contraseña del usuario.
     * @param contrasena Contraseña a validar
     * @return true si la contraseña es válida, false en caso contrario
     */
    bool validarContrasena(const QString &contrasena) const;

    /**
     * @brief Verifica si el usuario tiene respuestas guardadas.
     * @return true si el usuario tiene respuestas guardadas, false en caso contrario
     */
    bool tieneRespuestasGuardadas() const;

    /**
     * @brief Agrega una respuesta a la lista de respuestas del usuario.
     * @param respuesta Respuesta a agregar
     */
    void agregarRespuesta(const QString &respuesta);

    /**
     * @brief Obtiene las respuestas del usuario.
     * @return Vector de respuestas del usuario
     */
    QVector<QString> obtenerRespuestas() const;

    /**
     * @brief Establece la duración del ciclo menstrual del usuario.
     * @param duracion Duración del ciclo en días
     */
    void setDuracionCiclo(int duracion);

    /**
     * @brief Establece la duración del período menstrual del usuario.
     * @param duracion Duración del período en días
     */
    void setDuracionPeriodo(int duracion);

    /**
     * @brief Establece la fecha de inicio del último período menstrual del usuario.
     * @param fecha Fecha de inicio del último período
     */
    void setFechaInicioUltimoPeriodo(const QDate &fecha);

    /**
     * @brief Obtiene la duración del ciclo menstrual del usuario.
     * @return Duración del ciclo en días
     */
    int getDuracionCiclo() const;

    /**
     * @brief Obtiene la duración del período menstrual del usuario.
     * @return Duración del período en días
     */
    int getDuracionPeriodo() const;

    /**
     * @brief Obtiene la fecha de inicio del último período menstrual del usuario.
     * @return Fecha de inicio del último período
     */
    QDate getFechaInicioUltimoPeriodo() const;

    /**
     * @brief Carga las respuestas guardadas del usuario.
     * @return Vector de respuestas guardadas
     */
    QVector<QString> cargarRespuestasGuardadas() const;

    /**
     * @brief Encripta la contraseña del usuario.
     * @param contrasena Contraseña a encriptar
     * @return Contraseña encriptada
     */
    static QString encriptarContrasena(const QString &contrasena);

private:
    QString nombreUsuario; ///< Nombre del usuario
    QString contrasena; ///< Contraseña del usuario
    QVector<QString> respuestas; ///< Vector de respuestas del usuario

    int duracionCiclo; ///< Duración del ciclo menstrual del usuario
    int duracionPeriodo; ///< Duración del período menstrual del usuario
    QDate fechaInicioUltimoPeriodo; ///< Fecha de inicio del último período menstrual del usuario
};

#endif // USUARIO_H
