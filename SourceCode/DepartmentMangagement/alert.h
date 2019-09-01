#ifndef ALERT_H
#define ALERT_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

void errorAlertion(int errorType, string position) {
    switch (errorType) {
    case 0:{
        cerr << "申请失败NULL, at " << position << endl;;
        break;
    }
    case 1: {
        cerr << "插入信息不满足约束条件,插入失败, at " << position << endl;;
        break;
    }
    case 2: {
        cerr << "插入信息与原信息冲突,插入失败, at " << position << endl;;
        break;
    }
    case 3: {
        cerr << "查找失败返回NULL, at " << position << endl;;
        break;
    }
    case 4: {
        cerr << "不满足部门主管人数约束,添加失败, at " << position << endl;;
        break;
    }

    default: {
        cerr << "失败, at " << position << endl;
        break;
    }
    }

}


#endif // ALERT_H
