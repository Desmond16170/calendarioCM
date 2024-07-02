/**
 * @file gestion_de_ciclo.cpp
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Gestión de Ciclo - Implementación
 * @brief Este archivo contiene la implementación de la clase gestion_de_ciclo, que maneja la gestión del ciclo menstrual dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include <QTextStream>
#include "gestion_de_ciclo.h"
#include "ui_gestion_de_ciclo.h"
#include "dateselectiondialog.h"
#include "resultado.h"
#include <QTimer>
#include <QMessageBox>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDebug> // Incluir la cabecera para qDebug

/**
 * @brief Constructor de la clase gestion_de_ciclo
 * @param parent Puntero al widget padre
 */
gestion_de_ciclo::gestion_de_ciclo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_de_ciclo),
    preguntaActual(0),
    respuestasCorrectas(0),
    duracionCiclo(28),
    duracionPeriodo(5)
{
    ui->setupUi(this);
    qDebug() << "Ventana gestion_de_ciclo inicializada."; // Añadir mensaje de depuración

    texto.append({ "¿Cuál es la duración de tu ciclo menstrual (en días)?",
                  {"28", "30", "35", "Otro"},
                  -1 });
    texto.append({ "¿Cuál es la duración de tu período (en días)?",
                  {"3", "5", "7", "Otro"},
                  -1 });

    mostrarPregunta(texto[preguntaActual]);

    connect(ui->BotonSiguiente_2, &QPushButton::clicked, this, &gestion_de_ciclo::mostrarSiguientePregunta);
    connect(ui->BotonAnterior_2, &QPushButton::clicked, this, &gestion_de_ciclo::mostrarPreguntaAnterior);
    connect(ui->botonVolver_2, &QPushButton::clicked, this, &gestion_de_ciclo::volver_a_Menu);
}

/**
 * @brief Destructor de la clase gestion_de_ciclo
 */
gestion_de_ciclo::~gestion_de_ciclo() {
    delete ui;
}

/**
 * @brief Establece el usuario actual
 * @param usuario Puntero al objeto Usuario
 */
void gestion_de_ciclo::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
    qDebug() << "Usuario asignado en gestion_de_ciclo.";
}

/**
 * @brief Verifica si la ventana está visible
 * @return true si la ventana está visible, false en caso contrario
 */
bool gestion_de_ciclo::isWindowVisible() {
    return this->isVisible();
}

/**
 * @brief Evento que se ejecuta al mostrar la ventana
 * @param event Puntero al objeto QShowEvent
 */
void gestion_de_ciclo::showEvent(QShowEvent *event) {
    qDebug() << "gestion_de_ciclo showEvent triggered";
    QMainWindow::showEvent(event);
    this->raise();
    this->activateWindow();
}

/**
 * @brief Reinicia el quiz a su estado inicial
 */
void gestion_de_ciclo::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    respuestas.clear();
    mostrarPregunta(texto[preguntaActual]);
}

/**
 * @brief Establece el texto en un QLabel
 * @param texto Cadena de caracteres
 */
void gestion_de_ciclo::setTextoEnLabel(const QString &texto) {
    ui->questionLabel->setText(texto);
}

/**
 * @brief Vuelve al menú principal
 */
void gestion_de_ciclo::volver_a_Menu() {
    emit regresar_a_Menu();
}

/**
 * @brief Muestra la siguiente pregunta del quiz
 */
void gestion_de_ciclo::mostrarSiguientePregunta() {
    int respuestaSeleccionada = -1;
    if (ui->option1RadioButton->isChecked()) respuestaSeleccionada = 0;
    else if (ui->option2RadioButton->isChecked()) respuestaSeleccionada = 1;
    else if (ui->option3RadioButton->isChecked()) respuestaSeleccionada = 2;
    else if (ui->option4RadioButton->isChecked()) respuestaSeleccionada = 3;

    if (preguntaActual < texto.size()) {
        respuestas.append(respuestaSeleccionada);

        switch (preguntaActual) {
        case 0:
            if (respuestaSeleccionada == 0) duracionCiclo = 28;
            else if (respuestaSeleccionada == 1) duracionCiclo = 30;
            else if (respuestaSeleccionada == 2) duracionCiclo = 35;
            else duracionCiclo = 28;
            break;
        case 1:
            if (respuestaSeleccionada == 0) duracionPeriodo = 3;
            else if (respuestaSeleccionada == 1) duracionPeriodo = 5;
            else if (respuestaSeleccionada == 2) duracionPeriodo = 7;
            else duracionPeriodo = 5;
            break;
        }
    }

    if (preguntaActual + 1 < texto.size()) {
        preguntaActual++;
        mostrarPregunta(texto[preguntaActual]);
    } else {
        mostrarPantallaSeleccionFecha();
    }
}

/**
 * @brief Muestra la pregunta anterior del quiz
 */
void gestion_de_ciclo::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
        preguntaActual--;
        respuestas.removeLast();
        mostrarPregunta(texto[preguntaActual]);
    }
}

/**
 * @brief Muestra una pregunta en la interfaz gráfica
 * @param pregunta Referencia a un objeto Quiz_de_Gestion_de_Ciclo
 */
void gestion_de_ciclo::mostrarPregunta(const Quiz_de_Gestion_de_Ciclo &pregunta) {
    ui->questionLabel->setText(pregunta.Pregunta);
    ui->option1RadioButton->setText(pregunta.Respuestas[0]);
    ui->option2RadioButton->setText(pregunta.Respuestas[1]);
    ui->option3RadioButton->setText(pregunta.Respuestas[2]);
    ui->option4RadioButton->setText(pregunta.Respuestas[3]);

    ui->option1RadioButton->setAutoExclusive(false);
    ui->option2RadioButton->setAutoExclusive(false);
    ui->option3RadioButton->setAutoExclusive(false);
    ui->option4RadioButton->setAutoExclusive(false);

    ui->option1RadioButton->setChecked(false);
    ui->option2RadioButton->setChecked(false);
    ui->option3RadioButton->setChecked(false);
    ui->option4RadioButton->setChecked(false);

    ui->option1RadioButton->setAutoExclusive(true);
    ui->option2RadioButton->setAutoExclusive(true);
    ui->option3RadioButton->setAutoExclusive(true);
    ui->option4RadioButton->setAutoExclusive(true);
}

/**
 * @brief Muestra la pantalla de selección de fecha
 */
void gestion_de_ciclo::mostrarPantallaSeleccionFecha() {
    DateSelectionDialog dateDialog(this);
    if (dateDialog.exec() == QDialog::Accepted) {
        fechaInicioUltimoPeriodo = dateDialog.getSelectedDate();
        calcularCicloMenstrual();
        guardarRespuestas();
        mostrarResultado();
    }
}

/**
 * @brief Calcula el ciclo menstrual basado en las respuestas del usuario
 */
void gestion_de_ciclo::calcularCicloMenstrual() {
    if (!fechaInicioUltimoPeriodo.isValid()) {
        QMessageBox::warning(this, "Error", "Por favor selecciona una fecha válida.");
        mostrarPantallaSeleccionFecha();
        return;
    }

    QDate fechaOvulacion = fechaInicioUltimoPeriodo.addDays(duracionCiclo / 2);
    QDate inicioDiasFertiles = fechaOvulacion.addDays(-5);
    QDate finDiasFertiles = fechaOvulacion.addDays(1);

    diasFertilesInicio = inicioDiasFertiles;
    diasFertilesFin = finDiasFertiles;
}

/**
 * @brief Muestra el resultado del ciclo menstrual
 */
void gestion_de_ciclo::mostrarResultado() {
    qDebug() << "mostrarResultado called";
    Resultado *resultado = new Resultado(nullptr);
    resultado->setResultados(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
    resultado->setRespuestas(respuestas);
    resultado->show();

    QTimer::singleShot(100, resultado, [resultado]() {
        resultado->raise();
        resultado->activateWindow();
    });

    if (resultado->isVisible()) {
        qDebug() << "Resultado window is visible";
    } else {
        qDebug() << "Resultado window is NOT visible";
    }
}

/**
 * @brief Guarda las respuestas del usuario en un archivo
 */
void gestion_de_ciclo::guardarRespuestas() {
    if (!usuario) {
        qDebug() << "Usuario no establecido, no se pueden guardar respuestas";
        return;
    }

    QString fileName = usuario->getNombreUsuario() + "_respuestas.log";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo para guardar respuestas";
        return;
    }

    QTextStream out(&file);
    for (int respuesta : respuestas) {
        out << respuesta << "\n";
    }

    out << fechaInicioUltimoPeriodo.toString(Qt::ISODate) << "\n";
    out << duracionCiclo << "\n";
    out << duracionPeriodo << "\n";

    file.close();
    qDebug() << "Respuestas guardadas en" << fileName;
}

/**
 * @brief Establece la fecha de inicio del último período menstrual
 * @param fecha Objeto QDate con la fecha de inicio
 */
void gestion_de_ciclo::setFechaInicioUltimoPeriodo(const QDate &fecha) {
    fechaInicioUltimoPeriodo = fecha;
}

/**
 * @brief Obtiene las respuestas del usuario
 * @return Vector de enteros con las respuestas del usuario
 */
QVector<int> gestion_de_ciclo::getRespuestas() {
    return respuestas;
}

/**
 * @brief Slot llamado al hacer clic en el botón "Volver"
 */
void gestion_de_ciclo::on_botonVolver_2_clicked()
{
    close();
}
