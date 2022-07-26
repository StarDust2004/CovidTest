/******************************************************************************
【文件名】TesteeView.hpp
【功能模块和目的】被试者界面类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef TesteeView_hpp
#define TesteeView_hpp

#include"../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/TesteeControl.hpp"
using namespace std;

/*************************************************************************
【类名】TesteeView
【功能】
    被试者界面类的操作:
    当用户在PortalView（主界面）选择以被试者身份登录时，主界面跳转到被试者界面;
    被试者界面自动显示最近一次的检测结果（采样时间、结果录入时间、阳性/阴性）
【接口说明】
    构造函数TesteeView();
    析构函数~TesteeView()，考虑后续扩展的可能性，写为虚函数；
    函数ShowTest显示最近一次检测结果;
    数据成员m_pTesteeControl，TesteeControl的实例的智能指针，方便进入注册界面
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class TesteeView
{
public:
    //构造函数
    TesteeView();
    //析构函数
    virtual ~TesteeView();

    //显示最近一次检测结果
    //通过传入的已登录用户指针，在内部生成TesteeControl的实例，
    //从而调用TesteeControl里的函数
    //然后显示检测结果
    void ShowTest(shared_ptr<User> pCurrentUser, 
        shared_ptr<TubeManager> aTubeManager);
private:
    //TesteeControl的实例的智能指针
    shared_ptr<TesteeControl> m_pTesteeControl;

};//end class TesteeView


#endif