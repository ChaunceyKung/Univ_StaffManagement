#ifndef DIALOG_INSERTDEPARTNEW_H
#define DIALOG_INSERTDEPARTNEW_H

#include <QDialog>
#include <QDialog>
#include <string>
using namespace std;
#include "dialog_successalert.h"
#include "dialog_failalert.h"

namespace Ui {
class Dialog_InsertDepartNew;
}

class Dialog_InsertDepartNew : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_InsertDepartNew(QWidget *parent = nullptr);
    ~Dialog_InsertDepartNew();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_InsertDepartNew *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_INSERTDEPARTNEW_H
