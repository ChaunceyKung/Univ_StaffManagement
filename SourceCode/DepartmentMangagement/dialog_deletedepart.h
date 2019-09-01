#ifndef DIALOG_DELETEDEPART_H
#define DIALOG_DELETEDEPART_H

#include <QDialog>
#include "dialog_successalert.h"
#include "dialog_failalert.h"


namespace Ui {
class Dialog_deletedepart;
}

class Dialog_deletedepart : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_deletedepart(QWidget *parent = nullptr);
    ~Dialog_deletedepart();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_deletedepart *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_DELETEDEPART_H
