/******************************************************************************
【文件名】TesteeView.cpp
【功能模块和目的】被试者界面类的的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include"../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/TesteeControl.hpp"
#include "../Models/Constant.hpp"
#include "TesteeView.hpp"
using namespace std;

/******************************************************************************
【函数名称】TesteeView
【函数功能】TesteeView类的构造函数，可以创建一个TesteeView类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
TesteeView::TesteeView()
{

}

/******************************************************************************
【函数名称】~TesteeView
【函数功能】TesteeView类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
TesteeView::~TesteeView(){

}

/******************************************************************************
【函数名称】ShowTest
【函数功能】显示最近一次的检测结果
【参数】
    输入参数pCurrentUser，当前用户实例；
    输入参数aTubeManager，用于调用TubeManager成员
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void TesteeView::ShowTest(shared_ptr<User> pCurrentUser,
    shared_ptr<TubeManager> aTubeManager)
{
    if (m_pTesteeControl == nullptr)//如果m_pTesteeControl为空
    {
        //TesteeControl的实例的智能指针
        m_pTesteeControl = make_shared<TesteeControl>(pCurrentUser);
    }
    
    cout << "**************************************************" << endl;
    cout << pCurrentUser->GetName() << ",您好！" << endl;
    cout << "您最近一次核酸检测结果如下:" << endl;

    //查找到结果录入时间最近的那个试管
    try
    {

        m_pTesteeControl->SearchLatest(aTubeManager, pCurrentUser);

        cout << "采样时间:" << m_pTesteeControl->GetLatestSample() << endl;
        cout << "结果录入时间:" << m_pTesteeControl->GetLatestEntry() << endl;
        if (m_pTesteeControl->GetLatestResult() == TestResult::Positive)
        {
            cout << "核酸检测结果:阳性" << endl;
        }
        if (m_pTesteeControl->GetLatestResult() == TestResult::Negative)
        {
            cout << "核酸检测结果:阴性" << endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';//输出报错信息
    }
    
    cout << "按任意键返回上一界面" << endl;
    system("pause");
}

