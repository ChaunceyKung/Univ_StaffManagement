#include "form_showdepart.h"
#include "ui_form_showdepart.h"

Form_ShowDepart::Form_ShowDepart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ShowDepart)
{
    ui->setupUi(this);

    /*设置表格数据*/
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"顶层机构"<<"部门名称");


    /*根据数据结构内容具体添加数据*/



}

Form_ShowDepart::~Form_ShowDepart()
{
    delete ui;
}
