#include "dialog_deletedepart.h"
#include "ui_dialog_deletedepart.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;


Dialog_deletedepart::Dialog_deletedepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_deletedepart)
{
    ui->setupUi(this);
}

Dialog_deletedepart::~Dialog_deletedepart()
{
    delete ui;
}

void Dialog_deletedepart::on_buttonBox_accepted()
{
    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert = new Dialog_FailAlert(this);
    /*获取待删除部门的名称*/
    string deletedNameStr = ui->lineEdit->text().toStdString() ;
    if(DEPARTNODE_deleteNode(DEPARTL1_T_Linked,deletedNameStr , STAFFTABLE_T_Linked)){
        /*提示删除成功*/
        dialog_successalert->show();
        this->close();
    }else{
        /*提示删除失败*/
        dialog_failalert->show();
    }
}

void Dialog_deletedepart::on_buttonBox_rejected()
{
    this->close();
}
