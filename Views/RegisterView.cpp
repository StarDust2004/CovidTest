/******************************************************************************
【文件名】RegisterView.cpp
【功能模块和目的】注册界面类的的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include<string>
#include<vector>
#include"../Controllers/Register.hpp"
#include"../Models/CipherText.hpp"
#include"RegisterView.hpp"
using namespace std;

/******************************************************************************
【函数名称】RegisterView
【函数功能】RegisterView类的构造函数，可以创建一个RegisterView类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
RegisterView::RegisterView()
{

}

/******************************************************************************
【函数名称】~RegisterView
【函数功能】RegisterView类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
RegisterView::~RegisterView(){

}

/******************************************************************************
【函数名称】ShowRegister
【函数功能】显示基本注册界面并读入信息
【参数】输入参数aUserManager，用于调用UserManager的成员
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void RegisterView::ShowRegister(shared_ptr<UserManager>& aUserManager) const
{
    string Name;//临时变量，暂存姓名
    string ID;//临时变量，暂存身份证号
    string Password;//临时变量，暂存密码
    cout << "请输入身份证号、姓名和密码以注册一个新用户." << endl;
    cout << "身份证号:" ;
    cin >> ID;//读入用户输入的身份证号
    cout << "姓名:";
    cin >> Name;//读入用户输入的姓名
    cout << "密码:";
    cin >> Password;//读入用户输入的密码
    Register aReg;//创建一个Register(control类)的实例
    //调用函数，创建新用户
    aReg.RegisterNewUser(aUserManager, ID, Name, Password, "");
}

