/**
 * @file quiz_quedar_embarazada.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Quiz Quedar Embarazada - Evaluación de la probabilidad de embarazo
 * @brief Esta clase se encarga de presentar y gestionar un quiz sobre la probabilidad de quedar embarazada.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef QUIZ_QUEDAR_EMBARAZADA_H
#define QUIZ_QUEDAR_EMBARAZADA_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include "usuario.h"
#include "dateselectiondialog.h"
#include "resultado.h"

/**
 * @brief Estructura Quiz_de_Quedar_Embarazada para almacenar la información de cada pregunta del quiz.
 */
struct Quiz_de_Quedar_Embarazada {
    QString Pregunta; ///< Texto de la pregunta
    QVector<QString> Respuestas; ///< Lista de respuestas posibles
    int Respuesta_Correcta; ///< Índice de la respuesta correcta
};

namespace Ui {
class Quiz_quedar_embarazada;
}

/**
 * @brief La clase Quiz_quedar_embarazada maneja el quiz sobre la probabilidad de quedar embarazada.
 */
class Quiz_quedar_embarazada : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase Quiz_quedar_embarazada
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit Quiz_quedar_embarazada(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Quiz_quedar_embarazada
     */
    ~Quiz_quedar_embarazada();

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
    Ui::Quiz_quedar_embarazada *ui; ///< Objeto de la interfaz de usuario generada por Qt
    QVector<Quiz_de_Quedar_Embarazada> texto; ///< Vector de preguntas del quiz
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
     * @param pregunta Referencia a un objeto Quiz_de_Quedar_Embarazada
     */
    void mostrarPregunta(const Quiz_de_Quedar_Embarazada &pregunta);

    /**
     * @brief Guarda las respuestas del usuario.
     */
    void guardarRespuestas();
};

#endif // QUIZ_QUEDAR_EMBARAZADA_H
