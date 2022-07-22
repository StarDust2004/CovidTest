/******************************************************************************
【文件名】TesteeControl.cpp
【功能模块和目的】被试者控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "TesteeControl.hpp"
#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "ControlerAbstractBase.hpp"
#include "../Models/Constant.hpp"
#include "../Models/UserRecord.hpp"
#include "../Models/TubeManager.hpp"
#include <algorithm>
using namespace std;

/******************************************************************************
【函数名称】TesteeControl
【函数功能】TesteeControl类的构造函数，可以创建TesteeControl类的一个实例
【参数】输入参数shared_ptr<User> CurrentUser
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
TesteeControl::TesteeControl(shared_ptr<User> CurrentUser) 
    : ControlerAbstractBase(CurrentUser) {
    m_LatestTest = nullptr;  
}

/******************************************************************************
【函数名称】~TesteeControl
【函数功能】TesteeControl类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
TesteeControl::~TesteeControl() {
    
}

/*
//遍历RecordList,
//将每个符合条件的测试信息的指针存入m_Records中
void TesteeControl::SearchID(const string& IDNumber)
{
    //遍历UserRecord列表m_RecordList
    for (const auto& n : UserRecord::m_RecordList)
    {
        //如果某个UserRecord对象的UserID符合；
        if (n->GetUserID() == IDNumber)
        {
            //就将其指针传入m_Records中
            m_Records.push_back(n);
        }
    }
}
*/

/******************************************************************************
【函数名称】SearchLatest
【函数功能】
    遍历m_TubeList，查找到该被试者的最近结果录入时间对应的那个Tube实例的指针，
    存入m_LatestTest中。
【参数】无
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void TesteeControl::SearchLatest()
{
    DateTime Latest(1900, 1, 1, 0, 0, 0);
    //遍历m_TubeList列表
    for (const auto& n : m_TubeList)
    {
        //查找到结果录入时间EntryTime最近（最大）的那一个试管
        if (n->GetEntryTime() >= Latest)
        {
            //不断更新Latest（最近时间）、m_LatestTest（最近测试的试管的指针）
            Latest = n->GetEntryTime();
            m_LatestTest = n;
        }
    }
    //debuging:
    if (m_LatestTest == nullptr)//暂时没有进行过核酸检测
    {
        throw invalid_argument("No Result Yet");
    }
}

/******************************************************************************
【函数名称】GetLatestSample
【函数功能】读取最近采样日期时间
【参数】无
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
DateTime TesteeControl::GetLatestSample() const
{
    return m_LatestTest->GetSamplingTime();
}

/******************************************************************************
【函数名称】GetLatestEntry
【函数功能】读取最近结果录入时间
【参数】无
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
DateTime TesteeControl::GetLatestEntry() const
{
    return m_LatestTest->GetEntryTime();
}

/******************************************************************************
【函数名称】GetLatestResult
【函数功能】读取最近核酸检测结果
【参数】无
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
TestResult TesteeControl::GetLatestResult() const
{
    return m_LatestTest->GetResult();
}
