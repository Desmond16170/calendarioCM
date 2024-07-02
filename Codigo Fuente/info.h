/**
 * @file info.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Información - Manejo y presentación de preguntas informativas
 * @brief Esta clase se encarga de manejar y presentar preguntas informativas dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QVector>
#include <QString>

/**
 * @brief Estructura InfoPregunta para almacenar la información de cada pregunta.
 */
struct InfoPregunta {
    QString Pregunta; ///< Texto de la pregunta
    QString Respuesta; ///< Texto de la respuesta
    QString Imagen; ///< Ruta de la imagen asociada
    QString URL; ///< URL adicional

    /**
     * @brief Constructor de la estructura InfoPregunta
     * @param p Texto de la pregunta
     * @param r Texto de la respuesta
     * @param i Ruta de la imagen
     * @param u URL adicional
     */
    InfoPregunta(const QString& p, const QString& r, const QString& i, const QString& u)
        : Pregunta(p), Respuesta(r), Imagen(i), URL(u) {}
};

namespace Ui {
class info;
}

/**
 * @brief La clase info maneja y presenta preguntas informativas en la aplicación.
 */
class info : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase info
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit info(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase info
     */
    ~info();

    /**
     * @brief Reinicia el cuestionario informativo.
     */
    void reiniciarInfo();

private slots:
    /**
     * @brief Muestra la siguiente pregunta del cuestionario.
     */
    void mostrarSiguientePregunta();

    /**
     * @brief Muestra la pregunta anterior del cuestionario.
     */
    void mostrarPreguntaAnterior();

    /**
     * @brief Vuelve al menú principal.
     */
    void volver_a_Menu();

    /**
     * @brief Acción al hacer clic en el botón "Volver".
     */
    void on_botonVolver_clicked();

    /**
     * @brief Acción al activar un enlace en el URL.
     * @param link Cadena de caracteres con el enlace
     */
    void on_url_linkActivated(const QString &link);

private:
    Ui::info *ui; ///< Objeto de la interfaz de usuario generada por Qt
    QVector<InfoPregunta> texto; ///< Vector de preguntas informativas
    int preguntaActual; ///< Índice de la pregunta actual
    int respuestasCorrectas; ///< Número de respuestas correctas

    /**
     * @brief Muestra una pregunta en la interfaz gráfica.
     * @param pregunta Referencia a un objeto InfoPregunta
     */
    void mostrarPregunta(const InfoPregunta &pregunta);
};

#endif // INFO_H
