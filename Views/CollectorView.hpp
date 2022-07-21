#ifndef CollectorView_hpp
#define CollectorView_hpp

#include "../Models/User.hpp"
#include "../Controllers/ControlerAbstractBase.hpp"
#include "../Controllers/CollectorControl.hpp"
using namespace std;

//采集员界面
//当用户在PortalView（主界面）选择以采集员身份登录时，主界面跳转到采集员界面
//采集员可以输入试管编号（TubeNumber）、添加采样日期时间、被试者ID*n
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