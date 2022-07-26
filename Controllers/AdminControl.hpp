/******************************************************************************
【文件名】AdminControl.hpp
【功能模块和目的】管理员控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef AdminControl_hpp
#define AdminControl_hpp

#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "ControlerAbstractBase.hpp"
using namespace std;

/*************************************************************************
【类名】AdminControl
【功能】管理员控制器类的操作
【接口说明】
    构造函数AdminControl(shared_ptr<User> CurrentUser);
    析构函数 ~AdminControl(),考虑到后续扩展的可能性，写为虚函数；
    函数AppointAsAdmin将给定用户指定为Admin(管理员)；
    函数AppointAsCollector将给定用户指定为Collector(采集员)；
    函数AppointAsEntryStaff将给定用户指定为EntryStaff(录入员)
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class AdminControl : public ControlerAbstractBase
{
public:
    //构造函数
    AdminControl(shared_ptr<User> CurrentUser);
    //析构函数
    virtual ~AdminControl();
    
    //通过身份证号查找，将给定用户指定为Admin(管理员)
    void AppointAsAdmin(shared_ptr<UserManager> aUserManager, 
        const string& IDNumber);
    //通过身份证号查找，将给定用户指定为Collector(采集员)
    void AppointAsCollector(shared_ptr<UserManager> aUserManager, 
        const string& IDNumber);
    //通过身份证号查找，将给定用户指定为EntryStaff(录入员)
    void AppointAsEntryStaff(shared_ptr<UserManager> aUserManager, 
        const string& IDNumber);
};

#endif