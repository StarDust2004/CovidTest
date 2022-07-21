#ifndef EntryStaffView_hpp
#define EntryStaffView_hpp

#include"../Models/User.hpp"
#include"../Models/UserManager.hpp"
#include"../Models/TubeManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/EntryStaffControl.hpp"
using namespace std;

//录入员界面
//当用户在PortalView（主界面）选择以录入员身份登录时，主界面跳转到录入员界面
//录入员可以输入试管编号（生产日期+时间+6位数字组成的流水号）,
//并为该试管添加1个测试结果信息（结果录入日期时间、 阳性/阴性）
class EntryStaffView
{
public:
    //构造函数
    EntryStaffView();
    //析构函数
    virtual ~EntryStaffView();
    //显示录入员界面
    void ShowEntry(shared_ptr<User> pCurrentUser, 
        shared_ptr<TubeManager> aTubeManager);
private:
    //EntryStaffControl的实例的智能指针
    shared_ptr<EntryStaffControl> m_pEntryStaffControl;

};//end class EntryStaffView

#endif