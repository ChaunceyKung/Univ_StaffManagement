#include "dialog_showstaff.h"
#include "ui_dialog_showstaff.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_ShowStaff::Dialog_ShowStaff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ShowStaff)
{
    ui->setupUi(this);

    /*设置表格数据*/
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"ID" << "性别" << "年龄");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个


    int row_num = 0;
    STAFFNODE_T head1 = STAFFTABLE_T_Linked->tableHead;
    while (NULL != head1) {
        row_num++;
        head1 = head1->nextStaffNode;
    }
    ui->tableWidget->setRowCount(row_num);

        /*根据数据结构内容具体添加数据*/
    int row_count = 0;
    STAFFNODE_T head = STAFFTABLE_T_Linked->tableHead;
    while (NULL != head) {
        /*填入人员信息*/
        /*注意 string -> QString*/
        ui->tableWidget->setItem(row_count,0, new QTableWidgetItem(QString::fromStdString(head->staffName))  );
        ui->tableWidget->setItem(row_count,1, new QTableWidgetItem(QString::fromStdString(head->staffID))  );
        QString sexQStr;
        if(head->staffSexTag == 0){
            sexQStr = "男";
        }else{
            sexQStr = "女";
        }
        ui->tableWidget->setItem(row_count,2, new QTableWidgetItem(sexQStr)  );
        ui->tableWidget->setItem(row_count,3, new QTableWidgetItem(QString::number(head->staffAge)));
        //int 通过QString::number()的方式转为QString
        head = head->nextStaffNode;
        row_count++;
    }
}

Dialog_ShowStaff::~Dialog_ShowStaff()
{
    delete ui;
}
