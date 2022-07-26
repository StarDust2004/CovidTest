/******************************************************************************
【文件名】Login.hpp
【功能模块和目的】登录的控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef Login_hpp
#define Login_hpp

#include "../Models/UserManager.hpp"
#include "ControlerAbstractBase.hpp"
using namespace std;

/*************************************************************************
【类名】Login
【功能】负责登录的控制器类的操作
【接口说明】
    构造函数Login(shared_ptr<User> CurrentUser = nullptr)；
    析构函数~Login(),考虑到后续扩展的可能性，写为虚函数；
    函数LoginUser用于检查用户能否成功登录
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class Login : public ControlerAbstractBase
{
public:
    //构造函数
    Login(shared_ptr<User> CurrentUser = nullptr);
    //析构函数
    virtual ~Login();

    //检查用户ID和密码是否对应，检查是否能够成功登录,返回User指针
    shared_ptr<User> LoginUser(shared_ptr<UserManager>& aUserManager, 
        const string& IDNumber, const string& Password);
};

#endif