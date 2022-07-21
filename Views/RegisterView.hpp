#ifndef RegisterView_hpp
#define RegisterView_hpp

#include<string>
#include<vector>
#include"../Controllers/Register.hpp"
using namespace std;

//注册界面
//只负责注册一个新用户，然后就回到Login界面，不需要调用LoginView
class RegisterView
{
public:
    RegisterView();//构造函数
    virtual ~RegisterView();//析构函数

    //显示基本界面并读入信息
    void ShowRegister(shared_ptr<UserManager>& aUserManager) const;

};//end class Register

#endif