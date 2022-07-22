#include <string>
#include <iostream>
#include "../Models/UserManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/Login.hpp"
#include "LoginView.hpp"
#include "RegisterView.hpp"
#include "PortalView.hpp"
#include "AdminView.hpp"
#include "CollectorView.hpp"
#include "EntryStaffView.hpp"
#include "TesteeView.hpp"
using namespace std;

//无参构造函数
LoginView::LoginView()
{
    m_pUserManager = nullptr;
    m_pCurrentUser = nullptr;
    m_pLogin = nullptr;
    m_pPortalView = nullptr;
    m_pTubeManager = nullptr;
    m_pRegisterView = nullptr;
}

//析构函数
LoginView::~LoginView()
{
    //是否需要delete掉智能指针
}

//显示基本界面并读入信息
void LoginView::ShowLogin()
{
    bool Exist = false;

    //debuging
    //创建UserManager的实例，将指针存入m_pUserManager
    m_pUserManager = make_shared<UserManager>();
    /*
    if (m_pUserManager == nullptr)//如果m_pUserManager为空
    {
        //创建UserManager的实例，将指针存入m_pUserManager
        m_pUserManager = make_shared<UserManager>();
    }
    */

    if (m_pTubeManager == nullptr)//如果m_pTubeManager为空
    {
        //创建TubeManager的实例，将指针存入m_pTubeManager
        m_pTubeManager = make_shared<TubeManager>();
    }
    if (m_pLogin == nullptr)//如果m_pLogin为空
    {
        //创建Login的实例，将指针存入m_pLogin
        m_pLogin = make_shared<Login>();
    }
    unsigned int i;//用于读取用户的选择
    //string Name;//用于读取用户输入的姓名
    string UserID;//用于读取用户输入的身份证号
    string Password;//用于读取用户输入的密码
    while(!Exist == true)
    {
        cout << "**************************************************" << endl;
        cout << "退出系统请按0,直接登录请按1,注册新用户请按2。" << endl;
        cin >> i;//读取用户的选择
        if (i == 0)//退出系统
        {
            //保存数据，然后退出系统界面
            Exit();
            Exist = true;//退出程序
        }
        else if (i == 1)//直接登录
        {
            cout << "请输入身份证号和密码以进行登录" << endl;
            cout << "身份证号：";
            cin >> UserID; //读取用户输入的身份证号
            cout << "密码：";
            cin >> Password;//读取用户输入的密码
            //检查身份证号与密码是否对应
            try
            {
                //成功登录则将User指针存到m_pCurrentUser中
                m_pCurrentUser = m_pLogin->LoginUser(m_pUserManager, UserID, Password);
                //此处有可能抛出异常
                //m_pCurrentUser = m_pUserManager->Verify(UserID, Password);
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';//输出报错信息
                continue;
            }
            if (m_pPortalView == nullptr)//如果m_pPortalView为空
            {
                //创建一个PortalView的实例,将指针存入m_pPortalView
                m_pPortalView = make_shared<PortalView>();
            }
            //跳转到PortalView主界面
            m_pPortalView->ShowPortal(m_pCurrentUser, m_pTubeManager, m_pUserManager);
        }
        else if (i == 2)//注册新用户
        {
            if (m_pRegisterView == nullptr)//如果m_pRegisterView为空
            {
                //创建一个RegisterView的实例,将指针存入m_pRegisterView
                m_pRegisterView = make_shared<RegisterView>();
            }
            //跳转到RegisterView注册界面
            m_pRegisterView->ShowRegister(m_pUserManager);
        }
        else
        {
            cout << "指令无效" << endl;
        }
    }
}

//退出程序的函数：退出当前登录，保存信息
void LoginView::Exit()
{
    //debuging
    //保存信息
    try
    {
        m_pUserManager->SaveToFile(UsersFileName);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';//输出报错信息
    }
    try
    {
        m_pTubeManager->SaveToFile(TubesFileName);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';//输出报错信息
    }
    /*debuging
    m_pUserManager->SaveToFile(UsersFileName);
    m_pTubeManager->SaveToFile(TubesFileName);
    */
    
    //显示登出界面
    //按下任意键后清屏
    //debuging
    //system("pause");
    //system("cls");
    cout << "您已成功退出." << endl;
}




