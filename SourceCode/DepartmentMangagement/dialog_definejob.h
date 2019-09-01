#ifndef DIALOG_DEFINEJOB_H
#define DIALOG_DEFINEJOB_H

#include <QDialog>
#include "dialog_successalert.h"
#include "dialog_failalert.h"

namespace Ui {
class Dialog_DefineJob;
}

class Dialog_DefineJob : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DefineJob(QWidget *parent = nullptr);
    ~Dialog_DefineJob();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_DefineJob *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_DEFINEJOB_H
