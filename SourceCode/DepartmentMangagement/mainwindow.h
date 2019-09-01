#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog_insertdepart.h"
#include "dialog_insertdepartnew.h"
#include "dialog_deletedepart.h"
#include "dialog_showdepart.h"
#include "dialog_insertstaff.h"
#include "dialog_showstaff.h"
#include "dialog_definejob.h"
#include "dialog_searchjob.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    //添加私有成员，为一个dialog窗口的指针
    Dialog_InsertDepart *dialog_insertdepart;   //插入部门所新定义的窗口
    Dialog_InsertDepartNew *dialog_insertdepartnew;
    Dialog_deletedepart *dialog_deletedepart;   //删除部门所新定义的窗口
    Dialog_ShowDepart *dialog_showdepart;       //显示部门所新定义的窗口
    Dialog_InsertStaff *dialog_insertstaff;     //插入部门所新定义的窗口
    Dialog_ShowStaff *dialog_showstaff;         //显示人员所定义的新窗口
    Dialog_DefineJob *dialog_definejob;         //定义职位所定义的新窗口
    Dialog_SearchJob *dialog_searchjob;         //查找人员职位所定义的新窗口

};

#endif // MAINWINDOW_H
