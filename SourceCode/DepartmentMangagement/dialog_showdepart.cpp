#include "dialog_showdepart.h"
#include "ui_dialog_showdepart.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_ShowDepart::Dialog_ShowDepart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ShowDepart)
{
    ui->setupUi(this);

    /*设置表格数据*/
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"顶层机构"<<"部门名称");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个

    /*得先遍历一遍确定表格行数*/
    int row_num = 0;
    for(int i = 0; i < L2NUM; i++){
        DEPARTNODE_T head2 = DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead;
        while (NULL != head2) {
            head2 = head2->nextDepartNode;
            row_num++;
        }
    }
    //设置表格行数
    ui->tableWidget->setRowCount(row_num);

    /*根据数据结构内容具体添加数据*/
    int row_count = 0;
    for(int i = 0; i < L2NUM; i++){
        DEPARTNODE_T head = DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead;
        while (NULL != head) {
            /*填入顶层机构*/
            /*注意 string -> QString*/
            ui->tableWidget->setItem(row_count,0, new QTableWidgetItem(QString::fromStdString(L2NameArr[i]))  );
            ui->tableWidget->setItem(row_count,1, new QTableWidgetItem(QString::fromStdString(head->departName))  );
            head = head->nextDepartNode;
            row_count++;
        }
    }
}

Dialog_ShowDepart::~Dialog_ShowDepart()
{
    delete ui;
}
