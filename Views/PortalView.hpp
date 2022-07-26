/******************************************************************************
【文件名】PortalView.hpp
【功能模块和目的】主界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef PortalView_hpp
#define PortalView_hpp

#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "AdminView.hpp"
#include "CollectorView.hpp"
#include "EntryStaffView.hpp"
#include "TesteeView.hpp"
using namespace std;

/*************************************************************************
【类名】PortalView
【功能】
    主界面类的操作：
    从LoginView（登录页面）进入主界面，主界面可以返回登录页面（退出当前登录）；
    主界面显示四种身份选择，从不同身份页面可以返回主界面。
【接口说明】
    构造函数PortalView();
    析构函数~PortalView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowPortal显示主界面并读入信息，根据用户选择切换到不同的身份页面；
    数据成员m_pAdminView，指向AdminView的实例；
    数据成员m_pCollectorView，指向CollectorView的实例；
    数据成员m_pEntryStaffView，指向EntryStaffView的实例；
    数据成员m_pTesteeView，指向TesteeView的实例
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class PortalView
{
public:
    //构造函数
    PortalView();
    //析构函数
    virtual ~PortalView();

    //显示主界面的函数
    //要能够判断传入的当前用户（m_pCurrentUser）有哪些权限
    //然后显示对应的身份选项
    //用户选择后，就跳转到所选身份对应的页面
    void ShowPortal(shared_ptr<User> pCurrentUser, 
        shared_ptr<TubeManager>& aTubeManager, 
        shared_ptr<UserManager>& aUserManager);
private:
    //AdminView的实例的智能指针
    shared_ptr<AdminView> m_pAdminView;
    //CollectorView的实例的智能指针
    shared_ptr<CollectorView> m_pCollectorView;
    //EntryStaffView的实例的智能指针
    shared_ptr<EntryStaffView> m_pEntryStaffView;
    //TesteeView的实例的智能指针
    shared_ptr<TesteeView> m_pTesteeView;
};//end class PortalView


#endif