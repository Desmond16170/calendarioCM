#include "usuario.h"

Usuario::Usuario(const QString &nombreUsuario, const QString &contrasena)
    : nombreUsuario(nombreUsuario), contrasena(contrasena), duracionCiclo(28), duracionPeriodo(5) {}

QString Usuario::getNombreUsuario() const {
    return nombreUsuario;
}

QString Usuario::getContrasena() const {
    return contrasena;
}


bool Usuario::validarContrasena(const QString &contrasena) const {
    return this->contrasena == contrasena;
}

void Usuario::agregarRespuesta(const QString &respuesta) {
    respuestas.append(respuesta);
}

QVector<QString> Usuario::obtenerRespuestas() const {
    return respuestas;
}

void Usuario::setDuracionCiclo(int duracion) {
    duracionCiclo = duracion;
}

void Usuario::setDuracionPeriodo(int duracion) {
    duracionPeriodo = duracion;
}

void Usuario::setFechaInicioUltimoPeriodo(const QDate &fecha) {
    fechaInicioUltimoPeriodo = fecha;
}

int Usuario::getDuracionCiclo() const {
    return duracionCiclo;
}

int Usuario::getDuracionPeriodo() const {
    return duracionPeriodo;
}

QDate Usuario::getFechaInicioUltimoPeriodo() const {
    return fechaInicioUltimoPeriodo;
}
