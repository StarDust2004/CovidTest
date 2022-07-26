/******************************************************************************
【文件名】CollectorControl.hpp
【功能模块和目的】采集员控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef CollectorControl_hpp
#define CollectorControl_hpp

#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "../Models/TubeManager.hpp"
#include "../Models/UserRecord.hpp"
#include "ControlerAbstractBase.hpp"
using namespace std;

/*************************************************************************
【类名】CollectorControl
【功能】采集员控制器类的操作
【接口说明】
    构造函数CollectorControl(shared_ptr<User> CurrentUser, 
        shared_ptr<Tube> aTube = nullptr);
    析构函数~CollectorControl(),考虑到后续扩展的可能性，写为虚函数；
    函数SetTube为m_pTube赋值;
    函数AddTube创建一个Tube类对象的实例，并将指针添加到试管列表里去，
    返回该对象指针;
    函数AddSample向传入的试管添加一个采样日期时间；
    函数AddTestee向传入的试管添加一个被试者身份证号；
    私有数据成员m_pTube用来存储采集员创建的试管类对象实例的指针；
    私有成员函数AddRecord将一条被试者身份证号及对应试管编号的信息添加
    到UserRecord里；
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class CollectorControl : public ControlerAbstractBase
{
public:
    //构造函数
    CollectorControl(shared_ptr<User> CurrentUser, shared_ptr<Tube> aTube = nullptr);
    //析构函数
    virtual ~CollectorControl();
    
    //为m_pTube赋值
    void SetTube(shared_ptr<Tube> aTube);
    //输入试管编号（生产日期时间+六位数流水号）
    //创建一个Tube类的对象,并添加到试管列表里去
    shared_ptr<Tube> AddTube(shared_ptr<TubeManager> aTubeManager, 
        const string& TubeNumber);
    //传入试管指针，向其添加采样日期时间
    void AddSample(const DateTime& SampleTime, shared_ptr<Tube> aTube);
    //传入试管指针，向其添加被试者身份证号
    void AddTestee(shared_ptr<TubeManager> aTubeManager, 
        const string& IDNumber, shared_ptr<Tube> aTube);
private:
    shared_ptr<Tube> m_pTube;//用来存储采集员创建的试管类对象实例的指针

    //将一条被试者ID&试管编号的信息添加到UserRecord里
    void AddRecord(shared_ptr<TubeManager> aTubeManager, 
        const string& IDNumber, const string& TubeNumber);
};

#endif