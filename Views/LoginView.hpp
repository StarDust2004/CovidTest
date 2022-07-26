/******************************************************************************
【文件名】LoginView.hpp
【功能模块和目的】登录界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-22 由黄润一添加、修改了注释
******************************************************************************/
#ifndef LoginView_hpp
#define LoginView_hpp

#include<string>
#include <iostream>
#include "LoginView.hpp"
#include "RegisterView.hpp"
#include "PortalView.hpp"
#include "../Models/UserManager.hpp"
#include "../Models/TubeManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/Login.hpp"
using namespace std;

/*************************************************************************
【类名】LoginView
【功能】登录界面类的操作
【接口说明】
    构造函数LoginView();
    析构函数~LoginView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowLogin显示基本界面并读入信息；
    函数Exit保存信息并退出程序；
    数据成员m_pUserManager，指向当前唯一UserManager实例；
    数据成员m_pTubeManager，指向当前唯一TubeManager实例；
    数据成员m_pCurrentUser，指向当前唯一User实例；
    数据成员m_pLogin，方便调用Controler类中的Login；
    数据成员m_pPortalView，方便进入主界面PortalView；
    数据成员m_pRegisterView，RegisterView的实例的智能指针，方便进入注册界面
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-22 由黄润一添加、修改了注释
*************************************************************************/
class LoginView
{
public:
    LoginView();//无参构造函数
    virtual ~LoginView();//析构函数

    //显示基本界面并读入信息
    void ShowLogin();
    //退出程序的函数,保存信息并退出程序
    void Exit();
private:
    //User manager，当前唯一
    shared_ptr<UserManager> m_pUserManager;
    //Tube manager，当前唯一
    shared_ptr<TubeManager> m_pTubeManager;

    //Current user
    shared_ptr<User> m_pCurrentUser;

    //Login(control)的实例的智能指针
    shared_ptr<Login> m_pLogin;

    //PortalView的实例的智能指针
    shared_ptr<PortalView> m_pPortalView;

    //RegisterView的实例的智能指针
    shared_ptr<RegisterView> m_pRegisterView;
};//end class LoginView

#endif