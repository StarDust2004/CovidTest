#include"../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/TesteeControl.hpp"
#include "../Models/Constant.hpp"
#include "TesteeView.hpp"
using namespace std;

//构造函数
TesteeView::TesteeView()
{

}

//析构函数
TesteeView::~TesteeView(){

}

//显示最近一次检测结果
//通过传入的已登录用户指针，在内部生成TesteeControl的实例，
//从而调用TesteeControl里的函数
//然后显示检测结果
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

