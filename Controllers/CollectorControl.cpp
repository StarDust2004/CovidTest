/******************************************************************************
【文件名】CollectorControl.cpp
【功能模块和目的】采集员控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "../Models/TubeManager.hpp"
#include "../Models/UserRecord.hpp"
#include "ControlerAbstractBase.hpp"
#include "CollectorControl.hpp"
using namespace std;

/******************************************************************************
【函数名称】CollectorControl
【函数功能】构造CollectorControl类的一个实例
【参数】
    输入参数CurrentUser，shared_ptr<User>类型，当前用户
    输入参数aTube，shared_ptr<Tube>类型，默认值为nullptr
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
CollectorControl::CollectorControl
    (shared_ptr<User> CurrentUser, shared_ptr<Tube> aTube) 
    : ControlerAbstractBase(CurrentUser)
{
    m_pTube = aTube;
}

/******************************************************************************
【函数名称】~CollectorControl
【函数功能】CollectorControl类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
CollectorControl::~CollectorControl()
{
    //m_pTube = nullptr;
}

/******************************************************************************
【函数名称】SetTube
【函数功能】为私有数据成员m_pTube赋值
【参数】输入参数aTube,shared_ptr<Tube>类型
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void CollectorControl::SetTube(shared_ptr<Tube> aTube)
{
    m_pTube = aTube;
}

/******************************************************************************
【函数名称】AddTube
【函数功能】输入试管编号（生产日期时间+六位数流水号）,创建一个Tube类的对象,并将其指针
           添加到试管列表里去
【参数】
    输入参数aTubeManager，shared_ptr<TubeManager>类型，用来调用TubeManager类的函数；
    输入参数TubeNumber,string类型,传入采集员输入的试管编号
【返回值】shared_ptr<Tube>,返回新创建的这个Tube实例的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<Tube> CollectorControl::AddTube
    (shared_ptr<TubeManager> aTubeManager, const string& TubeNumber)
{
    shared_ptr<Tube> aTube = aTubeManager->AddTube(TubeNumber);
    return aTube;
}

/******************************************************************************
【函数名称】AddSample
【函数功能】传入试管指针，向其添加一个采样日期时间
【参数】
    输入参数DateTime SampleTime，传入一个采样日期时间；
    输入参数shared_ptr<Tube> aTube，传入需要添加采样时间的Tube实例的指针
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void CollectorControl::AddSample(const DateTime& SampleTime, 
    shared_ptr<Tube> aTube)
{
    aTube->AddSamplingTime(SampleTime);
}

/******************************************************************************
【函数名称】AddTestee
【函数功能】
    传入试管指针，向其添加一个被试者身份证号；
    调用函数AddRecord,用这个身份证号和对应试管编号创建一个UserRecord实例，将该实例的
    指针添加到TubeManager中的m_AllRecords列表中。
【参数】
    输入参数shared_ptr<TubeManager> aTubeManager，用来调用TubeManager中的函数；
    输入参数string IDNumber，传入一个被试者身份证号；
    输入参数shared_ptr<Tube> aTube，传入需要添加被试者身份证号的Tube实例的指针。
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void CollectorControl::AddTestee(shared_ptr<TubeManager> aTubeManager, 
    const string& IDNumber, shared_ptr<Tube> aTube)
{
    aTube->AddIDNumber(IDNumber);
    AddRecord(aTubeManager, IDNumber, aTube->GetTubeNumber());
}

/******************************************************************************
【函数名称】AddRecord
【函数功能】
    将一条被试者身份证号和对应试管编号的信息添加到一个新的UserRecord实例；
    并将这个新的UserRecord实例的指针添加到TubeManager中的m_AllRecords列表中。
【参数】
    输入参数shared_ptr<TubeManager> aTubeManager，用来调用TubeManager中的函数；
    输入参数string IDNumber，传入一个被试者身份证号；
    输入参数string TubeNumber，传入对应的试管编号。
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-18
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void CollectorControl::AddRecord(shared_ptr<TubeManager> aTubeManager, 
    const string& IDNumber, const string& TubeNumber)
{
    //将一条被试者ID&试管编号的信息添加到一个新的UserRecord实例;
    shared_ptr<UserRecord> aUserRecord = 
        make_shared<UserRecord>(TubeNumber, IDNumber);
    //并将这个新的UserRecord实例添加到RecordManager中的m_AllRecords列表中
    aTubeManager->AddUserRecord(aUserRecord);
}
