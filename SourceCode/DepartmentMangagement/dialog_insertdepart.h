#ifndef DIALOG_INSERTDEPART_H
#define DIALOG_INSERTDEPART_H

#include <QDialog>
#include <string>
using namespace std;
#include "dialog_successalert.h"
#include "dialog_failalert.h"

namespace Ui {
class Dialog_InsertDepart;
}

class Dialog_InsertDepart : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_InsertDepart(QWidget *parent = nullptr);
    ~Dialog_InsertDepart();
    int getComboBoxIndex();
    string getDepartName();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog_InsertDepart *ui;
    Dialog_SuccessAlert* dialog_successalert;
    Dialog_FailAlert* dialog_failalert;
};

#endif // DIALOG_INSERTDEPART_H
