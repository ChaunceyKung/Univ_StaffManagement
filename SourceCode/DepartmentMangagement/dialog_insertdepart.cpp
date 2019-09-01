#include "dialog_insertdepart.h"
#include "ui_dialog_insertdepart.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;


Dialog_InsertDepart::Dialog_InsertDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_InsertDepart)
{
    ui->setupUi(this);
}


Dialog_InsertDepart::~Dialog_InsertDepart()
{
    delete ui;
}


int Dialog_InsertDepart::getComboBoxIndex()
{
    return ui->comboBox->currentIndex();
}

string Dialog_InsertDepart::getDepartName(){
    //通过 toStdString 将 QString转换为String
    return ui->lineEdit->text().toStdString();
}

void Dialog_InsertDepart::on_buttonBox_accepted()
{
    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert = new Dialog_FailAlert(this);

    /*调用插入部门的函数*/
    if(DEPARTNODE_addNode(DEPARTL1_T_Linked, L2NameArr[this->getComboBoxIndex()], this->getDepartName())){
        dialog_successalert->show();
        //关闭窗口
        this->close();
    }else{
        dialog_failalert->show();
    }
}

void Dialog_InsertDepart::on_buttonBox_rejected()
{
    this->close();
}
