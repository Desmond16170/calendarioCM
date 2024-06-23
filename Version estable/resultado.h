#ifndef RESULTADO_H
#define RESULTADO_H

#include <QWidget>
#include <QDate>
#include <QCalendarWidget>
#include <QLabel>

// Asegurarse de incluir el archivo generado por el diseñador de interfaces
#include "ui_resultado.h"

namespace Ui {
class Resultado;
}

class Resultado : public QWidget
{
    Q_OBJECT

public:
    explicit Resultado(QWidget *parent = nullptr);
    ~Resultado();
    void setResultados(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo);
    void setRespuestas(const QVector<int> &respuestas); // Nueva función para establecer las respuestas del usuario

private:
    Ui::Resultado *ui;
    QCalendarWidget *calendarWidget;
    QLabel *contadorLabel;

    void actualizarCalendario(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo);
    void actualizarContador(const QDate &fechaInicio, int duracionCiclo);
};

#endif // RESULTADO_H
