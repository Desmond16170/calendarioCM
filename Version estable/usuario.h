#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <QVector>
#include <QDate>

class Usuario {
public:
    Usuario(const QString &nombreUsuario, const QString &contrasena);

    QString getNombreUsuario() const;
    QString getContrasena() const;
    bool validarContrasena(const QString &contrasena) const;

    void agregarRespuesta(const QString &respuesta);
    QVector<QString> obtenerRespuestas() const;

    // Métodos adicionales para el ciclo menstrual
    void setDuracionCiclo(int duracion);
    void setDuracionPeriodo(int duracion);
    void setFechaInicioUltimoPeriodo(const QDate &fecha);

    int getDuracionCiclo() const;
    int getDuracionPeriodo() const;
    QDate getFechaInicioUltimoPeriodo() const;

private:
    QString nombreUsuario;
    QString contrasena;
    QVector<QString> respuestas;

    // Variables adicionales para el ciclo menstrual
    int duracionCiclo;
    int duracionPeriodo;
    QDate fechaInicioUltimoPeriodo;
};

#endif // USUARIO_H
