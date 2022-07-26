/******************************************************************************
【文件名】ControlerAbstractBase.cpp
【功能模块和目的】控制器抽象基类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】
    2022-07-19 由黄润一删除部分成员 
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include<string>
#include"../Models/CipherText.hpp"
#include"../Models/Date.hpp"
#include"../Models/Time.hpp"
#include"../Models/DateTime.hpp"
#include"../Models/MD5.hpp"
#include"../Models/Tube.hpp"
#include"../Models/User.hpp"
#include"../Models/UserManager.hpp"
#include"../Models/TubeManager.hpp"
#include"ControlerAbstractBase.hpp"
using namespace std;

/******************************************************************************
【函数名称】ControlerAbstractBase
【函数功能】ControlerAbstractBase类的构造函数，可构造CollectorControl类的一个实例
【参数】输入参数CurrentUser，shared_ptr<User>类型，当前用户
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
ControlerAbstractBase::ControlerAbstractBase(shared_ptr<User> CurrentUser)
{   
    m_pCurrentUser = CurrentUser; 
}

/******************************************************************************
【函数名称】~CollectorControl
【函数功能】CollectorControl类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
ControlerAbstractBase::~ControlerAbstractBase(){
    //2022-07-19删除
    //m_pCurrentUser = nullptr;
}

/******************************************************************************
【函数名称】DeleteYourself
【函数功能】删除一个已登录的用户
【参数】
    输入参数shared_ptr<UserManager> aUserManager，用来调用UserManager类的函数；
    输入参数shared_ptr<User> aUser，传入需要删除的User实例指针
【返回值】bool，成功执行删除操作则返回true；出现错误则输出报错信息并返回false
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
bool ControlerAbstractBase::DeleteYourself(shared_ptr<UserManager> aUserManager, 
    shared_ptr<User> aUser)
{
    try
    {
        aUserManager->Delete(aUser);
        return true;//成功执行删除操作则返回true
    }
    catch (const std::exception& e)//出现错误
    {
        std::cerr << e.what() << '\n';//输出报错信息
        return false;
    }
}


