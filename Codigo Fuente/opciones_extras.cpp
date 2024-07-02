/**
 * @file opciones_extras.cpp
 * @title Opciones Extras - Implementación
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase opciones_extras, que maneja las funcionalidades adicionales de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "opciones_extras.h"
#include "ui_opciones_extras.h"
#include <QMessageBox>
#include <QDebug>

/**
 * @brief Constructor de la clase opciones_extras
 * @param parent Puntero al widget padre
 * @param usuario Puntero al objeto Usuario que está utilizando las opciones extras
 */
opciones_extras::opciones_extras(QWidget *parent, Usuario *usuario) :
    QWidget(parent),
    ui(new Ui::opciones_extras),
    infoWindow(nullptr),
    gestionCicloWindow(nullptr),
    resultadoWindow(nullptr),
    usuario(usuario)
{
    ui->setupUi(this);

    connect(ui->button_info, &QPushButton::clicked, this, &opciones_extras::on_button_info_clicked);
    connect(ui->button_agregardatos, &QPushButton::clicked, this, &opciones_extras::on_button_agregarDatos_clicked);
    connect(ui->button_calendario, &QPushButton::clicked, this, &opciones_extras::on_button_calendario_clicked);
}

/**
 * @brief Destructor de la clase opciones_extras
 */
opciones_extras::~opciones_extras()
{
    delete ui;
    if (infoWindow) delete infoWindow;
    if (gestionCicloWindow) delete gestionCicloWindow;
    if (resultadoWindow) delete resultadoWindow;
}

/**
 * @brief Slot llamado al hacer clic en el botón de información
 */
void opciones_extras::on_button_info_clicked()
{
    qDebug() << "Botón info clicado.";

    if (!infoWindow) {
        infoWindow = new info(nullptr);  // Crear la ventana sin un padre
    }
    infoWindow->show();
    infoWindow->raise();
    infoWindow->activateWindow();
}

/**
 * @brief Slot llamado al hacer clic en el botón para agregar datos
 */
void opciones_extras::on_button_agregarDatos_clicked()
{
    qDebug() << "Botón agregarDatos clicado.";

    if (!gestionCicloWindow) {
        gestionCicloWindow = new gestion_de_ciclo(nullptr);  // Crear la ventana sin un padre
        gestionCicloWindow->setUsuario(usuario);
    }
    gestionCicloWindow->show();
    gestionCicloWindow->raise();
    gestionCicloWindow->activateWindow();
}

/**
 * @brief Slot llamado al hacer clic en el botón de calendario
 */
void opciones_extras::on_button_calendario_clicked()
{
    qDebug() << "Botón calendario clicado.";

    if (!usuario->tieneRespuestasGuardadas()) {
        QMessageBox::warning(this, "Error", "Por favor, registre los datos primero.");
        return;
    }

    qDebug() << "Datos registrados, preparando para mostrar el calendario.";

    // Simplificar la lógica de apertura de resultadoWindow
    resultadoWindow = new Resultado(nullptr);  // Crear la ventana sin un padre
    qDebug() << "Ventana resultado creada.";

    resultadoWindow->show();
    resultadoWindow->raise();
    resultadoWindow->activateWindow();
    qDebug() << "Ventana resultado mostrada.";

    QVector<QString> respuestasGuardadas = usuario->cargarRespuestasGuardadas();
    QVector<int> respuestas;

    for (int i = 0; i < respuestasGuardadas.size() - 3; ++i) {
        respuestas.append(respuestasGuardadas[i].toInt());
    }

    int duracionPeriodo = respuestasGuardadas.takeLast().toInt();
    int duracionCiclo = respuestasGuardadas.takeLast().toInt();
    QDate fechaInicioUltimoPeriodo = QDate::fromString(respuestasGuardadas.takeLast(), Qt::ISODate);

    resultadoWindow->setResultados(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
    resultadoWindow->setRespuestas(respuestas);

    QDate fechaOvulacion = fechaInicioUltimoPeriodo.addDays(duracionCiclo / 2);
    QDate inicioDiasFertiles = fechaOvulacion.addDays(-5);
    QDate finDiasFertiles = fechaOvulacion.addDays(1);

    resultadoWindow->setDiasFertiles(inicioDiasFertiles, finDiasFertiles);

    qDebug() << "Resultados configurados y días fértiles establecidos.";
}

/**
 * @brief Slot llamado al hacer clic en el botón para cerrar la ventana
 */
void opciones_extras::on_pushButton_3_clicked()
{
    close();
}
