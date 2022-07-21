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

//登录界面
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