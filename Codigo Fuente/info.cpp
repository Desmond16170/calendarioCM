/**
 * @file info.cpp
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Información - Implementación
 * @brief Este archivo contiene la implementación de la clase info, que maneja la presentación de preguntas informativas dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "info.h"
#include "ui_info.h"
#include <QDir>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>

/**
 * @brief Constructor de la clase info
 * @param parent Puntero al widget padre
 */
info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info),
    preguntaActual(0),
    respuestasCorrectas(0)
{
    ui->setupUi(this);
    // Configurar el QLabel para que funcione como un enlace
    ui->url->setTextFormat(Qt::RichText);
    ui->url->setOpenExternalLinks(true);

    // Conectar el slot para manejar los clics en enlaces
    connect(ui->url, &QLabel::linkActivated, this, &info::on_url_linkActivated);

    // Ruta relativa a la carpeta de imágenes desde el directorio del proyecto
    QString imageDir = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../../../Imagenes/");

    // Agrega preguntas con sus respuestas usando QString
    texto.append(InfoPregunta("¿Qué es la menstruación?",
                              "La menstruación (también llamada periodo o regla) \nes cuando la sangre y el tejido que cubre tu útero \nsalen de tu cuerpo a través de tu vagina. \nEsto suele ocurrir todos los meses. ",
                              imageDir + "/menstruacion.jpg",
                              "<br><br><a href=\"https://www.plannedparenthood.org/es/temas-de-salud/salud-y-bienestar/menstruacion\">Descubre más acá</a>"));

    texto.append(InfoPregunta("¿Qué es el ciclo menstrual?",
                              "El ciclo menstrual es una serie mensual de cambios \nque ocurren "
                              "en el cuerpo\n"
                              "en preparación para el embarazo. Cada mes, uno \nde los ovarios "
                              "libera un óvulo.\n"
                              "Esto se llama ovulación. Los cambios hormonales \nde esta etapa"
                              "preparan al útero para el embarazo.\n"
                              "Si el óvulo liberado no se fertiliza durante \nla ovulación, el"
                              "recubrimiento del útero \n"
                              "se expulsa a través de la vagina. Este es el \nperíodo menstrual.\n"
                              "Te gustaría saber qué es normal \ny qué no visita el siguiente link:",
                              imageDir + "image1.jpg",
                              "<br><br><a href=\"https://www.mayoclinic.org/es/healthy-lifestyle/womens-health/in-depth/menstrual-cycle/art-20047186\">Descubre más acá</a>"));

    texto.append(InfoPregunta("¿Cómo te afectan las hormonas?",
                              "Las hormonas son mensajeros químicos liberados por \n"
                              "las glándulas del cuerpo, fundamentales para procesos\n"
                              " como la pubertad y el ciclo menstrual.\n"
                              "Aunque son esenciales para el desarrollo y el\n "
                              "funcionamiento correcto del cuerpo, también tienen \n"
                              "efectos negativos.\n"
                              "Durante la pubertad, los cambios hormonales pueden \n"
                              "causar cambios de humor,\n"
                              " irritabilidad, tristeza y ansiedad debido a la \n"
                              "desincronización entre las hormonas \n"
                              "y la química cerebral. Además, estos cambios hormonales \n"
                              "pueden provocar granos, \n"
                              "exceso de vello corporal y aumento del olor corporal. Por eso, \n"
                              "aunque las hormonas \n"
                              "son cruciales para el crecimiento, también pueden hacer \n"
                              "que las emociones sean \n"
                              "difíciles de manejar y que el cuerpo se sienta extraño.\n"
                              "Si quieres saber más ingresa al siguiente link:\n",
                              imageDir + "/hormonas.jpg",
                              "<br><br><a href=\"https://www.saba-centroamerica.com/cr/rompiendo-mitos/mito-verdad/pubertad/menstruation-cycle-hormones/\">Descubre más acá</a>"));

    texto.append(InfoPregunta("¿Cuáles son los síntomas de la menstruación?",
                              "El principal signo de la menstruación es\n "
                              "sangrado a través de la vagina.\n"
                              "Otros síntomas incluyen:\n"
                              "⦁ Calambres pelvianos o abdominales\n"
                              "⦁ Dolor en la parte baja de la espalda\n"
                              "⦁ Mamas hinchadas y doloridas\n"
                              "⦁ Antojos de alimentos\n"
                              "⦁ Cambios en el estado de ánimo e irritabilidad\n"
                              "⦁ Dolor de cabeza\n"
                              "⦁ Fatiga\n"
                              "⦁ entre otros.\n"
                              "Más información siguiente link:\n",
                              imageDir + "/sintomas.jpg",
                              "<br><br><a href=\"https://www.mayoclinic.org/es/diseases-conditions/premenstrual-syndrome/symptoms-causes/syc-20376780\">Descubre más acá</a>"));

    texto.append(InfoPregunta("Te gustaría saber sobre tú Higiene menstrual",
                              "Puedes pulsar el link \n"
                              "que se encuntra abajo \n"
                              "para que te redireccione\n"
                              "Más información:\n",
                              imageDir + "/Higiene.jpg",
                              "<br><br><a href=\"https://salud.edomex.gob.mx/isem/salud_menstrual\">Descubre más acá</a>"));

    texto.append(InfoPregunta("¿Te gustaría saber sobre la Educación y \nComunicación en tu ciclo menstrual?",
                              "La educación sexual es fundamental para comprender mejor el \npropio cuerpo \n"
                              "y promover la salud y el bienestar. Aprender sobre \nla menstruación, sus fases\n"
                              " y los cambios hormonales asociados, permite a las mujeres \nmanejar mejor sus síntomas\n"
                              " y cuidar de su salud reproductiva. Además, mantener \nuna comunicación abierta sobre \n"
                              "la menstruación con familiares, amigos y profesionales \nde la salud es crucial. \n"
                              "Hablar sobre estos temas ayuda a desmitificar \nla menstruación, reducir el estigma \n"
                              "asociado y proporciona un apoyo emocional y práctico, \nfacilitando una experiencia \n"
                              "más positiva y empoderada durante este proceso natural.\n"
                              "Si necesitas más información descarga el folleto en el siguiente link:\n",
                              imageDir + "/Educacion.jpg",
                              "<br><br><a href=\"https://www.lakotex.cr/es-cr/iniciativa-ella-puede\">Descubre más acá</a>"));

    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las funciones correspondientes
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &info::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &info::mostrarPreguntaAnterior);
    connect(ui->botonVolver, &QPushButton::clicked, this, &info::volver_a_Menu);
}

/**
 * @brief Destructor de la clase info
 */
info::~info()
{
    delete ui;
}

/**
 * @brief Reinicia el cuestionario informativo a su estado inicial
 */
void info::reiniciarInfo() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(texto[preguntaActual]);
}

/**
 * @brief Muestra la siguiente pregunta del cuestionario
 */
void info::mostrarSiguientePregunta() {
    if (preguntaActual + 1 < texto.size()) {
        preguntaActual++;
        mostrarPregunta(texto[preguntaActual]);
    } else {
        // Si no hay más preguntas, puedes manejar este caso aquí.
    }
}

/**
 * @brief Muestra la pregunta anterior del cuestionario
 */
void info::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
        preguntaActual--;
        mostrarPregunta(texto[preguntaActual]);
    }
}

/**
 * @brief Muestra una pregunta en la interfaz gráfica
 * @param pregunta Referencia a un objeto InfoPregunta
 */
void info::mostrarPregunta(const InfoPregunta &pregunta) {
    ui->titulo->setText(pregunta.Pregunta);
    ui->texto->setText(pregunta.Respuesta);
    ui->url->setText(pregunta.URL);

    // Mostrar la imagen en el QLabel dentro del QFrame si la ruta no está vacía
    if (!pregunta.Imagen.isEmpty()) {
        QPixmap pixmap(pregunta.Imagen);
        if (!pixmap.isNull()) {
            ui->labelImagen->setPixmap(pixmap);
            ui->labelImagen->setScaledContents(true);
            ui->labelImagen->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image" << pregunta.Imagen;
            ui->labelImagen->clear(); // Clear the label if image loading fails
        }
    } else {
        ui->labelImagen->clear(); // Clear the label if there is no image
    }
}

/**
 * @brief Vuelve al menú principal
 */
void info::volver_a_Menu() {
    close();  // Asegúrate de que esta señal esté definida en tu archivo info.h
}

/**
 * @brief Slot llamado al hacer clic en el botón "Volver"
 */
void info::on_botonVolver_clicked()
{
    close();
}

/**
 * @brief Slot llamado al activar un enlace en el URL
 * @param link Cadena de caracteres con el enlace
 */
void info::on_url_linkActivated(const QString &link) {
    QDesktopServices::openUrl(QUrl(link));
}
