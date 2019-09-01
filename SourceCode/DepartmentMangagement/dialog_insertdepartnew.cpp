#include "dialog_insertdepartnew.h"
#include "ui_dialog_insertdepartnew.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_InsertDepartNew::Dialog_InsertDepartNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_InsertDepartNew)
{
    ui->setupUi(this);
}

Dialog_InsertDepartNew::~Dialog_InsertDepartNew()
{
    delete ui;
}

void Dialog_InsertDepartNew::on_buttonBox_accepted()
{


    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert = new Dialog_FailAlert(this);

    /*调用插入部门的函数*/
    if(DEPARTNODE_addNode(DEPARTL1_T_Linked, L2NameArr[ui->comboBox->currentIndex()], ui->lineEdit->text().toStdString())){
        dialog_successalert->show();
        //关闭窗口
        this->close();
    }else{
        dialog_failalert->show();
    }
}

void Dialog_InsertDepartNew::on_buttonBox_rejected()
{
    this->close();
}
