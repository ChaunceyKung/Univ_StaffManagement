#ifndef DATATYPE_H
#define DATATYPE_H

#pragma once
#include <string>
using namespace std;
//设计理念，人员表和组织结构表上同一信息存两份，存在冗余防止出错

#define HEAD_POSITION 0
#define VICE_POSITION 1
#define OTHER_POSITION 2

#define MALE 0
#define FEMALE 1

#define L2NUM 5

const string L2NameArr[L2NUM] = {
    "学院",
    "党群组织",
    "行政机构",
    "直属单位",
    "附属单位"
};

/*总的人员表
由长长的人员结点链表组成（方便删除人员）
*/
struct staff_table;
typedef staff_table STAFFTABLE;
typedef staff_table* STAFFTABLE_T;

/*人员结点
 由长长的名片结点链表组成（方便删除身份）
*/
struct staff_node;
typedef staff_node STAFFNODE;
typedef staff_node* STAFFNODE_T;

/*身份结点
 储存一种身份信息，并指向底层部门结点（注意不是部门下辖的人员结点），
    方便部门那边的同步删除
*/
struct name_card;
typedef name_card NAMECARD;
typedef name_card* NAMECARD_T;


/*总的部门表
    下辖5个L2，分别是学院、党群组织、行政机构、直属单位、附属单位
    基本不会变，可用数组定死
*/
struct departl1;
typedef departl1 DEPARTL1;
typedef departl1* DEPARTL1_T;

/*部门类别表
    依然存在，不需再创建
*/
struct departl2;
typedef departl2 DEPARTL2;
typedef departl2* DEPARTL2_T;

/*具体部门结点
    需要手动输入创建

*/
struct depart_node;
typedef depart_node DEPARTNODE;
typedef depart_node* DEPARTNODE_T;


/*部门人事
    具有一定的冗余性，
    组成链表插在具体部门上
*/
struct depart_staff;
typedef depart_staff DEPARTSTAFF;
typedef depart_staff* DEPARTSTAFF_T;


/*
struct departhead;
typedef departhead DEPARTHEAD;
typedef departhead* DEPARTHEAD_T;

struct departvice;
typedef departvice DEPARTVICE;
typedef departvice* DEPARTVICE_T;
*/


/*
该完成的基本在staff_node内完成了，
此处主要负责存储一些辅助信息
*/
struct staff_table {
    int staffNum;
    STAFFNODE_T tableHead;	//人员链表（头插法）
};


struct staff_node {
    string staffID;		//primary key:"1653633"七位
    string staffName;
    int staffSexTag;
    int staffAge;
    NAMECARD_T namecardLinkedList;
    STAFFNODE_T nextStaffNode;
};


struct name_card {
    string departName;
    int positionTag;
    DEPARTNODE_T departPointer;	//Point towards specific department
    NAMECARD_T nextNameCard;	//指向下一个名片结点
};


struct departl1 {
    DEPARTL2_T level2Depart[L2NUM] = {NULL};
};

struct departl2 {
    string level2DepartName;	//顶层机构的名称（有5个）
    int subDepartNum;	//下属具体机构的数目
    DEPARTNODE_T level2DepartHead;	//指向子部门链表的指针(采用头插法)
};

struct depart_node {
    string departName;	//具体部门的名称，如“电子与信息工程学院”
    int departStaffNum;	 //该部门所拥有的员工数目
    DEPARTSTAFF_T departStaffPointer; //表头，链表指向部门员工的工作卡
    DEPARTNODE_T nextDepartNode;	//指向下一个具体的部门结点
    int headNum;	//该部门所拥有的主管数目，如果已经为1，则不能再添加主管
};


struct depart_staff {
    string staffID;	//不再链接到人员Node，而是根据ID在table中找
    int positionTag;
    DEPARTSTAFF_T nextDepartStaff;	//指向下一个员工的工作卡
};


/*部门基本操作*/
bool L1L2DEPART_Init(DEPARTL1_T& DEPARTL1_T_Linked);
bool L2DEPART_Init(DEPARTL2_T& DEPARTL2_T_Linked, string l2Name);
bool DEPARTNODE_addNode(
    DEPARTL1_T DEPARTL1_T_Linked,
    string L2DepartName_t,	//所属大类机构的名称
    string subDepartName	//待添加的机构的具体名称
);
bool DEPARTNODE_deleteNode(
    DEPARTL1_T DEPARTL1_T_Linked,
    string subDepartName,	//待删除的机构的具体名称
    STAFFTABLE_T STAFFTABLE_T_Linked	//人员表，方便删除人员的名片卡
);//删除部门，难点在于要关联地删除掉人员的职位信息
bool DEPARTSTAFF_addCard(
    STAFFNODE_T STAFFNODE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par
);



/*人员基本操作*/
bool STAFFTABLE_Init(STAFFTABLE_T& STAFFTABLE_T_Linked);
bool STAFFTABLE_addStaffNode(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffID_par,
    string staffName_par,
    int staffSexTag_par,
    int staffAge_par
);
bool STAFFNODE_defineNameCard(
    STAFFNODE_T STAFFNODE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par
);



/*涉及两张表的综合操作*/
bool COMPOSITE_defineJob(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par,
    string staffName_par
);




/*查询相关*/
//人员查询
STAFFNODE_T STAFFTABLE_searchByName(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffName_par
);

STAFFNODE_T STAFFTABLE_searchByID(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffID_par
);

//部门查询
DEPARTNODE_T DEPARTNODEL1_searchByName(
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par
);
DEPARTNODE_T DEPARTNODEL2_searchByName(
    DEPARTL2_T DEPARTL2_T_Linked,
    string departName_par
);

//综合查询
/*为满足（3）的要求：
    根据输入的人员名，
    查找其所在部门、职位等信息
*/
void COMPOSITE_search(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string staffName_par
);

/*在图形界面下，以下函数需要被改写*/
void show_basicInfo(STAFFNODE_T STAFFNODE_T_Linked);

void show_COMPOSITE_search_result(NAMECARD_T NAMECARD_T_Linked);

void show_DEPART(DEPARTL1_T DEPARTL1_T_Linked);

void show_STAFF(STAFFTABLE_T STAFFTABLE_T_Linked);





#endif // DATATYPE_H
