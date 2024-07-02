/**
 * @file resultado.cpp
 * @title Resultado - Implementación
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase Resultado, que maneja la presentación de los resultados del ciclo menstrual y del quiz.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "resultado.h"
#include "ui_resultado.h"
#include <QTextCharFormat>
#include <QDebug>
#include <QTimer>

/**
 * @brief Constructor de la clase Resultado
 * @param parent Puntero al widget padre
 */
Resultado::Resultado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resultado),
    duracionCiclo(28),
    duracionPeriodo(5)
{
    ui->setupUi(this);
    calendarWidget = ui->calendarWidget;
    contadorLabel = ui->contadorLabel;

    if (calendarWidget == nullptr || contadorLabel == nullptr) {
        qDebug() << "Error: calendarWidget or contadorLabel not found";
    } else {
        qDebug() << "calendarWidget and contadorLabel initialized successfully";
    }

    // Asegurarse de que la ventana tenga botones de maximizar, minimizar y cerrar
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    // Desactivar la visualización de la columna de semanas
    calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QString calendarStyleSheet =
        "QCalendarWidget { background-color: #FAF3F3; border: 1px solid #BDC3C7; }"
        "QCalendarWidget QAbstractItemView:enabled { color: #2C3E50; background: #FAF3F3; selection-background-color: #E74C3C; selection-color: white; }"
        "QCalendarWidget QAbstractItemView:disabled { color: #BDC3C7; }"
        "QCalendarWidget QWidget#qt_calendar_navigationbar { background-color: #E74C3C; }"
        "QCalendarWidget QToolButton { color: white; background-color: #E74C3C; border: none; padding: 5px; }"
        "QCalendarWidget QToolButton:hover { background-color: #C0392B; }"
        "QCalendarWidget QToolButton::menu-indicator { image: none; }"
        "QCalendarWidget QSpinBox { color: white; background: #E74C3C; border: none; }"
        "QCalendarWidget QSpinBox::up-button, QCalendarWidget QSpinBox::down-button { background: none; border: none; }"
        "QCalendarWidget QSpinBox::up-arrow, QCalendarWidget QSpinBox::down-arrow { image: none; }"
        "QCalendarWidget QTableView QHeaderView::section { background-color: #FAF3F3; color: #2C3E50; }" // Cambia el color del encabezado de fila y columna
        "QCalendarWidget QTableView { gridline-color: #BDC3C7; }"; // Cambia el color de las líneas de la cuadrícula

    calendarWidget->setStyleSheet(calendarStyleSheet);
}

/**
 * @brief Destructor de la clase Resultado
 */
Resultado::~Resultado()
{
    qDebug() << "Destructor de Resultado llamado.";
    delete ui;
}

/**
 * @brief Establece los resultados del ciclo menstrual
 * @param fechaInicio Fecha de inicio del último período
 * @param duracionCiclo Duración del ciclo menstrual
 * @param duracionPeriodo Duración del período menstrual
 */
void Resultado::setResultados(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo) {
    this->fechaInicioUltimoPeriodo = fechaInicio;
    this->duracionCiclo = duracionCiclo;
    this->duracionPeriodo = duracionPeriodo;
    actualizarCalendario();
    actualizarContador(fechaInicio, duracionCiclo);
}

/**
 * @brief Establece las respuestas del usuario en el quiz
 * @param respuestas Vector de respuestas del usuario
 */
void Resultado::setRespuestas(const QVector<int> &respuestas) {
    // Aquí puedes manejar las respuestas del usuario
    // Por ejemplo, podrías mostrar un resumen de las respuestas en un QLabel
    QString respuestasTexto;
    for (int i = 0; i < respuestas.size(); ++i) {
        respuestasTexto += QString("Pregunta %1: %2\n").arg(i + 1).arg(respuestas[i]);
    }

    // Lógica adicional para actualizar el calendario basada en las respuestas
    actualizarCalendario();
}

/**
 * @brief Actualiza el calendario con los datos del ciclo menstrual
 * @param fechaInicio Fecha de inicio del último período
 * @param duracionCiclo Duración del ciclo menstrual
 * @param duracionPeriodo Duración del período menstrual
 */
void Resultado::actualizarCalendario(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo) {
    qDebug() << "actualizarCalendario called";
    QDate fechaActual = QDate::currentDate();
    QDate fechaMenstruacion = fechaInicio.addDays(duracionCiclo);

    QTextCharFormat formato;
    formato.setBackground(QColorConstants::Svg::pink);

    while (fechaMenstruacion <= fechaActual.addMonths(3)) {
        for (int i = 0; i < duracionPeriodo; ++i) {
            calendarWidget->setDateTextFormat(fechaMenstruacion.addDays(i), formato);
        }
        fechaMenstruacion = fechaMenstruacion.addDays(duracionCiclo);
    }
}

/**
 * @brief Actualiza el calendario con los datos del ciclo menstrual
 */
void Resultado::actualizarCalendario() {
    actualizarCalendario(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
}

/**
 * @brief Actualiza el contador de días del ciclo menstrual
 * @param fechaInicio Fecha de inicio del último período
 * @param duracionCiclo Duración del ciclo menstrual
 */
void Resultado::actualizarContador(const QDate &fechaInicio, int duracionCiclo) {
    qDebug() << "actualizarContador called";
    QDate fechaActual = QDate::currentDate();
    QDate proximaMenstruacion = fechaInicio.addDays(duracionCiclo);

    while (proximaMenstruacion < fechaActual) {
        proximaMenstruacion = proximaMenstruacion.addDays(duracionCiclo);
    }

    int diasParaMenstruacion = fechaActual.daysTo(proximaMenstruacion);
    contadorLabel->setText(QString("Días para tu próxima menstruación: %1").arg(diasParaMenstruacion));
}

/**
 * @brief Establece los días fértiles del ciclo menstrual
 * @param inicio Fecha de inicio de los días fértiles
 * @param fin Fecha de fin de los días fértiles
 */
void Resultado::setDiasFertiles(const QDate &inicio, const QDate &fin) {
    qDebug() << "setDiasFertiles called";

    QTextCharFormat formatoFertiles;
    formatoFertiles.setBackground(QColorConstants::Svg::lightgreen);

    // Iterar sobre varios meses para marcar los días fértiles
    QDate fecha = inicio;
    QDate fechaFin = QDate::currentDate().addMonths(3);  // Marcar hasta 3 meses en el futuro

    while (fecha <= fin) {
        calendarWidget->setDateTextFormat(fecha, formatoFertiles);
        fecha = fecha.addDays(1);
    }

    // Marcar los días fértiles para los próximos meses
    QDate siguienteInicio = inicio.addDays(duracionCiclo);
    QDate siguienteFin = fin.addDays(duracionCiclo);

    while (siguienteInicio <= fechaFin) {
        fecha = siguienteInicio;
        while (fecha <= siguienteFin) {
            calendarWidget->setDateTextFormat(fecha, formatoFertiles);
            fecha = fecha.addDays(1);
        }
        siguienteInicio = siguienteInicio.addDays(duracionCiclo);
        siguienteFin = siguienteFin.addDays(duracionCiclo);
    }

    QString textoFertiles = QString("Tus días fértiles este mes son del %1 al %2.")
                                .arg(inicio.toString("dd-MM-yyyy"))
                                .arg(fin.toString("dd-MM-yyyy"));
    ui->diasFertiles->setText(textoFertiles);
}

/**
 * @brief Slot llamado al hacer clic en el botón "Volver"
 */
void Resultado::on_botonVolver_2_clicked()
{
    close();
}

