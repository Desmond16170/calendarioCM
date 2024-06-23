#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inicio.h"
#include "quiz_quedar_embarazada.h"
#include "dateselectiondialog.h"
#include "info.h"  // Añadir la inclusión de info.h

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , quizWindow(new Quiz_quedar_embarazada(this))
    , usuario(nullptr)
    , InicioWindow(new inicio())  // Inicializar sin 'this' para que sea una ventana separada
    , infoWindow(new info())  // Inicializar la ventana Info
{
    ui->setupUi(this);

    connect(ui->button_quedarme_embarazada_2, &QPushButton::clicked, this, &MainWindow::openQuizWindow);
    connect(quizWindow, &Quiz_quedar_embarazada::regresar_a_Menu, this, &MainWindow::showMainMenu);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::inicioDeSesion);
    connect(InicioWindow, &inicio::loginSuccessful, this, &MainWindow::handleLogin);
    connect(ui->button_entendermicuerpo, &QPushButton::clicked, this, &MainWindow::openInfoWindow);  // Conectar el botón al slot
}

MainWindow::~MainWindow()
{
    delete ui;
    delete quizWindow;
    delete InicioWindow;
    delete usuario;
    delete infoWindow;
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
    // Mostrar la ventana de inicio de sesión
    InicioWindow->show();
}

void MainWindow::handleLogin(Usuario *usuario)
{
    // Asigna el usuario logueado
    this->usuario = usuario;
    InicioWindow->hide();  // Oculta la ventana de inicio de sesión
    this->show();  // Muestra la ventana principal

    // Actualizar el QLabel con el nombre de usuario
    ui->usernameLabel->setText("Usuario: " + usuario->getNombreUsuario());
}

void MainWindow::openInfoWindow()
{
    infoWindow->show();  // Mostrar la ventana info
}
