/**
 * @file dateselectiondialog.cpp
 * @authors Luis Fernando Herrera Vargas, Steven Chacón Salazar & Juan Jose
 * @title Diálogo de Selección de Fecha - Implementación
 * @brief Este archivo contiene la implementación de la clase DateSelectionDialog, que maneja la selección de fechas en la aplicación.
 * @version 1.3.3
 * @date 2024-06-25
 */

#include "dateselectiondialog.h"
#include "ui_dateselectiondialog.h"
#include "quiz_quedar_embarazada.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

/**
 * @brief Constructor de la clase DateSelectionDialog
 * @param parent Puntero al widget padre
 */
DateSelectionDialog::DateSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateSelectionDialog)
{
    ui->setupUi(this);

    // Configurar la pregunta en el QLabel
    ui->dateQuestionLabel->setText("¿Cuándo fue el primer día de tu último período?");

    // Inicializar los QComboBox para día, mes y año
    for (int i = 1; i <= 31; ++i) {
        ui->dayComboBox->addItem(QString::number(i));
    }
    for (int i = 1; i <= 12; ++i) {
        ui->monthComboBox->addItem(QString::number(i));
    }
    QDate currentDate = QDate::currentDate();
    for (int i = currentDate.year() - 10; i <= currentDate.year(); ++i) {
        ui->yearComboBox->addItem(QString::number(i));
    }

    // Conectar los botones a los slots
    connect(ui->BotonAnterior_2, &QPushButton::clicked, this, &DateSelectionDialog::BotonAnterior_2_clicked);
    connect(ui->BotonSiguiente_2, &QPushButton::clicked, this, &DateSelectionDialog::BotonSiguiente_2_clicked);
    connect(ui->botonVolver_2, &QPushButton::clicked, this, &DateSelectionDialog::botonVolver_2_clicked);
}

/**
 * @brief Destructor de la clase DateSelectionDialog
 */
DateSelectionDialog::~DateSelectionDialog()
{
    delete ui;
}

/**
 * @brief Slot llamado al hacer clic en el botón "Anterior"
 */
void DateSelectionDialog::BotonAnterior_2_clicked()
{
    qDebug() << "BotonAnterior_2_clicked called";
    // Lógica para regresar al cuestionario de embarazo
    Quiz_quedar_embarazada* quizWindow = qobject_cast<Quiz_quedar_embarazada*>(parent());
    if (quizWindow) {
        quizWindow->show();
    }
    // No cerrar la ventana actual
}

/**
 * @brief Slot llamado al hacer clic en el botón "Siguiente"
 */
void DateSelectionDialog::BotonSiguiente_2_clicked()
{
    qDebug() << "BotonSiguiente_2_clicked called";
    // Capturar la fecha seleccionada
    int dia = ui->dayComboBox->currentText().toInt();
    int mes = ui->monthComboBox->currentText().toInt();
    int anio = ui->yearComboBox->currentText().toInt();
    selectedDate = QDate(anio, mes, dia);

    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "Error", "Por favor selecciona una fecha válida.");
        return;
    }

    // Mostrar la pantalla de resultados
    Quiz_quedar_embarazada* quizWindow = qobject_cast<Quiz_quedar_embarazada*>(parent());
    if (quizWindow) {
        qDebug() << "Setting fechaInicioUltimoPeriodo";
        quizWindow->setFechaInicioUltimoPeriodo(selectedDate);
        quizWindow->mostrarResultado();
    } else {
        qDebug() << "quizWindow is null";
    }
    // Cerrar la ventana actual
    this->accept();
}

/**
 * @brief Slot llamado al hacer clic en el botón "Volver"
 */
void DateSelectionDialog::botonVolver_2_clicked()
{
    qDebug() << "botonVolver_2_clicked called";
    // Lógica para volver al menú principal
    QMainWindow* mainWindow = qobject_cast<QMainWindow*>(parentWidget()->parentWidget());
    if (mainWindow) {
        mainWindow->show();
    }
    // Cerrar la ventana actual
    this->accept();
}

/**
 * @brief Slot llamado al aceptar el cuadro de botones
 */
void DateSelectionDialog::buttonBox_accepted()
{
    int dia = ui->dayComboBox->currentText().toInt();
    int mes = ui->monthComboBox->currentText().toInt();
    int anio = ui->yearComboBox->currentText().toInt();
    selectedDate = QDate(anio, mes, dia);
}

/**
 * @brief Obtiene la fecha seleccionada por el usuario
 * @return La fecha seleccionada como un objeto QDate
 */
QDate DateSelectionDialog::getSelectedDate() const
{
    return selectedDate;
}
