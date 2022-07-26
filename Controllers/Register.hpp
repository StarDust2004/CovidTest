/******************************************************************************
【文件名】Register.hpp
【功能模块和目的】负责新用户注册的控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef Register_hpp
#define Register_hpp

#include "../Models/UserManager.hpp"
#include "ControlerAbstractBase.hpp"

/*************************************************************************
【类名】Register
【功能】负责新用户注册的控制器类的操作
【接口说明】
    构造函数Register();
    析构函数~Register(),考虑到后续扩展的可能性，写为虚函数；
    函数RegisterNewUser通过一个UserManager实例来调用UserManager::AddUser()，
    从而注册一个新的用户。
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class Register
{
public:
    //构造函数
    Register();
    //析构函数
    virtual ~Register();

    //通过一个UserManager实例来调用UserManager::AddUser()，
    //从而注册一个新的用户
    void RegisterNewUser(shared_ptr<UserManager>& aUserManager, 
        const string& IDNumber, const string& Name, const string& Password, 
        const string& TelephoneNumber = nullptr);
};//end class Register

#endif