/**
 * @file usuario.cpp
 * @title Usuario - Implementación
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase Usuario, que maneja la información y la autenticación de los usuarios dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "usuario.h"
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

/**
 * @brief Constructor de la clase Usuario
 * @param nombreUsuario Nombre del usuario
 * @param contrasena Contraseña del usuario
 */
Usuario::Usuario(const QString &nombreUsuario, const QString &contrasena)
    : nombreUsuario(nombreUsuario), contrasena(contrasena), duracionCiclo(28), duracionPeriodo(5) {}

/**
 * @brief Obtiene el nombre del usuario
 * @return Nombre del usuario
 */
QString Usuario::getNombreUsuario() const {
    return nombreUsuario;
}

/**
 * @brief Obtiene la contraseña del usuario
 * @return Contraseña del usuario
 */
QString Usuario::getContrasena() const {
    return contrasena;
}

/**
 * @brief Valida la contraseña del usuario
 * @param contrasena Contraseña a validar
 * @return true si la contraseña es válida, false en caso contrario
 */
bool Usuario::validarContrasena(const QString &contrasena) const {
    return this->contrasena == encriptarContrasena(contrasena);
}

/**
 * @brief Agrega una respuesta a la lista de respuestas del usuario
 * @param respuesta Respuesta a agregar
 */
void Usuario::agregarRespuesta(const QString &respuesta) {
    respuestas.append(respuesta);
}

/**
 * @brief Obtiene las respuestas del usuario
 * @return Vector de respuestas del usuario
 */
QVector<QString> Usuario::obtenerRespuestas() const {
    return respuestas;
}

/**
 * @brief Establece la duración del ciclo menstrual del usuario
 * @param duracion Duración del ciclo en días
 */
void Usuario::setDuracionCiclo(int duracion) {
    duracionCiclo = duracion;
}

/**
 * @brief Establece la duración del período menstrual del usuario
 * @param duracion Duración del período en días
 */
void Usuario::setDuracionPeriodo(int duracion) {
    duracionPeriodo = duracion;
}

/**
 * @brief Establece la fecha de inicio del último período menstrual del usuario
 * @param fecha Fecha de inicio del último período
 */
void Usuario::setFechaInicioUltimoPeriodo(const QDate &fecha) {
    fechaInicioUltimoPeriodo = fecha;
}

/**
 * @brief Obtiene la duración del ciclo menstrual del usuario
 * @return Duración del ciclo en días
 */
int Usuario::getDuracionCiclo() const {
    return duracionCiclo;
}

/**
 * @brief Obtiene la duración del período menstrual del usuario
 * @return Duración del período en días
 */
int Usuario::getDuracionPeriodo() const {
    return duracionPeriodo;
}

/**
 * @brief Obtiene la fecha de inicio del último período menstrual del usuario
 * @return Fecha de inicio del último período
 */
QDate Usuario::getFechaInicioUltimoPeriodo() const {
    return fechaInicioUltimoPeriodo;
}

/**
 * @brief Verifica si el usuario tiene respuestas guardadas
 * @return true si el usuario tiene respuestas guardadas, false en caso contrario
 */
bool Usuario::tieneRespuestasGuardadas() const {
    QFile file(nombreUsuario + "_respuestas.log");
    return file.exists() && file.size() > 0;
}

/**
 * @brief Carga las respuestas guardadas del usuario
 * @return Vector de respuestas guardadas
 */
QVector<QString> Usuario::cargarRespuestasGuardadas() const {
    QVector<QString> respuestas;
    QFile file(nombreUsuario + "_respuestas.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return respuestas;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        respuestas.append(in.readLine());
    }

    file.close();
    return respuestas;
}

/**
 * @brief Encripta la contraseña del usuario
 * @param contrasena Contraseña a encriptar
 * @return Contraseña encriptada
 */
QString Usuario::encriptarContrasena(const QString &contrasena) {
    QByteArray hash = QCryptographicHash::hash(contrasena.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

