/**
 * @file main.cpp
 * @title Aplicación Principal
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @brief Este archivo contiene la función principal de la aplicación, configurando y mostrando la ventana principal.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include <QApplication>
#include "mainwindow.h"
#include "info.h"
#include "resultado.h"

/**
 * @brief Función principal de la aplicación
 * @param argc Número de argumentos de línea de comandos
 * @param argv Vector de argumentos de línea de comandos
 * @return Código de salida de la aplicación
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    info infoWindow;
    Resultado resultadoWindow;

    // Establece una hoja de estilo para la aplicación
    QString styleSheet =
        "QWidget { background-color: #FAF3F3; }"
        "QMainWindow { background-color: #FAF3F3; }"
        "QLabel { color: #2C3E50; font-size: 16px; }"
        "QPushButton { background-color: #E74C3C; color: white; border: none; padding: 10px 20px; text-align: center; text-decoration: none; display: inline-block; font-size: 11px; margin: 4px 2px; cursor: pointer; border-radius: 12px; transition: background-color 0.3s ease; }"
        "QPushButton:hover { background-color: #C0392B; }"
        "QLineEdit { border: 2px solid #BDC3C7; border-radius: 4px; padding: 5px; font-size: 14px; color: #000000; }"
        "QRadioButton { color: #2C3E50; font-size: 14px; }"
        "QCheckBox { color: #2C3E50; font-size: 14px; }"
        "QComboBox { border: 2px solid #BDC3C7; border-radius: 4px; padding: 5px; font-size: 14px; color: #2C3E50; background-color: #FAF3F3; }"
        "QComboBox QAbstractItemView { background-color: #FAF3F3; color: #2C3E50; selection-background-color: #E74C3C; selection-color: white; border: 1px solid #BDC3C7; }"
        "QComboBox QAbstractItemView::item { min-height: 25px; }"
        "QTabWidget::pane { border: 1px solid #BDC3C7; background: #FAF3F3; }"
        "QTabBar::tab { background: #E74C3C; color: white; padding: 10px; border: 1px solid #BDC3C7; border-top-left-radius: 4px; border-top-right-radius: 4px; }"
        "QTabBar::tab:selected, QTabBar::tab:hover { background: #C0392B; }"
        "QScrollBar:vertical { border: 1px solid #BDC3C7; background: #FAF3F3; width: 15px; margin: 15px 3px 15px 3px; }"
        "QScrollBar::handle:vertical { background: #E74C3C; min-height: 20px; border-radius: 4px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: #FAF3F3; border: 1px solid #BDC3C7; height: 15px; subcontrol-origin: margin; }"
        "QScrollBar::add-line:vertical:hover, QScrollBar::sub-line:vertical:hover { background: #C0392B; }";

    a.setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
