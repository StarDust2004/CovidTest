#ifndef PortalView_hpp
#define PortalView_hpp

#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "AdminView.hpp"
#include "CollectorView.hpp"
#include "EntryStaffView.hpp"
#include "TesteeView.hpp"
using namespace std;

//主界面
//从LoginView（登录页面）进入主界面
//主界面显示四种身份选择，从不同身份页面可以返回主界面
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

    /*
    //返回
    void Logout();
    */
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