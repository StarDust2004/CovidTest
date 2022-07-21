#include"../Models/User.hpp"
#include"../Models/UserManager.hpp"
#include"../Models/TubeManager.hpp"
#include "../Models/Constant.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/EntryStaffControl.hpp"
#include "EntryStaffView.hpp"
using namespace std;

//构造函数
EntryStaffView::EntryStaffView()
{

}

//析构函数
EntryStaffView::~EntryStaffView(){

}

//显示录入员界面
void EntryStaffView::ShowEntry(shared_ptr<User> pCurrentUser,
    shared_ptr<TubeManager> aTubeManager)
{
    bool Exist = false;
    unsigned int i;//用于读取录入员的选择
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
        if (i == 0)//返回上一页面
        {
            Exist = true;
        }
        else if (i == 1)//开始录入测试结果（结果录入日期时间、 阳性/阴性）
        {
            cout << "请输入试管编号(格式为“2000/01/01 00:00:00 000001”):" << endl;
            getline(cin, TubeID);//用于读取录入员输入的试管编号
            //查找并接收录入员输入的试管编号对应的Tube实例的指针
            aTube = aTubeManager->SearchTube(TubeID);
            cout << "请输入结果录入日期时间(格式为“2000/01/01 00:00:00 000001”):" << endl;
            cin >> EntryTime;//读取录入员输入的录入时间
            //将录入时间添加到指定试管对象中
            m_pEntryStaffControl->AddEntry(EntryTime, aTube);
            cout << "请输入检测结果(Positive/Negative):" << endl;
            string Result;//读取录入员输入的检测结果，以字符串形式暂存
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


