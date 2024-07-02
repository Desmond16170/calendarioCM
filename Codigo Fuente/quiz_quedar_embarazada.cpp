/**
 * @file quiz_quedar_embarazada.cpp
 * @title Quiz Quedar Embarazada - Implementación
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase Quiz_quedar_embarazada, que maneja el quiz sobre la probabilidad de quedar embarazada.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "quiz_quedar_embarazada.h"
#include "ui_quiz_quedar_embarazada.h"
#include "dateselectiondialog.h"
#include "resultado.h"
#include <QTimer>
#include <QMessageBox>
#include <QDate>
#include <QFile>
#include <QTextStream>

/**
 * @brief Constructor de la clase Quiz_quedar_embarazada
 * @param parent Puntero al widget padre
 */
Quiz_quedar_embarazada::Quiz_quedar_embarazada(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Quiz_quedar_embarazada),
    preguntaActual(0),
    respuestasCorrectas(0),
    duracionCiclo(28),
    duracionPeriodo(5)
{
    ui->setupUi(this);

    texto.append({ "¿Cuál es la duración de tu ciclo menstrual (en días)?",
                  {"28", "30", "35", "Otro"},
                  -1 });
    texto.append({ "¿Cuál es la duración de tu período (en días)?",
                  {"3", "5", "7", "Otro"},
                  -1 });

    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las direcciones correspondientes
    connect(ui->BotonSiguiente_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::mostrarSiguientePregunta);
    connect(ui->BotonAnterior_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::mostrarPreguntaAnterior);
    connect(ui->botonVolver_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::volver_a_Menu);
}

/**
 * @brief Destructor de la clase Quiz_quedar_embarazada
 */
Quiz_quedar_embarazada::~Quiz_quedar_embarazada()
{
    delete ui;
}

/**
 * @brief Establece el usuario actual
 * @param usuario Puntero al objeto Usuario
 */
void Quiz_quedar_embarazada::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

/**
 * @brief Reinicia el quiz a su estado inicial
 */
void Quiz_quedar_embarazada::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    respuestas.clear();  // Limpiar las respuestas anteriores
    mostrarPregunta(texto[preguntaActual]);
}

/**
 * @brief Establece el texto en un QLabel
 * @param texto Cadena de caracteres
 */
void Quiz_quedar_embarazada::setTextoEnLabel(const QString &texto) {
    ui->questionLabel->setText(texto);
}

/**
 * @brief Vuelve al menú principal
 */
void Quiz_quedar_embarazada::volver_a_Menu() {
    emit regresar_a_Menu();
}

/**
 * @brief Muestra la siguiente pregunta del quiz
 */
void Quiz_quedar_embarazada::mostrarSiguientePregunta() {
    int respuestaSeleccionada = -1;
    if (ui->option1RadioButton->isChecked()) respuestaSeleccionada = 0;
    else if (ui->option2RadioButton->isChecked()) respuestaSeleccionada = 1;
    else if (ui->option3RadioButton->isChecked()) respuestaSeleccionada = 2;
    else if (ui->option4RadioButton->isChecked()) respuestaSeleccionada = 3;

    if (preguntaActual < texto.size()) {
        respuestas.append(respuestaSeleccionada);  // Almacenar la respuesta seleccionada

        // Guardar las respuestas del usuario
        switch (preguntaActual) {
        case 0:  // Duración del ciclo
            if (respuestaSeleccionada == 0) duracionCiclo = 28;
            else if (respuestaSeleccionada == 1) duracionCiclo = 30;
            else if (respuestaSeleccionada == 2) duracionCiclo = 35;
            else duracionCiclo = 28;  // Puedes manejar "Otro" de manera diferente si es necesario
            break;
        case 1:  // Duración del período
            if (respuestaSeleccionada == 0) duracionPeriodo = 3;
            else if (respuestaSeleccionada == 1) duracionPeriodo = 5;
            else if (respuestaSeleccionada == 2) duracionPeriodo = 7;
            else duracionPeriodo = 5;  // Puedes manejar "Otro" de manera diferente si es necesario
            break;
        }
    }

    if (preguntaActual + 1 < texto.size()) {
        preguntaActual++;
        mostrarPregunta(texto[preguntaActual]);
    } else {
        mostrarPantallaSeleccionFecha();  // Mostrar la pantalla de selección de fecha aquí
    }
}

/**
 * @brief Muestra la pregunta anterior del quiz
 */
void Quiz_quedar_embarazada::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
        preguntaActual--;
        respuestas.removeLast();  // Remover la última respuesta al ir hacia atrás
        mostrarPregunta(texto[preguntaActual]);
    }
}

/**
 * @brief Muestra una pregunta en la interfaz gráfica
 * @param pregunta Referencia a un objeto Quiz_de_Quedar_Embarazada
 */
void Quiz_quedar_embarazada::mostrarPregunta(const Quiz_de_Quedar_Embarazada &pregunta) {
    ui->questionLabel->setText(pregunta.Pregunta);
    ui->option1RadioButton->setText(pregunta.Respuestas[0]);
    ui->option2RadioButton->setText(pregunta.Respuestas[1]);
    ui->option3RadioButton->setText(pregunta.Respuestas[2]);
    ui->option4RadioButton->setText(pregunta.Respuestas[3]);

    // Deseleccionar todas las respuestas
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
void Quiz_quedar_embarazada::mostrarPantallaSeleccionFecha() {
    DateSelectionDialog dateDialog(this);
    if (dateDialog.exec() == QDialog::Accepted) {
        fechaInicioUltimoPeriodo = dateDialog.getSelectedDate();
        calcularCicloMenstrual();
        guardarRespuestas();  // Guardar las respuestas antes de mostrar el resultado
        mostrarResultado();
    }
}

/**
 * @brief Calcula el ciclo menstrual basado en las respuestas del usuario
 */
void Quiz_quedar_embarazada::calcularCicloMenstrual() {
    // Verificar si se ha seleccionado una fecha válida
    if (!fechaInicioUltimoPeriodo.isValid()) {
        QMessageBox::warning(this, "Error", "Por favor selecciona una fecha válida.");
        mostrarPantallaSeleccionFecha(); // Volver a mostrar el diálogo si la fecha no es válida
        return;
    }

    // Calcula los días fértiles basados en las respuestas del usuario
    QDate fechaOvulacion = fechaInicioUltimoPeriodo.addDays(duracionCiclo / 2);
    QDate inicioDiasFertiles = fechaOvulacion.addDays(-5);
    QDate finDiasFertiles = fechaOvulacion.addDays(1);

    diasFertilesInicio = inicioDiasFertiles;
    diasFertilesFin = finDiasFertiles;
}

/**
 * @brief Muestra el resultado del ciclo menstrual
 */
void Quiz_quedar_embarazada::mostrarResultado() {
    qDebug() << "mostrarResultado called";
    Resultado *resultado = new Resultado(nullptr); // Crear la ventana sin un padre para que sea independiente
    resultado->setResultados(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
    resultado->setRespuestas(respuestas);
    resultado->setDiasFertiles(diasFertilesInicio, diasFertilesFin);  // Pasar los días fértiles
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
void Quiz_quedar_embarazada::guardarRespuestas() {
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

    out << fechaInicioUltimoPeriodo.toString(Qt::ISODate) << "\n";  // Guardar como cadena de texto
    out << duracionCiclo << "\n";
    out << duracionPeriodo << "\n";

    file.close();
    qDebug() << "Respuestas guardadas en" << fileName;
}

/**
 * @brief Establece la fecha de inicio del último período menstrual
 * @param fecha Objeto QDate con la fecha de inicio
 */
void Quiz_quedar_embarazada::setFechaInicioUltimoPeriodo(const QDate &fecha) {
    fechaInicioUltimoPeriodo = fecha;
}

/**
 * @brief Obtiene las respuestas del usuario
 * @return Vector de enteros con las respuestas del usuario
 */
QVector<int> Quiz_quedar_embarazada::getRespuestas() {
    return respuestas;
}

/**
 * @brief Slot llamado al hacer clic en el botón "Volver"
 */
void Quiz_quedar_embarazada::on_botonVolver_2_clicked()
{
    close();
}

