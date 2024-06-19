#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inicio.h"
#include "quiz_quedar_embarazada.h"
#include "dateselectiondialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , quizWindow(new Quiz_quedar_embarazada(this))
    , usuario(nullptr)
    , InicioWindow(new inicio())  // Inicializar sin 'this' para que sea una ventana separada
{
    ui->setupUi(this);

    connect(ui->button_quedarme_embarazada_2, &QPushButton::clicked, this, &MainWindow::openQuizWindow);
    connect(quizWindow, &Quiz_quedar_embarazada::regresar_a_Menu, this, &MainWindow::showMainMenu);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::inicioDeSesion);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete quizWindow;
    delete InicioWindow;
    delete usuario;
}

void MainWindow::openQuizWindow()
{

    quizWindow->setUsuario(usuario);  // Configura el usuario en el quiz
    quizWindow->show();
}

void MainWindow::showMainMenu()
{
    this->show();

}

void MainWindow::inicioDeSesion()
{
  // Ocultar la ventana principal
    InicioWindow->show();  // Mostrar la ventana 'inicio' como ventana independiente
}


