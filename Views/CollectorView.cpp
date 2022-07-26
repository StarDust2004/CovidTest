/******************************************************************************
【文件名】CollectorView.cpp
【功能模块和目的】采集员界面类的的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/CollectorControl.hpp"
#include "CollectorView.hpp"
#include <stdexcept>
using namespace std;

/******************************************************************************
【函数名称】CollectorView
【函数功能】CollectorView类的构造函数，可以创建一个CollectorView类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
CollectorView::CollectorView()
{

}

/******************************************************************************
【函数名称】~CollectorView
【函数功能】CollectorView类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
CollectorView::~CollectorView(){

}

/******************************************************************************
【函数名称】ShowCollector
【函数功能】
    显示采集员界面：
    通过传入的User智能指针，生成CollectorControl的实例；
    然后调用CollectorControl里的函数，对录入员的输入做出回应。
【参数】
    输入参数pCurrentUser，当前登录的用户指针；
    输入参数aTubeManager，用于调用TubeManager的函数
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void CollectorView::ShowCollector(shared_ptr<User> pCurrentUser, 
    shared_ptr<TubeManager> aTubeManager)
{
    bool Exist = false;
    string i;//用于读取采集员的选择
    string UserID;//用于读取采集员输入的被试者的身份证号
    string TubeID;//用于读取采集员输入的试管编号
    DateTime Sample;//用于读取采集员输入的采样日期时间
    if (m_pCollectorControl == nullptr)//如果m_pCollectorControl为空
    {
        //创建CollectorControl的实例的智能指针
        m_pCollectorControl = make_shared<CollectorControl>(pCurrentUser);
    }    
    cout << "**************************************************" << endl;
    cout << "采集员" << pCurrentUser->GetName() << ",您好！" << endl;
    while (!Exist == true)
    {
        cout << "**************************************************" << endl;
        cout << "返回上一界面请按0,开始采集检测信息请按1:" << endl;
        cin >> i;//读取管理员的选择
        if (i == "0")//返回上一界面
        {
            Exist = true;
        }
        else if (i == "1")//开始采集检测信息
        {
            cout << "请输入试管编号(格式为“2000/01/01 00:00:00 000001”):" << endl;

            cin.ignore();//清除缓存
            getline(cin, TubeID);//用于读取采集员输入的试管编号

            shared_ptr<Tube> aTube;//用来暂时存储采集员创建的Tube实例指针
            aTube = m_pCollectorControl->AddTube(aTubeManager, TubeID);
            m_pCollectorControl->SetTube(aTube);//为m_pTube赋值

            cout << "请输入采样日期时间(格式为“2000/01/01 00:00:00”):" << endl;
            //cin.ignore();//清除缓存
            cin >> Sample;//读取采集员输入的采样日期时间
            m_pCollectorControl->AddSample(Sample, aTube);//添加采样日期时间

            cout << "请输入被试者身份证号:" << endl;
            //cin.ignore();//清除缓存
            cin >> UserID;//读取采集员输入的被试者的身份证号
            //添加一个被试者身份证号
            m_pCollectorControl->AddTestee(aTubeManager, UserID, aTube);
            cout << "添加成功！" << endl;

            bool ifAdd = true;
            while (ifAdd == true)
            {
                cout << "请继续添加被试者身份证号，或输入0退出:" << endl;
                //cin.ignore();//清除缓存
                cin >> UserID;//读取采集员输入的被试者的身份证号
                if (UserID == "0")
                {
                    ifAdd = false;
                }
                else if (CheckID(UserID) == false)//输入的身份证号不符合规范
                {
                    cout << "您输入的身份证号不符合规范,请重新输入:" << endl;
                    continue;
                }
                else
                {
                    //添加一个被试者身份证号
                    m_pCollectorControl->AddTestee(aTubeManager, UserID, aTube);
                    cout << "添加成功！" << endl;
                }                    
            }
        }
        else
        {
            cout << "指令无效" << endl;
        }
    }
}

/******************************************************************************
【函数名称】CheckID
【函数功能】判断输入的身份证号是否符合规范
【参数】输入参数ID，传入需要判断规范性的身份证号
【返回值】bool，合规则返回true，否则返回false
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
bool CollectorView::CheckID(const string& ID)
{
    //身份证号必须是18位
    if (ID.size() != 18)
    {
        return false;
    }
    else
    {
        int i = 0;
        //前17位必须全是数字
        for (i = 0; i < 17; i++)
        {
            if (ID[i] < '0' || ID[i] > '9')
            {
                return false;
            }
        }
        //第18位应为数字或者'x'
        if ((ID[17] < '0' || ID[17] > '9') && (ID[17] != 'x'))
        {
            return false;
        }
        return true;
    }
}


