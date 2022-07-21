#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/CollectorControl.hpp"
#include "CollectorView.hpp"
using namespace std;

//构造函数
CollectorView::CollectorView()
{

}

//析构函数
CollectorView::~CollectorView(){

}

//显示采集员界面
void CollectorView::ShowCollector(shared_ptr<User> pCurrentUser, 
    shared_ptr<TubeManager> aTubeManager)
{
    bool Exist = false;
    unsigned int i;//用于读取采集员的选择
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
        if (i == 0)//返回上一界面
        {
            Exist = true;
        }
        else if (i == 1)//开始采集检测信息
        {
            cout << "请输入试管编号(格式为“2000/01/01 00:00:00 000001”):" << endl;
            getline(cin, TubeID);//用于读取采集员输入的试管编号
            shared_ptr<Tube> aTube;//用来暂时存储采集员创建的Tube实例指针
            aTube = m_pCollectorControl->AddTube(aTubeManager, TubeID);
            m_pCollectorControl->SetTube(aTube);//为m_pTube赋值
            cout << "请输入采样日期时间(格式为“2000/01/01 00:00:00”):" << endl;
            cin >> Sample;//读取采集员输入的采样日期时间
            m_pCollectorControl->AddSample(Sample, aTube);//添加采样日期时间
            cout << "请输入被试者身份证号:" << endl;
            cin >> UserID;//读取采集员输入的被试者的身份证号
            //添加一个被试者身份证号
            m_pCollectorControl->AddTestee(aTubeManager, UserID, aTube);
            cout << "请继续添加被试者身份证号,输入0退出:" << endl;
            bool ifAdd = true;
            while (ifAdd == true)
            {
                cin >> UserID;//读取采集员输入的被试者的身份证号
                if (UserID == "0")
                {
                    ifAdd = false;
                }
                else
                {
                    if (CheckID(UserID) == false)//输入的身份证号不符合规范
                    {
                        cout << "您输入的身份证号不符合规范,请重新输入:" << endl;
                        continue;
                    }
                    else
                    {
                        //添加一个被试者身份证号
                        m_pCollectorControl->AddTestee(aTubeManager, UserID, aTube);
                    }                    
                }
            }
        }
        else
        {
            cout << "指令无效" << endl;
        }

    }
}

//判断输入的身份证号是否符合规范的函数
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


