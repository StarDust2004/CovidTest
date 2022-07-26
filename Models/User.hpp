/******************************************************************************
【文件名】User.hpp
【功能模块和目的】用户类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】
    2022-07-09 由黄润一添加了用户异常类的声明
    2022-07-16 由黄润一添加了多个Get函数的声明
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至UserManager类
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef User_hpp
#define User_hpp

#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include"CipherText.hpp"
#include"DateTime.hpp"
#include"Constant.hpp"
using namespace std;

//---- Exceptions ----//
//The NO USER exception class
class ExceptionNoUser : public invalid_argument
{
public:
    ExceptionNoUser();
};

//The HAS USER BUT WRONG PASSWORD exception class
class ExceptionWrongPassword : public invalid_argument
{
public:
    ExceptionWrongPassword();
};

//The USER EXISTS exception class
class ExceptionUserExists : public invalid_argument
{
public:
    ExceptionUserExists();
};

/*************************************************************************
【类名】User
【功能】用户类的操作
【接口说明】
    构造函数User(const string& IDNumber, const string& Name, const 
        CipherText& Password, const string& TelephoneNumber = nullptr);
    析构函数~User()，考虑到后续扩展的可能性，写为虚函数；
    重载流插入运算符<<；
    重载流提取运算符>>；
    函数GetName读取姓名m_Name;
    函数GetIDNumber读取身份证号m_IDNumber;
    函数GetType读取用户类型m_uType；
    函数GetTelephoneNumber读取电话号码m_TelephoneNumber；
    函数SetType修改用户类型m_uTypes；
    函数SetTelephoneNumber修改电话号码m_TelephoneNumber；
    函数Verify判断输入的密码是否正确，正确则返回true，错误则返回false；
    函数changePassword修改密码；
    私有数据成员m_IDNumber，身份证号；
    私有数据成员m_Name，姓名；
    私有数据成员m_Password，密码以密文存储；
    私有数据成员m_TelephoneNumber，电话号码；
    私有数据成员m_uType，用户类型
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】
    2022-07-09 由黄润一添加了用户异常类的声明
    2022-07-16 由黄润一添加了多个Get函数的声明
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至UserManager类
    2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class User
{
public:
    //不允许无用户名和密码的用户创建：delete默认构造函数
	User() = delete;
	//不允许拷贝构造和赋值对象
	User(const User&) = delete; 
	User& operator=(const User&) = delete;

    //考虑到后续扩展和修改的可能性，析构函数应该是虚函数
    virtual ~User();

    //给定身份证号、姓名、密码创建用户
	User(const string& IDNumber, const string& Name, const 
        CipherText& Password, const string& TelephoneNumber = nullptr);

    //流插入运算符<<的运算符重载函数
    friend ostream& operator<<(ostream& Stream, const User& anUser);
    //流提取运算符>>的运算符重载函数
    friend istream& operator>>(istream& Stream, User& anUser);

    //读取姓名m_Name
    string GetName() const;
    //读取身份证号m_IDNumber的值
    string GetIDNumber() const;
    //读取用户类型m_uType的值   
    unsigned int GetType() const; 
    //读取电话号码m_TelephoneNumber
    string GetTelephoneNumber() const;
    //修改用户类型m_uTypes
    void SetType(unsigned int Type);
    //修改电话号码m_TelephoneNumber
    void SetTelephoneNumber(string& NewTelephoneNumber);

    //判断输入的密码是否正确，正确则返回true，错误则返回false
    bool Verify(const string& Password);

    /*
    //转移到UserManager类-------------------------------------------
    //类函数(静态的，没有对象的函数):保存所有用户到指定的文件，包括派生的对象
    static void SaveToFile(const string& FileName);
    //类函数(静态的，没有对象的函数):从指定的文件中读取和创建所有用户
    static void LoadFromFile(const string& FileName);
    //转移到UserManager类-------------------------------------------

    //转移到UserManager类-------------------------------------------
    //给定身份证号，在用户列表中查找某个用户
    static shared_ptr<User> SearchUser(const string& IDNumber);
    //转移到UserManager类-------------------------------------------
    */
protected:
    //修改密码
    void changePassword(const CipherText& NewPassword);
    
    /*
    //转移到UserManager类-------------------------------------------
    //用于添加一个用户
    //Create a user instance that wraps the protected constructor
	void AddUser(const string& IDNumber, const string& Name, 
        const CipherText& Password, const string& TelephoneNumber = nullptr);	

    //验证密码是否正确
    //class function(static, no object's function)
    //verify the specified user by user name and password.
    //the user name does not exist, an ExecptionNoUser will be thrown
    //the user exists but the password is wrong, an ExecptionWrongPassword will be thrown
    //the return value is the smart pointer to the user object
    static shared_ptr<User> Verify(const string& IDNumber, const string& Password);
    
    //通过给定的指针，从m_All里移除并销毁某一个实例，成功则返回true
    static bool Delete(shared_ptr<User>* Source);
    //转移到UserManager类-------------------------------------------
    */
private:
    string m_IDNumber;//身份证号
    string m_Name;//姓名
    CipherText m_Password;//密码以密文存储
    string m_TelephoneNumber;//电话号码
    //用户类型，每一位代表一个身份，0为否，1为是
    //在二进制中，最后一位表示被试者testee
    //从右往左数第二位表示管理员Admin
    //从右往左第三位表示采集员collector
    //从右往左第四位表示录入员EntryStaff
    unsigned int m_uType;
       
    /*写在Tube类里面
    DateTime m_SamplingTime;//采样日期时间
    DateTime m_EntryTime;//结果录入日期时间
    TestResult m_Result;//核酸检测结果（阴性/阳性）
    */
    //Tube* m_LatestTest;//最后一次核酸检测的指针

    /*
    //转移到UserManager类-------------------------------------------
    //所有用户对象的智能指针列表
    static vector<shared_ptr<User>> m_All;
    //转移到UserManager类-------------------------------------------
    */
};//end User

#endif