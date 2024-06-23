#ifndef QUIZ_QUEDAR_EMBARAZADA_H
#define QUIZ_QUEDAR_EMBARAZADA_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include "usuario.h"
#include "dateselectiondialog.h"
#include "resultado.h"

struct Quiz_de_Quedar_Embarazada {
    QString Pregunta;
    QVector<QString> Respuestas;
    int Respuesta_Correcta;
};

namespace Ui {
class Quiz_quedar_embarazada;
}

class Quiz_quedar_embarazada : public QMainWindow {
    Q_OBJECT

public:
    explicit Quiz_quedar_embarazada(QWidget *parent = nullptr);
    ~Quiz_quedar_embarazada();

    void reiniciarQuiz();
    void setTextoEnLabel(const QString &texto);
    void volver_a_Menu();
    void guardarEstado();
    void cargarEstado();
    void setUsuario(Usuario *usuario);
    QVector<int> getRespuestas();  // Nueva función para obtener las respuestas del usuario

    void mostrarResultado();  // Hacer pública esta función
    void setFechaInicioUltimoPeriodo(const QDate &fecha);  // Nueva función pública

signals:
    void quizTerminado();
    void regresar_a_Menu();

private slots:
    void mostrarSiguientePregunta();
    void mostrarPreguntaAnterior();
    void calcularCicloMenstrual();
    void mostrarPantallaSeleccionFecha();

private:
    Ui::Quiz_quedar_embarazada *ui;
    QVector<Quiz_de_Quedar_Embarazada> texto;
    int preguntaActual;
    int respuestasCorrectas;
    Usuario *usuario;
    QDate fechaInicioUltimoPeriodo;
    int duracionCiclo;
    int duracionPeriodo;

    QVector<int> respuestas;  // Nueva variable para almacenar las respuestas del usuario

    void mostrarPregunta(const Quiz_de_Quedar_Embarazada &pregunta);
};

#endif // QUIZ_QUEDAR_EMBARAZADA_H

