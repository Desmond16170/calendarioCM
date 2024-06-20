#ifndef DATESELECTIONDIALOG_H
#define DATESELECTIONDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DateSelectionDialog;
}

class DateSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateSelectionDialog(QWidget *parent = nullptr);
    ~DateSelectionDialog();

    QDate getSelectedDate() const;

private slots:
    void BotonAnterior_2_clicked();
    void BotonSiguiente_2_clicked();
    void botonVolver_2_clicked();
    void buttonBox_accepted();

private:
    Ui::DateSelectionDialog *ui;
    QDate selectedDate;
};

#endif // DATESELECTIONDIALOG_H

