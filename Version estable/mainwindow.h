#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quiz_quedar_embarazada.h"
#include "usuario.h"
#include "inicio.h"
#include "info.h"  // Añadir la inclusión de info.h

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openQuizWindow();
    void showMainMenu();
    void inicioDeSesion();

private slots:
    void handleLogin(Usuario *usuario);  // Nueva función para manejar el inicio de sesión exitoso
    void openInfoWindow();  // Nueva función para abrir la ventana info

private:
    Ui::MainWindow *ui;
    Quiz_quedar_embarazada *quizWindow;
    Usuario *usuario;
    inicio *InicioWindow;  // Asegúrate de que esta línea esté presente
    info *infoWindow;  // Añadir la instancia de Info
};


#endif // MAINWINDOW_H
