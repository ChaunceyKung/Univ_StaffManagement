#include "dialog_searchjob.h"
#include "ui_dialog_searchjob.h"

#include "datatype.h"
extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

Dialog_SearchJob::Dialog_SearchJob(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SearchJob)
{
    ui->setupUi(this);
}

Dialog_SearchJob::~Dialog_SearchJob()
{
    delete ui;
}

void Dialog_SearchJob::on_pushButton_clicked()
{
    dialog_successalert = new Dialog_SuccessAlert(this);
    dialog_failalert =  new Dialog_FailAlert(this);

    string staffName_par = ui->lineEdit->text().toStdString();

    /*根据姓名在人员表中找到staffnode*/
        //找到人员结点
    STAFFNODE_T STAFFNODE_T_new = STAFFTABLE_searchByName(STAFFTABLE_T_Linked, staffName_par);
    if (NULL == STAFFNODE_T_new) {
        //查找人员结点失败
        //errorAlertion(3, "COMPOSITE_defineJob");
        dialog_failalert->show();
        return;
    }

    /*打印基本信息于Label上*/
    //姓名
    ui->label_7->setText(QString::fromStdString(STAFFNODE_T_new->staffName ));
    //ID
    ui->label_8->setText(QString::fromStdString(STAFFNODE_T_new->staffID ));
    //性别
    QString sexQStr;
    if(STAFFNODE_T_new->staffSexTag == MALE){
        sexQStr = "男";
    }else{
        sexQStr = "女";
    }
    ui->label_9->setText(sexQStr);
    //年龄
    QString ageQStr;
    ageQStr.setNum(STAFFNODE_T_new->staffAge);
    ui->label_10->setText(ageQStr);

    /*打印职位信息于table widget上*/
    /*设置表格数据*/
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"部门名称" << "担任职务");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个

    /*确定row number*/
    int row_num = 0;
    NAMECARD_T head1 = STAFFNODE_T_new->namecardLinkedList;
    while(NULL != head1){
        row_num++;
        head1 = head1->nextNameCard;
    }
    ui->tableWidget->setRowCount(row_num);

    /*打印职位信息*/
    int row_count = 0;
    NAMECARD_T head = STAFFNODE_T_new->namecardLinkedList;
    while (NULL != head) {
        ui->tableWidget->setItem(row_count,0, new QTableWidgetItem(QString::fromStdString(head->departName))  );
        QString positionQStr;
        switch (head->positionTag) {
        case HEAD_POSITION:{
            positionQStr = "部门主管";
            break;
        }
        case VICE_POSITION:{
            positionQStr = "部门副主管";
            break;
        }
        case OTHER_POSITION:{
            positionQStr = "其他人员";
            break;
        }
        default:{
            positionQStr = "其他人员";
            break;
        }
        }
        ui->tableWidget->setItem(row_count,1, new QTableWidgetItem(positionQStr)  );
        head = head->nextNameCard;
        row_count++;
    }

}
