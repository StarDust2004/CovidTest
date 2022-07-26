/******************************************************************************
【文件名】Register.cpp
【功能模块和目的】负责新用户注册的控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "../Models/UserManager.hpp"
#include "Register.hpp"
using namespace std;

/******************************************************************************
【函数名称】Register
【函数功能】Register类的构造函数，可以创建Register类的一个实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
Register::Register() 
{

}

/******************************************************************************
【函数名称】~Register
【函数功能】Register类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
Register::~Register() {

}

/******************************************************************************
【函数名称】RegisterNewUser
【函数功能】通过一个UserManager实例来调用UserManager::AddUser，从而注册一个新的用户
【参数】
    输入参数shared_ptr<UserManager> aUserManager，用来调用UserManager的函数；
    输入参数string IDNumber，传入需要创建的新用户的身份证号；
    输入参数string Name，传入需要创建的新用户的姓名；
    输入参数CipherText Password，传入需要创建的新用户的密码；
    输入参数string TelephoneNumber，传入需要创建的新用户的电话号码（默认值为nullptr)
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void Register::RegisterNewUser(shared_ptr<UserManager>& aUserManager, const string& IDNumber,
    const string& Name, const string& Password, 
    const string& TelephoneNumber)
{
    try
    {
        aUserManager->AddUser(IDNumber, Name, Password, TelephoneNumber);
        cout << "创建成功." << endl;//创建成功，输出提示语句
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';//输出报错信息
        cout << "创建失败." << endl; //创建失败，输出提示语句
    }
}