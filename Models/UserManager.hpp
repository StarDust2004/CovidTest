/******************************************************************************
【文件名】UserManager.hpp
【功能模块和目的】管理User类的数据的类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef UserManager_hpp
#define UserManager_hpp

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <fstream>
#include "CipherText.hpp"
#include "DateTime.hpp"
#include "Constant.hpp"
#include "User.hpp"
using namespace std;

/*************************************************************************
【类名】TubeManager
【功能】管理User类的数据的类的操作
【接口说明】
    构造函数UserManager();
    析构函数~UserManager()，考虑后续扩展的可能性，写为虚函数；
    函数SaveToFile保存所有User到指定的文件；
    函数LoadFromFile从指定的文件中读取和创建所有User对象；
    函数SearchUserByID通过身份证号在User列表中查找某个用户；
    函数AddUser用于添加一个用户，添加前需要检验身份证号、姓名、密码的规范性；
    函数Verify检验给定的身份证号与密码是否对应得上；
    函数CheckID判断输入的身份证号是否符合规范的函数；
    函数Delete通过给定的指针，从m_All里移除并销毁某一个实例；
    数据成员m_All，所有用户对象的智能指针列表
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-21 由黄润一添加了CheckID函数，修改了其他一些函数
    2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class UserManager
{
public:
    //构造函数
    UserManager();
    //析构函数
    virtual ~UserManager();

    //保存所有用户到指定的文件
    void SaveToFile(const string& FileName);
    //从指定的文件中读取和创建所有用户
    void LoadFromFile(const string& FileName);
    //给定身份证号，在用户列表中查找某个用户
    shared_ptr<User> SearchUserByID(const string& IDNumber);
    //用于添加一个用户
	void AddUser(const string& IDNumber, const string& Name, 
        const string& Password, const string& TelephoneNumber = nullptr);	

    //验证密码是否正确
    //class function(static, no object's function)
    //verify the specified user by user name and password.
    //the user name does not exist, an ExecptionNoUser will be thrown
    //the user exists but the password is wrong, an ExecptionWrongPassword will be thrown
    //the return value is the smart pointer to the user object
    shared_ptr<User> Verify(const string& IDNumber, const string& Password);

    //判断输入的身份证号是否符合规范的函数
    bool CheckID(const string& ID);
    
    //通过给定的指针，从m_All里移除并销毁某一个实例，成功则返回true
    bool Delete(shared_ptr<User> Source);

    /*
    //当前登录的用户的指针,control类和View类均可访问(作为参数传入)
    //在Login时创建/保存到此处
    shared_ptr<User> pCurrentUser;
    */

private:
    //所有用户对象的智能指针列表
    vector<shared_ptr<User>> m_All;
};//end class UserManager

#endif