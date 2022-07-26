/******************************************************************************
【文件名】User.cpp
【功能模块和目的】用户类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】
    2022-07-09 由黄润一添加了用户异常类的定义
    2022-07-16 由黄润一添加了多个Get函数和其他一些函数
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至UserManager类
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <fstream>
#include "User.hpp"
#include "Constant.hpp"
using namespace std;

//用户异常类的定义
//The default constructor of NO USER exception class
ExceptionNoUser::ExceptionNoUser() : invalid_argument("No such user."){
}

//The default constructor of HAS USER BUT WRONG PASSWORD exception class
ExceptionWrongPassword::ExceptionWrongPassword() 
    : invalid_argument("Wrong password."){
}

//The default constructor of USER EXISTS exception class
ExceptionUserExists::ExceptionUserExists() : invalid_argument("User Exist."){
}

/******************************************************************************
【函数名称】~User
【函数功能】User类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
User::~User(){
}

/******************************************************************************
【函数名称】User
【函数功能】
    User类的构造函数，可以给定身份证号、姓名、密码（和电话号码）创建一个User类的实例
【参数】
    输入参数IDNumber，身份证号；
    输入参数Name，姓名；
    输入参数Password，密码；
    输入参数TelephoneNumber，电话号码，默认值为nullptr
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】
    2022-07-19 由黄润一修改了函数体，将部分功能转移至UserManager类
    2022-07-21 由黄润一修改了注释
******************************************************************************/
User::User(const string& IDNumber, const string& Name, const CipherText& Password,
    const string& TelephoneNumber) : m_Password(Password)
{
    /*转移至UserManager类
    //用户的身份证号不能相同
    //Lambda functional object for IDNumber comparison用于身份证号比较的Lambda函数对象
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool{return (ptr->m_IDNumber == IDNumber);};
    //To find out the first user specified by IDNumber找出由身份证号指定的第一个用户
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    //Found 用户已存在  
    if (it != m_All.end()) 
    {
        throw ExceptionUserExists();//用户已存在
    }
    //身份证号、姓名和密码都不能为空
    if (IDNumber.empty())
    {
        throw invalid_argument("Empty ID number");
    }
	if (Name.empty()) 
    {
		throw invalid_argument("Empty user name");
	}
	if (Password.empty())
    {
		throw invalid_argument("Empty password");
	}
    //身份证号必须为18位数,否则抛出异常
    if (IDNumber.size() != 18)
    {
        throw invalid_argument("Invalid IDNumber");
    }
    //上述情况均未发生
    */

	//私有非静态成员赋初始值
    m_IDNumber = IDNumber;
    m_Name = Name;
    //电话号码不作为注册时的强制要求，给出默认值为nullptr
    m_TelephoneNumber = TelephoneNumber;
    m_uType = 1;//用户类型需要人为指定，默认为单纯的被试者
    /*转移至UserManager类
    //将新用户的指针保存到列表中去
    m_All.push_back(shared_ptr<User>(this));
    */
}

/******************************************************************************
【函数名称】operator<<重载
【函数功能】流插入运算符<<的重载
【参数】
    输入参数anUser，需要插入流中的User实例的引用;
    输出参数Stream
【返回值】ostream&，返回Stream
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
ostream& operator<<(ostream& Stream, const User& anUser)
{
    //插入四行姓名、身份证号、密码(以密文形式)、用户类型
    Stream << anUser.m_Name << endl << anUser.m_IDNumber << endl 
        << anUser.m_Password << endl << anUser.m_uType;
    return Stream;
}

/******************************************************************************
【函数名称】operator>>重载
【函数功能】流提取运算符>>的重载
【参数】
    输入参数anUser，需要从流中提取信息存入的User实例的引用;
    输出参数Stream
【返回值】istream&，返回Stream
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
istream& operator>>(istream& Stream, User& anUser)
{
    //从流中提取四行姓名、身份证号、密码(以密文形式)、用户类型
    //不需要用endl处理，它已经被字符串提取运算符处理了
    Stream >> anUser.m_Name >> anUser.m_IDNumber >> anUser.m_Password 
        >> anUser.m_uType;
    return Stream;
}

/******************************************************************************
【函数名称】changePassword
【函数功能】修改函数
【参数】输入参数NewPassword，传入新密码
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void User::changePassword(const CipherText& NewPassword)
{
    m_Password = NewPassword;
}

/******************************************************************************
【函数名称】GetName
【函数功能】读取姓名Name
【参数】无
【返回值】string，返回m_Name
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
string User::GetName() const
{
    return m_Name;
}

/******************************************************************************
【函数名称】GetIDNumber
【函数功能】读取身份证号m_IDNumber
【参数】无
【返回值】string，返回m_IDNumber
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
string User::GetIDNumber() const
{
    return m_IDNumber;
}

/******************************************************************************
【函数名称】GetType
【函数功能】读取用户类型m_uType的值
【参数】无
【返回值】unsigned int，返回m_uType
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/ 
unsigned int User::GetType() const
{
    return m_uType;
}

/******************************************************************************
【函数名称】GetTelephoneNumber
【函数功能】读取电话号码m_TelephoneNumber
【参数】无
【返回值】string，返回m_TelephoneNumber
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/ 
string User::GetTelephoneNumber() const
{
    return m_TelephoneNumber;
}

/******************************************************************************
【函数名称】SetType
【函数功能】修改用户类型m_uType
【参数】输入参数unsigned int Type，传入需要设置为的用户类型的值
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/ 
void User::SetType(unsigned int Type)
{
    m_uType = Type;
}

/******************************************************************************
【函数名称】SetTelephoneNumber
【函数功能】修改电话号码m_TelephoneNumber
【参数】输入参数NewTelephoneNumber，传入需要设置为的电话号码
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-16
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
void User::SetTelephoneNumber(string& NewTelephoneNumber)
{
    m_TelephoneNumber = NewTelephoneNumber;
}

/******************************************************************************
【函数名称】Verify
【函数功能】通过密码验证用户能否登录
【参数】输入参数Password，传入需要核验的密码
【返回值】bool，输入的密码错误则返回false，正确则返回true
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】
    2022-07-16 由黄润一修改了函数体，将部分功能转移至UserManager类
    2022-07-21 由黄润一修改了注释
******************************************************************************/
bool User::Verify(const string& Password)
{
    if (this->m_Password != Password)
    {
        return false;//输入的密码错误
    }
    return true;//密码正确
}

/*转移至UserManager类
//静态函数：将所有用户保存到指定文件，包括派生对象
//如果文件无法打开，则尝试创建文件
//如果无法创建文件，将抛出invalid_argument异常
void User::SaveToFile(const string& FileName)
{
    //打开或创建由FileName指定的文件
    ofstream File(FileName);
    //Can't create or open file
    if (!File.is_open()) 
    {
        throw invalid_argument("Can't open/Create for saving, File : " + FileName);
    }
    //用于保存一个用户的Lambda表达式Lambda functional object for save one user
    auto Saver = [&File](shared_ptr<User> Ptr) {File << *Ptr << endl;};
    //Save the users count to the begin of the file, fist of all首先，将用户计数保存到文件的开头
    File << m_All.size() << endl;
    //traversal for save all users' data遍历并保存所有用户数据
    for_each(m_All.begin(), m_All.end(), Saver);
    //close means save to physical file system
}

//静态函数：从指定文件中读取和创建所有用户
//如果文件无法打开，则尝试创建文件
//如果无法创建文件，将抛出invalid_argument异常
void User::LoadFromFile(const string& FileName)
{
    //尝试打开指定文件
    ifstream File(FileName);
    //无法打开
    if (!File.is_open()) 
    {
        //尝试通过文件名创建文件
        ofstream NewFile(FileName);
        //无法创建文件
        if (!NewFile.is_open()) 
        {
            throw invalid_argument("Can't open/create for loading, file: " + FileName);
        }
        //设置初始用户数为0
        NewFile << 0 << endl;
        //关闭文件
        NewFile.close();

        //打开新文件
        File.open(FileName);
    }
    unsigned int UserCount;//文件中的用户计数
    //从文件中获取用户数
    File >> UserCount;
    //drop the endl after the users' count删除在用户计数后的endl
    File.get();
    //清除所有用户
    m_All.clear();
    //Zero user, then create the administrator by default name and password;
    if (UserCount < 1) 
    {
        throw invalid_argument("No user in this file");
    }
    //至少有一个用户
    else
    {
        for (unsigned long i = 0; i < UserCount; i++) 
        {
            //dynamic create an user by empty name and simple password;
            new User{string{"000000000000000000"}, string{"name"}, CipherText{"123456"}};
            //then update the user from file stream
            File >> *(*(m_All.end() - 1));
        }
    }
    //关闭文件
    File.close();
}

//通过身份证号和密码验证指定用户的静态函数。
//身份证号不存在，将会引发ExceptionNoUser
//用户存在，但密码错误，将抛出一个ExceptionWrongPassword
//返回值是指向用户对象的智能指针
shared_ptr<User> User::Verify(const string& IDNumber, const string& Password)
{
    //Lambda functional object for IDNumber comparision
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool
        {return (ptr->m_IDNumber == IDNumber);};
    //To find out the first user specified by IDNumber
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    //not found, throw NO USER excption
    if (it == m_All.end()) 
    {
        throw ExceptionNoUser();
    }
    //found，but wrong password, throw WRONG PASSWORD exception
    else if ((*it)->m_Password != Password)
    {
        throw ExceptionWrongPassword();
    }
    //return the user's smart pointer
    else 
    {
        return *it;
    }
}

//类的行为：通过给定的指针，从m_All里移除并销毁某一个实例，成功则返回true
bool User::Delete(shared_ptr<User>* Source)
{
    auto Finder = [Source](shared_ptr<User> ptr)->bool
        {return (&ptr == Source);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    //Found
    if (it != m_All.end()) 
    {
        //delete user
        m_All.erase(it);
        return true;
    }
    else
    {
        throw string("No such user");//???
    }
}

/*转移至UserManager类
//Create a user instance that wraps the protected constructor
void User::AddUser(const string& IDNumber, const string& Name,
    const CipherText& Password, const string& TelephoneNumber)
{//User objects can only be dynamically instantiated through the new operator
    new User(IDNumber, Name, Password);
}

//给定身份证号，在用户列表中查找某个用户，返回shared_ptr<User>指针
shared_ptr<User> User::SearchUser(const string& IDNumber)
{
    //Lambda functional object for IDNumber comparison用于身份证号比较的Lambda函数对象
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool{return (ptr->m_IDNumber == IDNumber);};
    //To find out the first user specified by IDNumber找出由身份证号指定的第一个用户
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    return *it;
}
*/