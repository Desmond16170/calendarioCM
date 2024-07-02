#include "resultado.h"
#include "ui_resultado.h"
#include <QTextCharFormat>
#include <QDebug>
#include <QTimer>

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

Resultado::~Resultado()
{
    delete ui;
}

void Resultado::setResultados(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo) {
    this->fechaInicioUltimoPeriodo = fechaInicio;
    this->duracionCiclo = duracionCiclo;
    this->duracionPeriodo = duracionPeriodo;
    actualizarCalendario();
    actualizarContador(fechaInicio, duracionCiclo);
}

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

void Resultado::actualizarCalendario() {
    actualizarCalendario(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
}

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

void Resultado::setDiasFertiles(const QDate &inicio, const QDate &fin) {
    qDebug() << "setDiasFertiles called";

    QTextCharFormat formatoFertiles;
    formatoFertiles.setBackground(QColorConstants::Svg::lightgreen);

    QDate fecha = inicio;
    while (fecha <= fin) {
        calendarWidget->setDateTextFormat(fecha, formatoFertiles);
        fecha = fecha.addDays(1);
    }

    QString textoFertiles = QString("Tus días fértiles son del %1 al %2.")
                                .arg(inicio.toString("dd-MM-yyyy"))
                                .arg(fin.toString("dd-MM-yyyy"));
    ui->diasFertiles->setText(textoFertiles);
}

void Resultado::on_botonVolver_2_clicked()
{
    close();
}
