/******************************************************************************
【文件名】CollectorView.hpp
【功能模块和目的】采集员界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef CollectorView_hpp
#define CollectorView_hpp

#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/CollectorControl.hpp"
using namespace std;

/*************************************************************************
【类名】CollectorView
【功能】
    采集员界面类的操作：
    当用户在PortalView（主界面）选择以采集员身份登录时，主界面跳转到采集员界面
    采集员可以输入试管编号（TubeNumber）、添加采样日期时间、被试者ID*n
【接口说明】
    构造函数CollectorView();
    析构函数~CollectorView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowCollector显示采集员界面；
    函数CheckID判断输入的身份证号是否符合规范；
    数据成员m_pCollectorControl指向CollectorControl的实例，方便调用
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class CollectorView
{
public:
    //构造函数
    CollectorView();
    //析构函数
    virtual ~CollectorView();
    //显示采集员界面
    void ShowCollector(shared_ptr<User> pCurrentUser, 
        shared_ptr<TubeManager> aTubeManager);
    //判断输入的身份证号是否符合规范的函数
    bool CheckID(const string& ID);
private:
    //CollectorControl的实例的智能指针
    shared_ptr<CollectorControl> m_pCollectorControl;
};//end class CollectorView

#endif