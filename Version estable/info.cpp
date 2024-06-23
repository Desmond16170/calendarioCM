#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info),
    preguntaActual(0),
    respuestasCorrectas(0)
{
    ui->setupUi(this);

    // Agrega preguntas con sus respuestas
    texto.append(InfoPregunta("¿Que es la mestruación?",
    "La menstruación (también llamada periodo o regla)"
    "es cuando la sangre y el tejido que cubre tu útero salen de tu cuerpo "
    "a través de tu vagina. Esto suele ocurrir todos los meses",
    "Descubre más de que es la mestruación en el siguiente link:"
    "https://www.plannedparenthood.org/es/temas-de-salud/salud-y-bienestar/menstruacion"));
    texto.append(InfoPregunta("Título 2", "Texto de respuesta 2",""));

    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las funciones correspondientes
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &info::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &info::mostrarPreguntaAnterior);
    connect(ui->botonVolver, &QPushButton::clicked, this, &info::volver_a_Menu);
}

info::~info()
{
    delete ui;
}

void info::reiniciarInfo() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(texto[preguntaActual]);
}

void info::mostrarSiguientePregunta() {
    if (preguntaActual + 1 < texto.size()) {
        preguntaActual++;
        mostrarPregunta(texto[preguntaActual]);
    } else {
    }
}

void info::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
        preguntaActual--;
        mostrarPregunta(texto[preguntaActual]);
    }
}

void info::mostrarPregunta(const InfoPregunta &pregunta) {
    ui->titulo->setText(pregunta.Pregunta);
    ui->texto->setText(pregunta.Respuesta);
    ui->url->setText(pregunta.Respuesta1);
}

void info::volver_a_Menu() {
    close();  // Asegúrate de que este señal esté definida en tu archivo info.h
}
