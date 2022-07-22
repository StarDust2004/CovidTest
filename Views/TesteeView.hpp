#ifndef TesteeView_hpp
#define TesteeView_hpp

#include"../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/TesteeControl.hpp"
using namespace std;

//被试者界面
//当用户在PortalView（主界面）选择以被试者身份登录时，主界面跳转到被试者界面
//被试者界面自动显示最近一次的检测结果（采样时间、结果录入时间、阳性/阴性）
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
    //CollectorControl的实例的智能指针
    shared_ptr<TesteeControl> m_pTesteeControl;


};//end class TesteeView


#endif