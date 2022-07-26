/******************************************************************************
【文件名】UserManager.cpp
【功能模块和目的】管理User类的数据的类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-21 由黄润一添加了CheckID函数，修改了其他一些函数
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
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
#include "UserManager.hpp"
using namespace std;

/******************************************************************************
【函数名称】UserManager
【函数功能】UserManager类的构造函数，可以创建一个UserManager类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
UserManager::UserManager()
{

}

/******************************************************************************
【函数名称】~UserManager
【函数功能】UserManager类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
UserManager::~UserManager(){

}

/******************************************************************************
【函数名称】AddUser
【函数功能】用于添加一个用户，添加前需要检验身份证号、姓名、密码的规范性
【参数】
    输入参数IDNumber，传入用户的身份证号；
    输入参数Name，传入用户的姓名；
    输入参数Password，传入用户的密码；
    输入参数TelephoneNumber，传入用户的电话号码，默认值为空；
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void UserManager::AddUser(const string& IDNumber, const string& Name, 
    const string& Password, const string& TelephoneNumber)
{
    //用户的身份证号不能相同
    //Lambda functional object for IDNumber comparison用于身份证号比较的Lambda函数对象
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool{return (ptr->GetIDNumber() == IDNumber);};
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
    if (!CheckID(IDNumber))
    {
        throw invalid_argument("Invalid IDNumber");
    }
    
    CipherText CipherPassword(Password);

    //上述情况均未发生
    User* aUser = new User(IDNumber, Name, CipherPassword, TelephoneNumber);

    //将新用户的指针保存到列表中去
    m_All.push_back(shared_ptr<User>(aUser));
}	

/******************************************************************************
【函数名称】SaveToFile
【函数功能】
    保存所有User到指定的文件。
    如果文件无法打开，则尝试创建文件；
    如果无法创建文件，将抛出invalid_argument异常。
【参数】输入参数string FileName，传入文件名
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void UserManager::SaveToFile(const string& FileName)
{
    //打开或创建由FileName指定的文件
    ofstream File(FileName);
    //Can't create or open file
    if (!File.is_open()) 
    {
        throw invalid_argument("Can't open/Create for saving, File : " + FileName);
    }
    //用于保存一个用户的Lambda表达式
    auto Saver = [&File](shared_ptr<User> Ptr) {File << *Ptr << endl;};
    //首先，将用户计数保存到文件的开头
    File << m_All.size() << endl;
    //traversal for save all users' data遍历并保存所有用户数据
    for_each(m_All.begin(), m_All.end(), Saver);
    //关闭文件
    File.close();
}

/******************************************************************************
【函数名称】LoadFromFile
【函数功能】
    从指定的文件中读取和创建所有User对象。
    如果文件无法打开，则尝试创建文件；
    如果无法创建文件，将抛出invalid_argument异常。
【参数】输入参数string FileName，传入文件名
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void UserManager::LoadFromFile(const string& FileName)
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
            //通过简单的信息动态创建用户；
            User* aUser = new User{ string{""}, string{""}, CipherText{"123456"}, string{""} };
            //将新用户的指针保存到列表中去，插入到末尾;
            m_All.push_back(shared_ptr<User>(aUser));
            //然后从文件流中更新用户信息
            File >> *(*(m_All.end() - 1));
        }
    }
    //关闭文件
    File.close();
}

/******************************************************************************
【函数名称】SearchUserByID
【函数功能】给定身份证号，在用户列表中查找某个用户，传回其指针
【参数】输入参数string IDNumber，传入需搜索的身份证号；
【返回值】shared_ptr<User>，返回搜索到的User的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<User> UserManager::SearchUserByID(const string& IDNumber)
{
    //用于身份证号比较的Lambda函数对象
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool{return (ptr->GetIDNumber() == IDNumber);};
    //找出由身份证号指定的第一个用户
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    return *it;
}

/******************************************************************************
【函数名称】Verify
【函数功能】
    检验给定的身份证号是否存在User实例，与密码是否对应得上。
    User实例不存在，将会引发ExceptionNoUser；
    User实例存在，但密码错误，将抛出一个ExceptionWrongPassword；
    User实例存在，搜索到给定身份证号和密码对应的User实例，返回其指针。
【参数】
    输入参数string IDNumber，传入身份证号；
    输入参数string Password，传入密码
【返回值】shared_ptr<User>，返回搜索到的可登录的User的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<User> UserManager::Verify(const string& IDNumber, 
    const string& Password)
{
    //Lambda functional object for IDNumber comparision
    auto Finder = [&IDNumber](shared_ptr<User> ptr)->bool
        {return (ptr->GetIDNumber() == IDNumber);};
    //To find out the first user specified by IDNumber
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    //不存在，引发ExceptionNoUser
    if (it == m_All.end()) 
    {
        throw ExceptionNoUser();
    }
    //存在，但密码错误，抛出一个ExceptionWrongPassword
    else if (!((*it)->Verify(Password)))
    {
        throw ExceptionWrongPassword();//密码错误
    }
    //返回搜索到的可登录的User的智能指针
    else 
    {
        return *it;
    }
}
   
/******************************************************************************
【函数名称】Delete
【函数功能】通过给定的指针，从m_All里移除并销毁某一个实例
【参数】输入参数shared_ptr<User> Source，传入需销毁的User实例的指针
【返回值】bool，销毁成功则返回true，失败则抛出异常
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
bool UserManager::Delete(shared_ptr<User> Source)
{
    auto Finder = [Source](shared_ptr<User> ptr)->bool
        {return (ptr == Source);};
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
        throw string("No such user");
    }
}

/******************************************************************************
【函数名称】CheckID
【函数功能】判断输入的身份证号是否符合规范
【参数】输入参数ID，传入一串需要判断规范性的身份证号
【返回值】bool，符合规范则返回true，不符合则返回false
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-21
【更改记录】
******************************************************************************/
bool UserManager::CheckID(const string& ID)
{
    //身份证号必须是18位
    if (ID.size() != 18)
    {
        return false;
    }
    else
    {
        int i = 0;
        //前17位必须全是数字
        for (i = 0; i < 17; i++)
        {
            if (ID[i] < '0' || ID[i] > '9')
            {
                return false;
            }
        }
        //第18位应为数字或者'x'
        if ((ID[17] < '0' || ID[17] > '9') && (ID[17] != 'x'))
        {
            return false;
        }
        return true;
    }
}
