#include "dateinputdialog.h"

DateInputDialog::DateInputDialog(QWidget *parent) :
    QDialog(parent),
    calendar(new QCalendarWidget(this)),
    buttonBox(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(calendar);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

QDate DateInputDialog::getSelectedDate() const
{
    return calendar->selectedDate();
}
