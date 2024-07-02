/**
 * @file gestion_de_ciclo.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Gestión de Ciclo - Administración del ciclo menstrual y sus interacciones
 * @brief Esta clase se encarga de la gestión del ciclo menstrual, incluyendo la presentación de preguntas tipo quiz y la selección de fechas.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef GESTION_DE_CICLO_H
#define GESTION_DE_CICLO_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include "usuario.h"
#include "dateselectiondialog.h"
#include "resultado.h"

/**
 * @brief Estructura Quiz_de_Gestion_de_Ciclo para almacenar la información de cada pregunta del quiz.
 */
struct Quiz_de_Gestion_de_Ciclo {
    QString Pregunta; ///< Texto de la pregunta
    QVector<QString> Respuestas; ///< Lista de respuestas posibles
    int Respuesta_Correcta; ///< Índice de la respuesta correcta
};

namespace Ui {
class gestion_de_ciclo;
}

/**
 * @brief La clase gestion_de_ciclo administra el ciclo menstrual del usuario y presenta un quiz interactivo.
 */
class gestion_de_ciclo : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase gestion_de_ciclo
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit gestion_de_ciclo(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase gestion_de_ciclo
     */
    ~gestion_de_ciclo();

    /**
     * @brief Reinicia el quiz a su estado inicial.
     */
    void reiniciarQuiz();

    /**
     * @brief Establece el texto en un QLabel (cuadro de texto) de la interfaz gráfica.
     * @param texto Cadena de caracteres
     */
    void setTextoEnLabel(const QString &texto);

    /**
     * @brief Vuelve al menú principal.
     */
    void volver_a_Menu();

    /**
     * @brief Guarda el estado actual de la aplicación.
     */
    void guardarEstado();

    /**
     * @brief Carga el estado previamente guardado de la aplicación.
     */
    void cargarEstado();

    /**
     * @brief Establece el usuario actual.
     * @param usuario Puntero al objeto Usuario
     */
    void setUsuario(Usuario *usuario);

    /**
     * @brief Obtiene las respuestas del usuario.
     * @return Vector de enteros con las respuestas del usuario
     */
    QVector<int> getRespuestas();

    /**
     * @brief Muestra el resultado del quiz.
     */
    void mostrarResultado();

    /**
     * @brief Establece la fecha de inicio del último período menstrual.
     * @param fecha Objeto QDate con la fecha de inicio
     */
    void setFechaInicioUltimoPeriodo(const QDate &fecha);

    /**
     * @brief Verifica si la ventana está visible.
     * @return Booleano indicando si la ventana está visible
     */
    bool isWindowVisible();

protected:
    /**
     * @brief Evento que se ejecuta al mostrar la ventana.
     * @param event Puntero al objeto QShowEvent
     */
    void showEvent(QShowEvent *event) override;

signals:
    /**
     * @brief Señal emitida cuando el quiz ha terminado.
     */
    void quizTerminado();

    /**
     * @brief Señal emitida para regresar al menú.
     */
    void regresar_a_Menu();

private slots:
    /**
     * @brief Muestra la siguiente pregunta del quiz.
     */
    void mostrarSiguientePregunta();

    /**
     * @brief Muestra la pregunta anterior del quiz.
     */
    void mostrarPreguntaAnterior();

    /**
     * @brief Calcula el ciclo menstrual basado en las respuestas del usuario.
     */
    void calcularCicloMenstrual();

    /**
     * @brief Muestra la pantalla de selección de fecha.
     */
    void mostrarPantallaSeleccionFecha();

    /**
     * @brief Acción al hacer clic en el botón "Volver".
     */
    void on_botonVolver_2_clicked();

private:
    Ui::gestion_de_ciclo *ui; ///< Objeto de la interfaz de usuario generada por Qt
    QVector<Quiz_de_Gestion_de_Ciclo> texto; ///< Vector de preguntas del quiz
    int preguntaActual; ///< Índice de la pregunta actual
    int respuestasCorrectas; ///< Número de respuestas correctas
    Usuario *usuario; ///< Puntero al objeto Usuario
    QDate fechaInicioUltimoPeriodo; ///< Fecha de inicio del último período menstrual
    int duracionCiclo; ///< Duración del ciclo menstrual
    int duracionPeriodo; ///< Duración del período menstrual
    QVector<int> respuestas; ///< Vector de respuestas del usuario
    QDate diasFertilesInicio; ///< Fecha de inicio de los días fértiles
    QDate diasFertilesFin; ///< Fecha de fin de los días fértiles

    /**
     * @brief Muestra una pregunta en la interfaz gráfica.
     * @param pregunta Referencia a un objeto Quiz_de_Gestion_de_Ciclo
     */
    void mostrarPregunta(const Quiz_de_Gestion_de_Ciclo &pregunta);

    /**
     * @brief Guarda las respuestas del usuario.
     */
    void guardarRespuestas();
};

#endif // GESTION_DE_CICLO_H
