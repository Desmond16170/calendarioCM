#include "dateselectiondialog.h"
#include "ui_dateselectiondialog.h"
#include "quiz_quedar_embarazada.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

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

DateSelectionDialog::~DateSelectionDialog()
{
    delete ui;
}

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

void DateSelectionDialog::buttonBox_accepted()
{
    int dia = ui->dayComboBox->currentText().toInt();
    int mes = ui->monthComboBox->currentText().toInt();
    int anio = ui->yearComboBox->currentText().toInt();
    selectedDate = QDate(anio, mes, dia);
}

QDate DateSelectionDialog::getSelectedDate() const
{
    return selectedDate;
}
