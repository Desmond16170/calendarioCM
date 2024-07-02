/**
 * @file resultado.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Resultado - Presentación de resultados del ciclo menstrual y del quiz
 * @brief Esta clase se encarga de mostrar los resultados del ciclo menstrual y del quiz dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef RESULTADO_H
#define RESULTADO_H

#include "qcalendarwidget.h"
#include "qlabel.h"
#include <QWidget>
#include <QVector>
#include <QString>
#include <QDate>

namespace Ui {
class Resultado;
}

/**
 * @brief La clase Resultado maneja la presentación de resultados del ciclo menstrual y del quiz.
 */
class Resultado : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase Resultado
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit Resultado(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Resultado
     */
    ~Resultado();

    /**
     * @brief Establece los resultados del ciclo menstrual.
     * @param fechaInicio Fecha de inicio del último período
     * @param duracionCiclo Duración del ciclo menstrual
     * @param duracionPeriodo Duración del período menstrual
     */
    void setResultados(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo);

    /**
     * @brief Establece las respuestas del usuario en el quiz.
     * @param respuestas Vector de respuestas del usuario
     */
    void setRespuestas(const QVector<int> &respuestas);

    /**
     * @brief Establece los días fértiles del ciclo menstrual.
     * @param inicio Fecha de inicio de los días fértiles
     * @param fin Fecha de fin de los días fértiles
     */
    void setDiasFertiles(const QDate &inicio, const QDate &fin);

private slots:
    /**
     * @brief Acción al hacer clic en el botón "Volver".
     */
    void on_botonVolver_2_clicked();

private:
    Ui::Resultado *ui; ///< Objeto de la interfaz de usuario generada por Qt
    QCalendarWidget *calendarWidget; ///< Widget del calendario para mostrar el ciclo menstrual
    QLabel *contadorLabel; ///< Label para mostrar el contador de días
    QDate fechaInicioUltimoPeriodo; ///< Fecha de inicio del último período menstrual
    int duracionCiclo; ///< Duración del ciclo menstrual
    int duracionPeriodo; ///< Duración del período menstrual

    /**
     * @brief Actualiza el calendario con los datos del ciclo menstrual.
     * @param fechaInicio Fecha de inicio del último período
     * @param duracionCiclo Duración del ciclo menstrual
     * @param duracionPeriodo Duración del período menstrual
     */
    void actualizarCalendario(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo);

    /**
     * @brief Actualiza el calendario con los datos del ciclo menstrual.
     */
    void actualizarCalendario();

    /**
     * @brief Actualiza el contador de días del ciclo menstrual.
     * @param fechaInicio Fecha de inicio del último período
     * @param duracionCiclo Duración del ciclo menstrual
     */
    void actualizarContador(const QDate &fechaInicio, int duracionCiclo);
};

#endif // RESULTADO_H

