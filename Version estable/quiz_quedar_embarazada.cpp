#include "quiz_quedar_embarazada.h"
#include "ui_quiz_quedar_embarazada.h"
#include "dateselectiondialog.h"
#include "resultado.h"
#include <QTimer>
#include <QMessageBox>
#include <QDate>

Quiz_quedar_embarazada::Quiz_quedar_embarazada(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Quiz_quedar_embarazada),
    preguntaActual(0),
    respuestasCorrectas(0),
    duracionCiclo(28),
    duracionPeriodo(5)
{
    ui->setupUi(this);

    // Agrega preguntas con sus opciones y respuestas correctas
    texto.append({ "¿Cuál es la duración de tu ciclo menstrual (en días)?",
                  {"28", "30", "35", "Otro"},
                  -1 });
    texto.append({ "¿Cuál es la duración de tu período (en días)?",
                  {"3", "5", "7", "Otro"},
                  -1 });

    // Muestra la primera pregunta
    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las direcciones correspondientes
    connect(ui->BotonSiguiente_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::mostrarSiguientePregunta);
    connect(ui->BotonAnterior_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::mostrarPreguntaAnterior);
    connect(ui->botonVolver_2, &QPushButton::clicked, this, &Quiz_quedar_embarazada::volver_a_Menu);
}

Quiz_quedar_embarazada::~Quiz_quedar_embarazada()
{
    delete ui;
}

void Quiz_quedar_embarazada::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Quiz_quedar_embarazada::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    respuestas.clear();  // Limpiar las respuestas anteriores
    mostrarPregunta(texto[preguntaActual]);
}

void Quiz_quedar_embarazada::setTextoEnLabel(const QString &texto) {
    ui->questionLabel->setText(texto);
}

void Quiz_quedar_embarazada::volver_a_Menu() {
    emit regresar_a_Menu();

}

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

void Quiz_quedar_embarazada::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
        preguntaActual--;
        respuestas.removeLast();  // Remover la última respuesta al ir hacia atrás
        mostrarPregunta(texto[preguntaActual]);
    }
}

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

void Quiz_quedar_embarazada::mostrarPantallaSeleccionFecha() {
    DateSelectionDialog dateDialog(this);
    if (dateDialog.exec() == QDialog::Accepted) {
        fechaInicioUltimoPeriodo = dateDialog.getSelectedDate();
        calcularCicloMenstrual();
        mostrarResultado();
    }
}


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

    QString mensaje = QString("Tu próximo período es el %1. \nTus días fértiles son del %2 al %3.")
                          .arg(fechaInicioUltimoPeriodo.addDays(duracionCiclo).toString("dd-MM-yyyy"))
                          .arg(inicioDiasFertiles.toString("dd-MM-yyyy"))
                          .arg(finDiasFertiles.toString("dd-MM-yyyy"));

    QMessageBox::information(this, "Resultado del Ciclo Menstrual", mensaje);
}

void Quiz_quedar_embarazada::mostrarResultado() {
    qDebug() << "mostrarResultado called";
    Resultado *resultado = new Resultado(nullptr); // Crear la ventana sin un padre para que sea independiente
    resultado->setResultados(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
    resultado->show();

    // Usar un temporizador para asegurar que la ventana se muestra en primer plano
    QTimer::singleShot(100, resultado, [resultado]() {
        resultado->raise();
        resultado->activateWindow();
    });

    if (resultado->isVisible()) {
        qDebug() << "Resultado window is visible";
    } else {
        qDebug() << "Resultado window is NOT visible";
    }

    // No ocultar la ventana actual
}



void Quiz_quedar_embarazada::setFechaInicioUltimoPeriodo(const QDate &fecha) {
    fechaInicioUltimoPeriodo = fecha;
}

QVector<int> Quiz_quedar_embarazada::getRespuestas() {
    return respuestas;
}
