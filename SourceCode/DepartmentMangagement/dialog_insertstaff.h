#ifndef DIALOG_INSERTSTAFF_H
#define DIALOG_INSERTSTAFF_H

#include <QDialog>
#include "dialog_successalert.h"
#include "dialog_failalert.h"

namespace Ui {
class Dialog_InsertStaff;
}

class Dialog_InsertStaff : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_InsertStaff(QWidget *parent = nullptr);
    ~Dialog_InsertStaff();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_InsertStaff *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_INSERTSTAFF_H
