#ifndef DATEINPUTDIALOG_H
#define DATEINPUTDIALOG_H

#include <QDialog>
#include <QCalendarWidget>
#include <QDialogButtonBox>
#include <QVBoxLayout>

class DateInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateInputDialog(QWidget *parent = nullptr);
    QDate getSelectedDate() const;

private:
    QCalendarWidget *calendar;
    QDialogButtonBox *buttonBox;
};

#endif // DATEINPUTDIALOG_H
