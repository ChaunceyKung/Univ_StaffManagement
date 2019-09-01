#include "dialog_insertstaff.h"
#include "ui_dialog_insertstaff.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_InsertStaff::Dialog_InsertStaff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_InsertStaff)
{
    ui->setupUi(this);
}

Dialog_InsertStaff::~Dialog_InsertStaff()
{
    delete ui;
}


void Dialog_InsertStaff::on_buttonBox_accepted()
{
    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert =  new Dialog_FailAlert(this);

    string staffID, staffName;
    int sexTag, age;
    staffID = ui->lineEdit->text().toStdString();
    staffName = ui->lineEdit_2->text().toStdString();
    age = ui->lineEdit_3->text().toInt();
    sexTag = ui->comboBox->currentIndex();

    if(STAFFTABLE_addStaffNode(STAFFTABLE_T_Linked, staffID, staffName, sexTag, age)){
        /*提示添加成功*/
        dialog_successalert->show();
        this->close();
    }else{
        dialog_failalert->show();
    }
}

void Dialog_InsertStaff::on_buttonBox_rejected()
{
    this->close();
}
