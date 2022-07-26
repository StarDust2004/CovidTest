/******************************************************************************
【文件名】RegisterView.hpp
【功能模块和目的】注册界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef RegisterView_hpp
#define RegisterView_hpp

#include<string>
#include<vector>
#include"../Controllers/Register.hpp"
using namespace std;

/*************************************************************************
【类名】RegisterView
【功能】
    注册界面类的操作。
    只负责注册一个新用户，然后就回到Login界面，不需要调用LoginView
【接口说明】
    构造函数RegisterView();
    析构函数~RegisterView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowRegister显示注册界面并读入信息
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class RegisterView
{
public:
    RegisterView();//构造函数
    virtual ~RegisterView();//析构函数

    //显示基本界面并读入信息
    void ShowRegister(shared_ptr<UserManager>& aUserManager) const;

};//end class Register

#endif