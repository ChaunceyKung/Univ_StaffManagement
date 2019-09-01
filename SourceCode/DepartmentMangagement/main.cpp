#include "mainwindow.h"
#include <QApplication>
#include "datatype.h"



DEPARTL1_T DEPARTL1_T_Linked = NULL;
STAFFTABLE_T STAFFTABLE_T_Linked = NULL;


int main(int argc, char *argv[])
{
    /*UI define*/
    QApplication a(argc, argv);
    MainWindow w;

    /*对人员表和部门表的初始化*/
    if (L1L2DEPART_Init(DEPARTL1_T_Linked)
        && STAFFTABLE_Init(STAFFTABLE_T_Linked)) {
        /*UI show*/
        w.show();
    }



    return a.exec();
}
