/**
 * @file opciones_extras.h
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Opciones Extras - Manejo de funcionalidades adicionales de la aplicación
 * @brief Esta clase se encarga de manejar las opciones extras y funcionalidades adicionales dentro de la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#ifndef OPCIONES_EXTRAS_H
#define OPCIONES_EXTRAS_H

#include <QWidget>
#include "info.h"
#include "gestion_de_ciclo.h"
#include "resultado.h"
#include "usuario.h"

namespace Ui {
class opciones_extras;
}

/**
 * @brief La clase opciones_extras maneja las opciones extras y funcionalidades adicionales en la aplicación.
 */
class opciones_extras : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase opciones_extras
     * @param parent El widget padre que contendrá a los otros widgets en esta ventana
     * @param usuario Puntero al objeto Usuario que está utilizando las opciones extras
     */
    explicit opciones_extras(QWidget *parent = nullptr, Usuario *usuario = nullptr);

    /**
     * @brief Destructor de la clase opciones_extras
     */
    ~opciones_extras();

private slots:
    /**
     * @brief Acción al hacer clic en el botón 3.
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Acción al hacer clic en el botón de información.
     */
    void on_button_info_clicked();

    /**
     * @brief Acción al hacer clic en el botón para agregar datos.
     */
    void on_button_agregarDatos_clicked();

    /**
     * @brief Acción al hacer clic en el botón de calendario.
     */
    void on_button_calendario_clicked();

private:
    Ui::opciones_extras *ui; ///< Objeto de la interfaz de usuario generada por Qt
    info *infoWindow; ///< Puntero a la ventana de información
    gestion_de_ciclo *gestionCicloWindow; ///< Puntero a la ventana de gestión de ciclo
    Resultado *resultadoWindow; ///< Puntero a la ventana de resultados
    Usuario *usuario; ///< Puntero al usuario actual para mantener la referencia
};

#endif // OPCIONES_EXTRAS_H
