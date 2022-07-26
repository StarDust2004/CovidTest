/******************************************************************************
【文件名】ControlerAbstractBase.hpp
【功能模块和目的】控制器的抽象基类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】
    2022-07-19 由黄润一删除部分成员 
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef ControlerAbstractBase_hpp
#define ControlerAbstractBase_hpp

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
using namespace std;

/*************************************************************************
【类名】ControlerAbstractBase
【功能】控制器抽象基类的操作
【接口说明】
    构造函数ControlerAbstractBase(shared_ptr<User> CurrentUser);
    析构函数~ControlerAbstractBase(),作为控制器的基类，析构函数为虚函数；
    函数DeleteYourself可以用来删除一个已登录的用户；
    私有数据成员m_pCurrentUser指向当前登录的用户（当前User实例）
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】
    2022-07-19 由黄润一删除部分成员 
    2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class ControlerAbstractBase
{
public:
    //构造函数
    ControlerAbstractBase(shared_ptr<User> CurrentUser);
    //析构函数
    virtual ~ControlerAbstractBase();

    //删除一个已登录的用户
    bool DeleteYourself(shared_ptr<UserManager> aUserManager,
        shared_ptr<User> aUser);
protected:
    //Current user当前用户
    shared_ptr<User> m_pCurrentUser;

    /*2022-7-19删除
    //file names
    string m_UsersFileName;
    string m_TubesFileName;
    */
};//end ControlerAbstractBase

/*2022-07-19删除
//marco trick
#define enum_to_string(x) #x

//controler函数的返回值
enum class ControlerRet
{
    NO_USER,
    WRONG_PASSWORD,
    USER_Current,
    USER_CREATED,
    DUPLICATE_USER//重复的用户
};

//较短的类型名
using RES = ControlerRet;

//controler函数的返回值字符串
const string ResStr[]
{
  enum_to_string(NO_USER),
  enum_to_string(WRONG_PASSWORD),
  enum_to_string(USER_Current),
  enum_to_string(USER_CREATED),
  enum_to_string(DUPLICATE_USER),
};
*/

#endif