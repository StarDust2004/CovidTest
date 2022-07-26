/******************************************************************************
【文件名】AdminControl.cpp
【功能模块和目的】管理员控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "AdminControl.hpp"
#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "../Models/UserManager.hpp"
#include "../Models/TubeManager.hpp"
#include "ControlerAbstractBase.hpp"
#include <algorithm>
using namespace std;

/******************************************************************************
【函数名称】       AdminControl
【函数功能】       构造AdminControl类的一个实例
【参数】           输入参数CurrentUser，shared_ptr<User>类型，指向当前用户的实例
【返回值】         构造函数没有返回值
【开发者及日期】   黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】       2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
AdminControl::AdminControl(shared_ptr<User> CurrentUser)
    : ControlerAbstractBase(CurrentUser) {

}

/******************************************************************************
【函数名称】       ~AdminControl
【函数功能】       AdminControl类的析构函数
【参数】           没有参数
【返回值】         析构函数没有返回值
【开发者及日期】   黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】       2022-07-21 由黄润一添加注释
******************************************************************************/
AdminControl::~AdminControl() {

}

/******************************************************************************
【函数名称】AppointAsAdmin
【函数功能】通过身份证号查找，将给定用户指定为Admin(管理员)
【参数】
    输入参数aUserManager,shared_ptr<UserManager>类型，用来调用UserManager类的函数；
    输入参数IDNumber，string类型，传递需指定身份的用户的身份证号
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void AdminControl::AppointAsAdmin(shared_ptr<UserManager> aUserManager, 
    const string& IDNumber)
{
    //调用UserManager类的函数，通过身份证号查找到指定用户，返回其指针
    shared_ptr<User> theUser = aUserManager->SearchUserByID(IDNumber);
    unsigned int type = theUser->GetType();//读取该用户的用户类型
    type = type | 2;//调整为Admin
    //调用User类的成员函数，修改该用户的用户类型
    theUser->SetType(type);
}

/******************************************************************************
【函数名称】AppointAsCollector
【函数功能】通过身份证号查找，将给定用户指定为Collector(采集员)
【参数】输入参数aUserManager,shared_ptr<UserManager>类型，用来调用UserManager类的
       函数；
       输入参数IDNumber，string类型，传递需指定身份的用户的身份证号
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void AdminControl::AppointAsCollector(shared_ptr<UserManager> aUserManager, 
    const string& IDNumber)
{
    //调用UserManager类的成员函数，通过身份证号查找到指定用户，返回其指针
    shared_ptr<User> theUser = aUserManager->SearchUserByID(IDNumber);
    unsigned int type = theUser->GetType();//读取该用户的用户类型
    type = type | 4;//调整为采集员
    //调用User类的成员函数，修改该用户的用户类型
    theUser->SetType(type);
}

/******************************************************************************
【函数名称】AppointAsEntryStaff
【函数功能】通过身份证号查找，将给定用户指定为EntryStaff(录入员)
【参数】输入参数aUserManager,shared_ptr<UserManager>类型，用来调用UserManager类的
       函数；
       输入参数IDNumber，string类型，传递需指定身份的用户的身份证号
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void AdminControl::AppointAsEntryStaff(shared_ptr<UserManager> aUserManager, 
    const string& IDNumber)
{
    //调用UserManager类的成员函数，通过身份证号查找到指定用户，返回其指针
    shared_ptr<User> theUser = aUserManager->SearchUserByID(IDNumber);
    unsigned int type = theUser->GetType();//读取该用户的用户类型
    type = type | 8;//调整为录入员
    //调用User类的成员函数，修改该用户的用户类型
    theUser->SetType(type);   
}

