#include <string>
#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "AdminView.hpp"
#include "CollectorView.hpp"
#include "EntryStaffView.hpp"
#include "TesteeView.hpp"
#include "PortalView.hpp"
using namespace std;

//构造函数
PortalView::PortalView()
{

}

//析构函数
PortalView::~PortalView(){

}

//显示主界面的函数
//要能够判断传入的当前用户（m_pCurrentUser）有哪些权限
//然后显示对应的身份选项
//用户选择后，就跳转到所选身份对应的页面
void PortalView::ShowPortal(shared_ptr<User> pCurrentUser, 
    shared_ptr<TubeManager>& aTubeManager, 
    shared_ptr<UserManager>& aUserManager)
{
    //用来保存用户身份，方便检测
    unsigned int status = pCurrentUser->GetType();
    string s;//用于读入用户的选择
    if (status == 1)//只有被试者身份
    {
        if (m_pTesteeView == nullptr)//如果m_pTesteeView为空
        {
            //创建TesteeView的实例，将指针存入m_pTesteeView
            m_pTesteeView = make_shared<TesteeView>();
        }
        m_pTesteeView->ShowTest(pCurrentUser);
    }
    else//还有其他身份
    {
        bool Exist = false;
        cout << "**************************************************" << endl;
        cout << pCurrentUser->GetName() << ",您好！" << endl;
        while (!Exist == true)
        {            
            cout << "请选择一个身份进行登录(按0退出登录):" << endl;
            if (status & 2)//具有管理员身份
            {
                cout << "选择管理员身份请按A" << endl;
            }
            if (status & 4)//具有采集员身份
            {
                cout << "选择采集员身份请按C" << endl;
            }
            if (status & 8)//具有录入员身份
            {
                cout << "选择录入员身份请按E" << endl;
            }
            //必定具有被试者身份
            cout << "选择被试者身份请按T" << endl;

            cin >> s;//读取用户的选择

            if (s == "0")//返回login界面，即退出此次登录
            {
                Exist = true;
            }

            //具有管理员身份并选择以管理员身份登录
            else if ((s == "A") && (status & 2))
            {
                if (m_pAdminView == nullptr)//如果m_pAdminView为空
                {
                    //创建一个AdminView的实例,将指针存入m_pAdminView
                    m_pAdminView = make_shared<AdminView>();
                }
                //跳转到AdminView管理员界面
                m_pAdminView->ShowAdmin(pCurrentUser, aUserManager);
            }

            //具有采集员身份并选择以采集员身份登录
            else if ((s == "C") && (status & 4))
            {
                if (m_pCollectorView == nullptr)//如果m_pCollectorView为空
                {
                    //创建一个CollectorView的实例,将指针存入m_pCollectorView
                    m_pCollectorView = make_shared<CollectorView>();
                }
                //跳转到CollectorView采集员界面
                m_pCollectorView->ShowCollector(pCurrentUser, aTubeManager);
            }

            //具有录入员身份并选择以录入员身份登录
            else if ((s == "E") && (status & 8))
            {
                if (m_pEntryStaffView == nullptr)//如果m_pEntryStaffView为空
                {
                    //创建一个EntryStaffView的实例,将指针存入m_pEntryStaffView
                    m_pEntryStaffView = make_shared<EntryStaffView>();
                }
                //跳转到EntryStaffView录入员界面
                m_pEntryStaffView->ShowEntry(pCurrentUser, aTubeManager);
            }
            
            //选择以被试者身份登录（必定具有被试者身份）
            else if (s == "T")
            {
                if (m_pTesteeView == nullptr)//如果m_pTesteeView为空
                {
                    //创建TesteeView的实例，将指针存入m_pTesteeView
                    m_pTesteeView = make_shared<TesteeView>();
                }
                //跳转到TesteeView被试者界面
                m_pTesteeView->ShowTest(pCurrentUser);
            }

            else//其他不合规输入
            {
                cout << "指令无效" << endl;
            }
        } 
    }
}

/*
//登出函数：退出当前登录，保存信息，现实登出界面
void PortalView::Logout()
{
    //保存信息
    m_pUserManager->SaveToFile(UsersFileName);
    m_pTubeManager->SaveToFile(TubesFileName);
    //显示登出界面
    //按下任意键后清屏
    system("pause");
    system("cls");
    cout << "您已成功退出登录." << endl;
}
*/