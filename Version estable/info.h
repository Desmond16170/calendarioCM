#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QVector>
#include <QString>

struct InfoPregunta {
    QString Pregunta;
    QString Respuesta;
    QString Respuesta1;

    InfoPregunta(const QString& p, const QString& r,const QString& u) : Pregunta(p), Respuesta(r), Respuesta1(u) {}
};

namespace Ui {
class info;
}

class info : public QWidget
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

    void reiniciarInfo();  // Reiniciar el cuestionario


private slots:
    void mostrarSiguientePregunta();  // Declarar los slots aquí
    void mostrarPreguntaAnterior();   // Declarar los slots aquí
    void volver_a_Menu();             // Declarar los slots aquí

private:
    Ui::info *ui;
    QVector<InfoPregunta> texto;
    int preguntaActual;
    int respuestasCorrectas;

    void mostrarPregunta(const InfoPregunta &pregunta);
};

#endif // INFO_H

