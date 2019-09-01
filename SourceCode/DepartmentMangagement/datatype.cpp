

#include "datatype.h"
#include "alert.h"
#include <iostream>



//由于删除涉及到人员与部门之间的约束关系，比添加要复杂一些

//操作的粒度定义在可人为增/减部门、人员；可人为定义(/解雇)人员的职位

//要考虑各类职员人数的约束(仅有一个约束，主管人数不超过1个)

/*
初始化L1,L2 department
*/
bool L1L2DEPART_Init(DEPARTL1_T& DEPARTL1_T_Linked) {
    DEPARTL1_T_Linked = new DEPARTL1;
    if (NULL == DEPARTL1_T_Linked) {
        errorAlertion(0, "L1L2DEPART_Init");
        //cout << "申请失败NULL, at  L1L2DEPART_Init" << endl;
        return false;
    }

    for (int i = 0; i < L2NUM; i++) {
        DEPARTL1_T_Linked->level2Depart[i] = new DEPARTL2;
        if (DEPARTL1_T_Linked->level2Depart[i] == NULL) {
            errorAlertion(0, "L1L2DEPART_Init");
            //cout << "申请失败NULL, at  L1L2DEPART_Init" << endl;
            return false;
        }
        L2DEPART_Init(DEPARTL1_T_Linked->level2Depart[i], L2NameArr[i]);
    }
    return true;
}

/*
初始化L2 department
*/
bool L2DEPART_Init(DEPARTL2_T& DEPARTL2_T_Linked, string l2Name) {
    DEPARTL2_T_Linked->level2DepartName = l2Name;	//大类机构名
    DEPARTL2_T_Linked->subDepartNum = 0;	//下辖机构数初始化为0
    DEPARTL2_T_Linked->level2DepartHead = NULL;		//链表头暂时指向NULL
    return true;
}


/*
添加机构
*/
bool DEPARTNODE_addNode(
    DEPARTL1_T DEPARTL1_T_Linked,
    string L2DepartName_t,	//所属大类机构的名称
    string subDepartName	//待添加的机构的具体名称
    ) {
    bool fit = false;
    int chosenL2_index = L2NUM;	//所属的大类机构的坐标
    for (int i = 0; i < L2NUM; i++) {
        if (L2DepartName_t == L2NameArr[i]) {
            fit = true;
            chosenL2_index = i;
            break;
        }
    }// end for i
    if (false == fit) {
        errorAlertion(1, "DEPARTNODE_addNode");
        return false;
    }


    //判断该部门结点是否已经被重复添加
    if (NULL != DEPARTNODEL2_searchByName(DEPARTL1_T_Linked->level2Depart[chosenL2_index], subDepartName)){
        return false;
    }



    //申请department结点
    DEPARTNODE_T DEPARTNODE_T_new = new DEPARTNODE;
    if (NULL == DEPARTNODE_T_new) {
        errorAlertion(0, "DEPARTNODE_addNode");
        return false;
    }

    //对新申请的department结点进行基本赋值
    DEPARTNODE_T_new->departName = subDepartName;
    DEPARTNODE_T_new->departStaffNum = 0;	//部门员工数暂为0
    DEPARTNODE_T_new->headNum = 0;		//部门中的主管数暂时定为0
    DEPARTNODE_T_new->departStaffPointer = NULL;	//员工卡链表暂时为NULL

    //采用头插法把departnode结点安置到L2depart上
    DEPARTNODE_T_new->nextDepartNode = DEPARTL1_T_Linked->level2Depart[chosenL2_index]->level2DepartHead;
    DEPARTL1_T_Linked->level2Depart[chosenL2_index]->level2DepartHead = DEPARTNODE_T_new;

    //顶层机构下辖机构数+1
    DEPARTL1_T_Linked->level2Depart[chosenL2_index]->subDepartNum++;

    return true;
}





/*
初始化人员table
要在调用函数之前先  = NULL
*/
bool STAFFTABLE_Init(STAFFTABLE_T& STAFFTABLE_T_Linked) {
    STAFFTABLE_T_Linked = new STAFFTABLE;
    if (NULL == STAFFTABLE_T_Linked) {
        errorAlertion(0, "STAFFTABLE_Init");
        return false;
    }

    STAFFTABLE_T_Linked->staffNum = 0;	//人员总数暂时设定为0
    STAFFTABLE_T_Linked->tableHead = NULL;		//人员链表表头暂时置为0
    return true;
}


/*
向人员表中添加人员
*/
bool STAFFTABLE_addStaffNode(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffID_par,
    string staffName_par,
    int staffSexTag_par,
    int staffAge_par
) {
    STAFFNODE_T STAFFNODE_T_new = new STAFFNODE;
    if (NULL == STAFFNODE_T_new) {
        errorAlertion(0, "STAFFTABLE_addStaffNode");
        return false;
    }
    if ((NULL != STAFFTABLE_searchByID(STAFFTABLE_T_Linked, staffID_par))
        || (NULL != STAFFTABLE_searchByName(STAFFTABLE_T_Linked, staffName_par))) {
        //姓名 or ID与表中已经存在的信息发生了冲突
        errorAlertion(2, "STAFFTABLE_addStaffNode");
        return false;
    }

    //对新申请的staffnode结点进行赋值
    STAFFNODE_T_new->staffName = staffName_par;
    STAFFNODE_T_new->staffID = staffID_par;
    STAFFNODE_T_new->staffSexTag = staffSexTag_par;
    STAFFNODE_T_new->staffAge = staffAge_par;
    STAFFNODE_T_new->namecardLinkedList = NULL;		//名片链表的头结点暂时置为NULL

    //采用头插法把staffnode结点安置到staffhead上
    STAFFNODE_T_new->nextStaffNode = STAFFTABLE_T_Linked->tableHead;
    STAFFTABLE_T_Linked->tableHead = STAFFNODE_T_new;

    //人员表的总数+1
    STAFFTABLE_T_Linked->staffNum++;

    return true;
}



/*
向人员表发起查询,by name
    未查找到则返回NULL
*/
STAFFNODE_T STAFFTABLE_searchByName(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffName_par
) {
    STAFFNODE_T head = STAFFTABLE_T_Linked->tableHead;
    while (NULL != head) {
        if (staffName_par == head->staffName) {
            return head;	//查找成功，返回该指针
        }
        head = head->nextStaffNode;
    }
    return NULL;
}


/*
向人员表发起查询,by ID
    未查找到则返回NULL
*/
STAFFNODE_T STAFFTABLE_searchByID(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    string staffID_par
) {
    STAFFNODE_T head = STAFFTABLE_T_Linked->tableHead;
    while (NULL != head) {
        if (staffID_par == head->staffID) {
            return head;	//查找成功，返回该指针
        }
        head = head->nextStaffNode;
    }
    return NULL;
}


/*
向部门表L1发起查询，by name
    未查找到则返回NULL
*/
DEPARTNODE_T DEPARTNODEL1_searchByName(
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par
) {
    DEPARTNODE_T departnode_srchRslt = NULL;
    for (int i = 0; i < L2NUM; i++) {
        departnode_srchRslt = DEPARTNODEL2_searchByName(DEPARTL1_T_Linked->level2Depart[i], departName_par);
        if (NULL != departnode_srchRslt) {
            //顺利找到，返回
            return departnode_srchRslt;
        }

    }// end for i

    //在5个大类中均没有顺利找到，返回NULL
    return NULL;
}


/*
向部门表L2发起查询， by name
    未找到则返回NULL
*/
DEPARTNODE_T DEPARTNODEL2_searchByName(
    DEPARTL2_T DEPARTL2_T_Linked,
    string departName_par
) {
    DEPARTNODE_T head = DEPARTL2_T_Linked->level2DepartHead;
    while (NULL != head) {
        if (departName_par == head->departName) {
            //顺利找到，返回
            return head;
        }
        head = head->nextDepartNode;
    }

    //在这个大类中没有成功找到，返回NULL
    return NULL;
}




/*
为人员定义职位
    是综合操作
    分为：
        为人员结点定义名片卡
            STAFFNODE_defineNameCard
        为部门结点定义员工卡
            DEPARTSTAFF_addCard
*/
bool COMPOSITE_defineJob(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par,
    string staffName_par
) {
    //找到人员结点
    STAFFNODE_T STAFFNODE_T_new = STAFFTABLE_searchByName(STAFFTABLE_T_Linked, staffName_par);
    if (NULL == STAFFNODE_T_new) {
        //查找人员结点失败
        errorAlertion(3, "COMPOSITE_defineJob");
        return false;
    }

    //更好的方法是在这个函数体中也找到部门结点

    //为人员结点定义名片卡
    if (STAFFNODE_defineNameCard(
        STAFFNODE_T_new,
        DEPARTL1_T_Linked,
        departName_par,
        positionTag_par
    )) {
        //为部门结点定义员工卡
        return 	//为部门结点定义员工卡
            DEPARTSTAFF_addCard(
                STAFFNODE_T_new,
                DEPARTL1_T_Linked,
                departName_par,
                positionTag_par
            );
    }
    else {
        return false;
    }
}




/*
为人员结点定义名片卡
*/
bool STAFFNODE_defineNameCard(
    STAFFNODE_T STAFFNODE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par
) {
    NAMECARD_T NAMECARD_T_new = new NAMECARD;
    if (NULL == NAMECARD_T_new) {
        errorAlertion(0, "STAFFNODE_defineNameCard");
        return false;
    }

    //对新申请到的namecard结点进行赋值
    NAMECARD_T_new->departName = departName_par;
    NAMECARD_T_new->positionTag = positionTag_par;

    //依据部门名称进行搜索
    DEPARTNODE_T DEPARTNODE_T_new = DEPARTNODEL1_searchByName(DEPARTL1_T_Linked, departName_par);
    if (NULL == DEPARTNODE_T_new) {
        //查找失败，返回NULL
        errorAlertion(3, "STAFFNODE_defineNameCard");
        return false;
    }

    //名片上指向具体部门
    NAMECARD_T_new->departPointer = DEPARTNODE_T_new;

    //若部门中已经有主管，再添加主管时，添加将失败
    if ((0 != DEPARTNODE_T_new->headNum) && (positionTag_par == HEAD_POSITION)) {
        //不满足人数约束，添加失败
        errorAlertion(4, "STAFFNODE_defineNameCard");
        return false;
    }
    DEPARTNODE_T_new->headNum++;

    //采用头插法把名片添加到人员卡上
    NAMECARD_T_new->nextNameCard = STAFFNODE_T_Linked->namecardLinkedList;
    STAFFNODE_T_Linked->namecardLinkedList = NAMECARD_T_new;

    //名片卡添加成功
    return true;
}


/*
删除部门
*/
bool DEPARTNODE_deleteNode(
    DEPARTL1_T DEPARTL1_T_Linked,
    string subDepartName,	//待删除的机构的具体名称
    STAFFTABLE_T STAFFTABLE_T_Linked	//人员表，方便删除人员的名片卡
)//删除部门，难点在于要关联地删除掉人员的职位信息
{
    bool findTag = false;
    DEPARTNODE_T head = NULL;
    for (int i = 0; i < L2NUM; i++) {
        if (NULL == DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead) {
            continue;
        }

        head = DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead;
        DEPARTNODE_T former = NULL;


        if (NULL != head) {
            /*第一个就是待删除的*/
            if (head->departName == subDepartName) {
                findTag = true;
                DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead = head->nextDepartNode;
                break;
            }

            /*待删除的并非是第一个*/
            former = head;
            head = head->nextDepartNode;
            while (NULL != head) {
                if (head->departName == subDepartName) {
                    findTag = true;
                    former->nextDepartNode = head->nextDepartNode;
                    break;
                }
                else {
                    former = head;
                    head = head->nextDepartNode;
                }
            }
            if (findTag == true) {
                break;
            }
        }


    }
    if (findTag == false) {
        errorAlertion(233, "DEPARTNODE_deleteNode");
        return false;
    }

    /*此时待删除的结点已经从链表脱钩，为head*/
    /*依据名片卡依次删去职位信息*/
    DEPARTSTAFF_T workCardHead = head->departStaffPointer;
    while (NULL != workCardHead) {
        string staffID_t = workCardHead->staffID;
        STAFFNODE_T STAFFNODE_T_u = STAFFTABLE_searchByID(STAFFTABLE_T_Linked ,staffID_t);
        if (NULL == STAFFNODE_T_u) {
            //并没有匹配的ID
            errorAlertion(3, "DEPARTNODE_deleteNode");
        }
        NAMECARD_T NAMECARD_T_u = STAFFNODE_T_u->namecardLinkedList;
        /*第一个就是待删除的*/
        if (NULL != NAMECARD_T_u) {
            if (NAMECARD_T_u->departName == subDepartName) {
                STAFFNODE_T_u->namecardLinkedList = NAMECARD_T_u->nextNameCard;
                NAMECARD_T_u = STAFFNODE_T_u->namecardLinkedList;
                continue;
                //break;
            }
            NAMECARD_T NAMECARD_former = NAMECARD_T_u;
            NAMECARD_T_u = NAMECARD_T_u->nextNameCard;
            while (NULL != NAMECARD_T_u) {
                if (NAMECARD_T_u->departName == subDepartName) {
                    NAMECARD_former->nextNameCard = NAMECARD_T_u->nextNameCard;
                    /*释放名片卡内存*/
                    delete NAMECARD_T_u;

                    NAMECARD_former = NAMECARD_T_u;
                    NAMECARD_T_u = NAMECARD_T_u->nextNameCard;
                }
            }

        }



        workCardHead = workCardHead->nextDepartStaff;
    }

    /*释放部门卡片内存*/
    delete head;
    return true;
}


/*
为部门结点定义员工卡
在具体部门的基础上，添加员工卡
    人员的基本信息来自员工结点，不再显式传入
    部门的结点位置来自于人员结点上，不再显式传入
*/
bool DEPARTSTAFF_addCard(
    STAFFNODE_T STAFFNODE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string departName_par,
    int positionTag_par
) {
    //依据部门名称进行搜索
    DEPARTNODE_T DEPARTNODE_T_new = DEPARTNODEL1_searchByName(DEPARTL1_T_Linked, departName_par);
    if (NULL == DEPARTNODE_T_new) {
        //查找失败，返回NULL
        errorAlertion(3, "DEPARTSTAFF_addCard");
        return false;
    }

    DEPARTSTAFF_T DEPARTSTAFF_T_new = new DEPARTSTAFF;
    if (NULL == DEPARTSTAFF_T_new) {
        //申请空间失败
        errorAlertion(0, "DEPARTSTAFF_addCard");
        return false;
    }

    //完善新申请空间的数据域
    DEPARTSTAFF_T_new->staffID = STAFFNODE_T_Linked->staffID;
    DEPARTSTAFF_T_new->positionTag = positionTag_par;

    //头插法
    DEPARTSTAFF_T_new->nextDepartStaff = DEPARTNODE_T_new->departStaffPointer;
    DEPARTNODE_T_new->departStaffPointer = DEPARTSTAFF_T_new;

    return true;
}




/*综合查询*/
void COMPOSITE_search(
    STAFFTABLE_T STAFFTABLE_T_Linked,
    DEPARTL1_T DEPARTL1_T_Linked,
    string staffName_par
) {
    /*根据姓名在人员表中找到staffnode*/
        //找到人员结点
    STAFFNODE_T STAFFNODE_T_new = STAFFTABLE_searchByName(STAFFTABLE_T_Linked, staffName_par);
    if (NULL == STAFFNODE_T_new) {
        //查找人员结点失败
        errorAlertion(3, "COMPOSITE_defineJob");
        return;
    }

    /*打印基本信息*/
    show_basicInfo(STAFFNODE_T_new);

    /*打印职位信息*/
    NAMECARD_T head = STAFFNODE_T_new->namecardLinkedList;
    while (NULL != head) {
        show_COMPOSITE_search_result(head);
        head = head->nextNameCard;
    }
}




/*打印基本信息*/
void show_basicInfo(STAFFNODE_T STAFFNODE_T_Linked) {
    string gender = (STAFFNODE_T_Linked->staffSexTag == MALE) ? "男" : "女";


    cout << endl << "人员基本信息" << endl;
    cout << "姓名：" << STAFFNODE_T_Linked->staffName << endl
        << "ID号：" << STAFFNODE_T_Linked->staffID << endl
        << "性别：" << gender << endl
        << "年龄：" << STAFFNODE_T_Linked->staffAge << endl;
}


/*打印职位信息*/
void show_COMPOSITE_search_result(NAMECARD_T NAMECARD_T_Linked) {
    string positionName;

    switch(NAMECARD_T_Linked->positionTag) {
    case HEAD_POSITION: {
        positionName = "部门主管";
        break;
    }
    case VICE_POSITION: {
        positionName = "主管副职";
        break;
    }
    case OTHER_POSITION: {
        positionName = "其他人员";
        break;
    }
    }
    cout << "职位信息" << endl;
    cout << "部门名称：" << NAMECARD_T_Linked->departName << endl
        << "部门职位：" << positionName << endl;
}


/*显示部门*/
void show_DEPART(DEPARTL1_T DEPARTL1_T_Linked) {
    cout << "各部门情况显示如下" << endl;
    for (int i = 0; i < L2NUM; i++) {
        cout << L2NameArr[i] << ":" << endl;
        DEPARTNODE_T head = DEPARTL1_T_Linked->level2Depart[i]->level2DepartHead;
        while (NULL != head) {
            cout << head->departName << endl;
            head = head->nextDepartNode;
        }
        cout << "end" << endl;
    }
}

/*显示人员表单*/
void show_STAFF(STAFFTABLE_T STAFFTABLE_T_Linked) {
    cout << "人员表单显示如下" << endl;
    STAFFNODE_T head = STAFFTABLE_T_Linked->tableHead;
    while (NULL != head) {
        cout << "姓名：" << head->staffName
            << " ID： " << head->staffID << endl;
        head = head->nextStaffNode;
    }
    cout << "end" << endl;
}





