/**
 * @file mainwindow.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Ventana Principal - Manejo de la interfaz principal de la aplicación
 * @brief Esta clase se encarga de manejar la ventana principal y la navegación entre las diferentes secciones de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quiz_quedar_embarazada.h"
#include "usuario.h"
#include "inicio.h"
#include "info.h"
#include "resultado.h"
#include "opciones_extras.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief La clase MainWindow maneja la ventana principal y la navegación en la aplicación.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase MainWindow
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase MainWindow
     */
    ~MainWindow();

    /**
     * @brief Abre la ventana del quiz.
     */
    void openQuizWindow();

    /**
     * @brief Muestra el menú principal.
     */
    void showMainMenu();

    /**
     * @brief Inicia sesión.
     */
    void inicioDeSesion();

    /**
     * @brief Abre la ventana de opciones extras.
     */
    void openOpcionesExtrasWindow();

protected:
    /**
     * @brief Evento que se ejecuta al cerrar la ventana.
     * @param event Puntero al objeto QCloseEvent
     */
    void closeEvent(QCloseEvent *event) override;

private slots:
    /**
     * @brief Maneja el inicio de sesión de un usuario.
     * @param usuario Puntero al objeto Usuario que ha iniciado sesión
     */
    void handleLogin(Usuario *usuario);

    /**
     * @brief Abre la ventana de información.
     */
    void openInfoWindow();

    /**
     * @brief Acción al hacer clic en el botón "Nada".
     */
    void on_button_nada_2_clicked();

    /**
     * @brief Acción al hacer clic en el botón "Gestionar Ciclo".
     */
    void on_button_gestionar_ciclo_clicked();

private:
    Ui::MainWindow *ui; ///< Objeto de la interfaz de usuario generada por Qt
    Quiz_quedar_embarazada *quizWindow; ///< Puntero a la ventana del quiz
    opciones_extras *opcionesExtrasWindow; ///< Puntero a la ventana de opciones extras
    Usuario *usuario; ///< Puntero al usuario actual
    inicio *InicioWindow; ///< Puntero a la ventana de inicio
    info *infoWindow; ///< Puntero a la ventana de información
    Resultado *resultadoWindow; ///< Puntero a la ventana de resultados

    /**
     * @brief Guarda los usuarios en un archivo.
     */
    void saveUsersToFile();
};

#endif // MAINWINDOW_H

