#ifndef DIALOG_SEARCHJOB_H
#define DIALOG_SEARCHJOB_H

#include <QDialog>
#include "dialog_successalert.h"
#include "dialog_failalert.h"

namespace Ui {
class Dialog_SearchJob;
}

class Dialog_SearchJob : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SearchJob(QWidget *parent = nullptr);
    ~Dialog_SearchJob();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_SearchJob *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_SEARCHJOB_H
