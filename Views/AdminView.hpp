/******************************************************************************
【文件名】AdminView.hpp
【功能模块和目的】管理员界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef AdminView_hpp
#define AdminView_hpp

#include"../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/AdminControl.hpp"
using namespace std;

/*************************************************************************
【类名】AdminView
【功能】
    管理员界面类的操作。
    当用户在PortalView（主界面）选择以管理员身份登录时，主界面跳转到管理员界面；
    管理员可以输入一个用户的身份证号，并选择将其调整为什么身份。
【接口说明】
    构造函数AdminView();
    析构函数~AdminView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowAdmin显示管理员界面；
    函数CheckID判断输入的身份证号是否符合规范；
    数据成员m_pAdminControl指向AdminControl的实例，方便调用
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class AdminView
{
public:
    //构造函数
    AdminView();
    //析构函数
    virtual ~AdminView();

    //显示管理员界面的函数
    //通过传入的User智能指针，生成AdminControl的实例
    //然后调用AdminControl里的函数，对管理员的输入做出回应
    void ShowAdmin(shared_ptr<User> pCurrentUser, 
        shared_ptr<UserManager> aUserManager);
        
    //判断输入的身份证号是否符合规范的函数
    bool CheckID(const string& ID);
private:
    //AdminControl的实例的智能指针
    shared_ptr<AdminControl> m_pAdminControl;
};//end class AdminView


#endif