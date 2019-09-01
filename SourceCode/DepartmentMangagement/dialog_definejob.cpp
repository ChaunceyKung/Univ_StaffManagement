#include "dialog_definejob.h"
#include "ui_dialog_definejob.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_DefineJob::Dialog_DefineJob(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_DefineJob)
{
    ui->setupUi(this);
}

Dialog_DefineJob::~Dialog_DefineJob()
{
    delete ui;
}

void Dialog_DefineJob::on_buttonBox_accepted()
{
    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert = new Dialog_FailAlert(this);

    string staffName, deptName;
    staffName = (ui->lineEdit->text()).toStdString();
    deptName = (ui->lineEdit_2->text()).toStdString();
    int positionTag = ui->comboBox->currentIndex();

    if(COMPOSITE_defineJob(STAFFTABLE_T_Linked, DEPARTL1_T_Linked, deptName, positionTag, staffName ) ){
        dialog_successalert->show();
        this->close();
    }else{
        dialog_failalert->show();
    }
}

void Dialog_DefineJob::on_buttonBox_rejected()
{
    this->close();
}
