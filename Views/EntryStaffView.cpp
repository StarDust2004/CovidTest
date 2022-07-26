/******************************************************************************
【文件名】EntryStaffView.cpp
【功能模块和目的】录入员界面类的的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include"../Models/User.hpp"
#include"../Models/UserManager.hpp"
#include"../Models/TubeManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/EntryStaffControl.hpp"
#include "EntryStaffView.hpp"
using namespace std;

/******************************************************************************
【函数名称】EntryStaffView
【函数功能】EntryStaffView类的构造函数，可以创建一个EntryStaffView类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
EntryStaffView::EntryStaffView()
{

}

/******************************************************************************
【函数名称】~EntryStaffView
【函数功能】EntryStaffView类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
EntryStaffView::~EntryStaffView(){

}

/******************************************************************************
【函数名称】ShowEntry
【函数功能】
    显示录入员界面：
    通过传入的User智能指针，生成EntryStaffControl的实例；
    然后调用EntryStaffControl里的函数，对录入员的输入做出回应。
【参数】
    输入参数pCurrentUser，当前登录的用户指针；
    输入参数aTubeManager，用于调用TubeManager的函数
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-20
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void EntryStaffView::ShowEntry(shared_ptr<User> pCurrentUser,
    shared_ptr<TubeManager> aTubeManager)
{
    bool Exist = false;
    string i;//用于读取录入员的选择
    string TubeID;//用于读取录入员输入的试管编号
    shared_ptr<Tube> aTube = nullptr;//用来接收录入员输入的试管编号对应的Tube实例的指针
    DateTime EntryTime;//用来暂时存储录入员输入的结果录入时间
    string Result;//用来暂时存储录入员输入的检测结果
    if (m_pEntryStaffControl == nullptr)//如果m_pEntryStaffControl为空
    {
        //创建EntryStaffControl的实例，存智能指针
        m_pEntryStaffControl = make_shared<EntryStaffControl>(pCurrentUser);
    }    
    cout << "**************************************************" << endl;
    cout << "录入员" << pCurrentUser->GetName() << ",您好！" << endl;
    while (!Exist == true)
    {
        cout << "**************************************************" << endl;
        cout << "返回上一页面请按0,开始录入测试结果请按1:" << endl;
        cin >> i;//读取录入员的选择
        if (i == "0")//返回上一页面
        {
            Exist = true;
        }
        else if (i == "1")//开始录入测试结果（结果录入日期时间、 阳性/阴性）
        {
            cout << "请输入试管编号(格式为“2000/01/01 00:00:00 000001”):" << endl;
            cin.ignore();//清除缓存
            getline(cin, TubeID);//用于读取录入员输入的试管编号
            //查找并接收录入员输入的试管编号对应的Tube实例的指针
            aTube = aTubeManager->SearchTube(TubeID);
            cout << "请输入结果录入日期时间(格式为“2000/01/01 00:00:00”):" << endl;
            cin >> EntryTime;//读取录入员输入的录入时间
            //将录入时间添加到指定试管对象中
            m_pEntryStaffControl->AddEntry(EntryTime, aTube);
            cout << "请输入检测结果(Positive/Negative):" << endl;
            string Result;//读取录入员输入的检测结果，以字符串形式暂存
            cin >> Result;
            if (Result == "Positive")//阳性
            {
                m_pEntryStaffControl->AddResult(TestResult::Positive, aTube);
            }
            else if (Result == "Negative")//阴性
            {
                m_pEntryStaffControl->AddResult(TestResult::Negative, aTube);
            }
            cout << "结果录入成功！"<< endl;
        }
        else//输入其他
        {
            cout << "指令无效" << endl;
        }
    }
}


