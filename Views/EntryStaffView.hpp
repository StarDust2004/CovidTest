/******************************************************************************
【文件名】EntryStaffView.hpp
【功能模块和目的】录入员界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef EntryStaffView_hpp
#define EntryStaffView_hpp

#include"../Models/User.hpp"
#include"../Models/UserManager.hpp"
#include"../Models/TubeManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/EntryStaffControl.hpp"
using namespace std;

/*************************************************************************
【类名】EntryStaffView
【功能】
    录入员界面类的操作：
    当用户在PortalView（主界面）选择以录入员身份登录时，主界面跳转到录入员界面；
    录入员可以输入试管编号（生产日期+时间+6位数字组成的流水号）,
    并为该试管添加1个测试结果信息（结果录入日期时间、 阳性/阴性）。
【接口说明】
    构造函数EntryStaffView();
    析构函数~EntryStaffView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowEntry显示录入员界面；
    数据成员m_pEntryStaffControl指向EntryStaffControl的实例，方便调用
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
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