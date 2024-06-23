#include "resultado.h"
#include "ui_resultado.h"
#include <QTextCharFormat>
#include <QDebug>
#include <QTimer>

Resultado::Resultado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resultado)
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

    // Usar un temporizador para asegurar que la ventana se muestra en primer plano
    QTimer::singleShot(100, this, [this]() {
        this->raise();
        this->activateWindow();
    });
}

Resultado::~Resultado()
{
    delete ui;
}

void Resultado::setResultados(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo) {
    qDebug() << "setResultados called";
    actualizarCalendario(fechaInicio, duracionCiclo, duracionPeriodo);
    actualizarContador(fechaInicio, duracionCiclo);
}

void Resultado::actualizarCalendario(const QDate &fechaInicio, int duracionCiclo, int duracionPeriodo) {
    qDebug() << "actualizarCalendario called";
    QDate fechaActual = QDate::currentDate();
    QDate fechaMenstruacion = fechaInicio.addDays(duracionCiclo);

    QTextCharFormat formato;
    formato.setBackground(Qt::red);

    while (fechaMenstruacion <= fechaActual.addMonths(3)) {
        for (int i = 0; i < duracionPeriodo; ++i) {
            calendarWidget->setDateTextFormat(fechaMenstruacion.addDays(i), formato);
        }
        fechaMenstruacion = fechaMenstruacion.addDays(duracionCiclo);
    }
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

void Resultado::setRespuestas(const QVector<int> &respuestas)
{
    // Aquí puedes manejar las respuestas del usuario
    // Por ejemplo, podrías mostrar un resumen de las respuestas en un QLabel
    QString respuestasTexto;
    for (int i = 0; i < respuestas.size(); ++i) {
        respuestasTexto += QString("Pregunta %1: %2\n").arg(i + 1).arg(respuestas[i]);
    }
    ui->respuestasLabel->setText(respuestasTexto);  // Asegúrate de tener un QLabel llamado respuestasLabel en tu UI
}
