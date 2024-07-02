/**
 * @file mainwindow.cpp
 * @title Ventana Principal - Implementación
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la implementación de la clase MainWindow, que maneja la ventana principal y la navegación en la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inicio.h"
#include "quiz_quedar_embarazada.h"
#include "opciones_extras.h"
#include "dateselectiondialog.h"
#include "info.h"
#include "resultado.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCloseEvent>

/**
 * @brief Constructor de la clase MainWindow
 * @param parent Puntero al widget padre
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , quizWindow(new Quiz_quedar_embarazada(this))
    , opcionesExtrasWindow(nullptr)  // Inicializar como nullptr
    , usuario(nullptr)
    , InicioWindow(new inicio())
    , infoWindow(new info())
    , resultadoWindow(new Resultado())
{
    ui->setupUi(this);

    connect(ui->button_quedarme_embarazada_2, &QPushButton::clicked, this, &MainWindow::openQuizWindow);
    connect(quizWindow, &Quiz_quedar_embarazada::regresar_a_Menu, this, &MainWindow::showMainMenu);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::inicioDeSesion);
    connect(InicioWindow, &inicio::loginSuccessful, this, &MainWindow::handleLogin);
    connect(ui->button_entendermicuerpo, &QPushButton::clicked, this, &MainWindow::openInfoWindow);
    connect(ui->button_gestionar_ciclo, &QPushButton::clicked, this, &MainWindow::openOpcionesExtrasWindow);
}

/**
 * @brief Destructor de la clase MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete quizWindow;
    delete opcionesExtrasWindow;
    delete InicioWindow;
    delete usuario;
    delete infoWindow;
    delete resultadoWindow;
}

/**
 * @brief Abre la ventana del quiz
 */
void MainWindow::openQuizWindow()
{
    quizWindow->setUsuario(usuario);
    quizWindow->show();
}

/**
 * @brief Abre la ventana de opciones extras
 */
void MainWindow::openOpcionesExtrasWindow()
{
    qDebug() << "Botón gestionar ciclo clicado.";

    if (!opcionesExtrasWindow) {  // Solo crear una instancia si no existe
        opcionesExtrasWindow = new opciones_extras();
    }

    opcionesExtrasWindow->show();
    qDebug() << "Ventana opciones_extras mostrada.";

    if (opcionesExtrasWindow->isVisible()) {
        qDebug() << "Ventana opciones_extras es visible.";
    } else {
        qDebug() << "Ventana opciones_extras NO es visible.";
    }
}

/**
 * @brief Muestra el menú principal
 */
void MainWindow::showMainMenu()
{
    this->show();
}

/**
 * @brief Inicia la ventana de inicio de sesión
 */
void MainWindow::inicioDeSesion()
{
    InicioWindow->show();
}

/**
 * @brief Maneja el inicio de sesión de un usuario
 * @param usuario Puntero al objeto Usuario que ha iniciado sesión
 */
void MainWindow::handleLogin(Usuario *usuario)
{
    this->usuario = usuario;
    InicioWindow->hide();

    if (usuario->tieneRespuestasGuardadas()) {
        QVector<QString> respuestasGuardadas = usuario->cargarRespuestasGuardadas();
        QVector<int> respuestas;

        for (int i = 0; i < respuestasGuardadas.size() - 3; ++i) {
            respuestas.append(respuestasGuardadas[i].toInt());
        }

        int duracionPeriodo = respuestasGuardadas.takeLast().toInt();
        int duracionCiclo = respuestasGuardadas.takeLast().toInt();
        QDate fechaInicioUltimoPeriodo = QDate::fromString(respuestasGuardadas.takeLast(), Qt::ISODate);

        resultadoWindow->setResultados(fechaInicioUltimoPeriodo, duracionCiclo, duracionPeriodo);
        resultadoWindow->setRespuestas(respuestas);

        QDate fechaOvulacion = fechaInicioUltimoPeriodo.addDays(duracionCiclo / 2);
        QDate inicioDiasFertiles = fechaOvulacion.addDays(-5);
        QDate finDiasFertiles = fechaOvulacion.addDays(1);
        resultadoWindow->setDiasFertiles(inicioDiasFertiles, finDiasFertiles);

        resultadoWindow->show();
    } else {
        this->show();
    }
}

/**
 * @brief Abre la ventana de información
 */
void MainWindow::openInfoWindow()
{
    infoWindow->show();
}

/**
 * @brief Slot llamado al hacer clic en el botón "Nada"
 */
void MainWindow::on_button_nada_2_clicked()
{
    close();
}

/**
 * @brief Evento que se ejecuta al cerrar la ventana
 * @param event Puntero al objeto QCloseEvent
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveUsersToFile();
    event->accept();
}

/**
 * @brief Guarda los usuarios en un archivo
 */
void MainWindow::saveUsersToFile()
{
    QFile file("usuarios.log");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning("No se pudo abrir el archivo para guardar los usuarios.");
        return;
    }

    QTextStream out(&file);
    for (const Usuario &usuario : InicioWindow->getUsuarios()) {
        out << usuario.getNombreUsuario() << "," << usuario.getContrasena() << "\n";
    }

    file.close();
}

/**
 * @brief Slot llamado al hacer clic en el botón "Gestionar Ciclo"
 */
void MainWindow::on_button_gestionar_ciclo_clicked()
{
    qDebug() << "Botón gestionar ciclo clicado."; // Mensaje de depuración
    openOpcionesExtrasWindow();  // Llamar a la nueva función
}
