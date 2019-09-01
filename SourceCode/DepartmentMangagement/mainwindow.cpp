#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using namespace std;
#include "datatype.h"

extern DEPARTL1_T DEPARTL1_T_Linked;
extern STAFFTABLE_T STAFFTABLE_T_Linked;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*button for "插入部门"*/

    //新建一个窗口对象
    dialog_insertdepartnew = new Dialog_InsertDepartNew(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_insertdepartnew->setModal(false);
    dialog_insertdepartnew->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    /*button for "删除部门"*/
    //新建一个窗口对象
    dialog_deletedepart = new Dialog_deletedepart(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_deletedepart->setModal(false);
    dialog_deletedepart->show();
}



void MainWindow::on_pushButton_3_clicked()
{
    /*button for "显示部门"*/
    /*新建对象*/
    dialog_showdepart = new Dialog_ShowDepart(this);

    dialog_showdepart->show();



}

void MainWindow::on_pushButton_4_clicked()
{
    /*button for "添加人员"*/
    //新建一个窗口对象
    dialog_insertstaff = new Dialog_InsertStaff(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_insertstaff->setModal(false);
    dialog_insertstaff->show();

}



void MainWindow::on_pushButton_5_clicked()
{
    /*button for显示人员*/
    dialog_showstaff =  new Dialog_ShowStaff(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_showstaff->setModal(false);
    dialog_showstaff->show();

}



void MainWindow::on_pushButton_6_clicked()
{
    /*button for定义职位*/
    dialog_definejob =  new Dialog_DefineJob(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_definejob->setModal(false);
    dialog_definejob->show();



}

void MainWindow::on_pushButton_7_clicked()
{
    /*button for "查找人员职位信息"*/
    dialog_searchjob =  new Dialog_SearchJob(this);

    //modal属性确定了show弹出的窗口应该为模态还是非模态
    dialog_searchjob->setModal(false);
    dialog_searchjob->show();
}
