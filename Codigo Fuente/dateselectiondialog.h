/**
 * @file DateSelectionDialog.h
 * @author Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Diálogo de Selección de Fecha - Interacciones del usuario con la selección de fechas
 * @brief Esta clase se encarga de desplegar un diálogo para la selección de fechas en la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef DATESELECTIONDIALOG_H
#define DATESELECTIONDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DateSelectionDialog;
}

/**
 * @brief La clase DateSelectionDialog presenta el diseño del diálogo de selección de fecha y contiene los botones para la navegación.
 */
class DateSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase DateSelectionDialog
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     */
    explicit DateSelectionDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase DateSelectionDialog
     */
    ~DateSelectionDialog();

    /**
     * @brief Obtiene la fecha seleccionada por el usuario.
     * @return La fecha seleccionada como un objeto QDate
     */
    QDate getSelectedDate() const;

private slots:
    /**
     * @brief Acción al hacer clic en el botón "Anterior".
     */
    void BotonAnterior_2_clicked();

    /**
     * @brief Acción al hacer clic en el botón "Siguiente".
     */
    void BotonSiguiente_2_clicked();

    /**
     * @brief Acción al hacer clic en el botón "Volver".
     */
    void botonVolver_2_clicked();

    /**
     * @brief Acción al aceptar el diálogo mediante el cuadro de botones.
     */
    void buttonBox_accepted();

private:
    Ui::DateSelectionDialog *ui; // Objeto de la interfaz de usuario generada por Qt
    QDate selectedDate; // Fecha seleccionada por el usuario
};

#endif // DATESELECTIONDIALOG_H
