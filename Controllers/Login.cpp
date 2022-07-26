/******************************************************************************
【文件名】Login.cpp
【功能模块和目的】负责登录的控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "../Models/UserManager.hpp"
#include "ControlerAbstractBase.hpp"
#include "Login.hpp"
using namespace std;

/******************************************************************************
【函数名称】Login
【函数功能】Login类的构造函数，可以创建Login类的一个实例
【参数】输入参数shared_ptr<User> CurrentUser
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
Login::Login(shared_ptr<User> CurrentUser) : ControlerAbstractBase(CurrentUser)
{

}

/******************************************************************************
【函数名称】~Login
【函数功能】Login类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
Login::~Login(){

}

/******************************************************************************
【函数名称】LoginUser
【函数功能】检查是否能够成功登录
【参数】
    输入参数shared_ptr<UserManager> aUserManager，用来调用UserManager里的函数；
    输入参数string IDNumber，传入用户输入的身份证号；
    输入参数string Password，传入用户输入的密码
【返回值】shared_ptr<User>，返回根据身份证号查找到的该用户实例的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<User> Login::LoginUser(shared_ptr<UserManager>& aUserManager, 
    const string& IDNumber, const string& Password)
{
    //如果核验通过，登录，并将找到的用户指针存在m_pCurrentUser中（当前用户）
    m_pCurrentUser = aUserManager->Verify(IDNumber, Password);
    return m_pCurrentUser;
}
   