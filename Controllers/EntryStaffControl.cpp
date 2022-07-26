/******************************************************************************
【文件名】EntryStaffControl.cpp
【功能模块和目的】录入员控制器类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "ControlerAbstractBase.hpp"
#include "../Models/Constant.hpp"
#include "EntryStaffControl.hpp"
using namespace std;

/******************************************************************************
【函数名称】EntryStaffControl
【函数功能】EntryStaffControl类的构造函数，可以创建EntryStaffControl类的一个实例
【参数】输入参数shared_ptr<User> CurrentUser
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
EntryStaffControl::EntryStaffControl(shared_ptr<User> CurrentUser) 
    : ControlerAbstractBase(CurrentUser)
{

}

/******************************************************************************
【函数名称】~EntryStaffControl
【函数功能】EntryStaffControl类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
EntryStaffControl::~EntryStaffControl() {
    
}

/******************************************************************************
【函数名称】AddEntry
【函数功能】传入试管指针，向其添加一个结果录入日期时间
【参数】
    输入参数DateTime EntryTime，传入一个结果录入日期时间；
    输入参数shared_ptr<Tube> aTube，传入需要添加录入时间的Tube实例的指针
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void EntryStaffControl::AddEntry(const DateTime& EntryTime, shared_ptr<Tube> aTube)
{
    aTube->AddEntryTime(EntryTime);
}

/******************************************************************************
【函数名称】AddResult
【函数功能】传入试管指针，向其添加一个核酸检测结果（阴性/阳性）
【参数】
    输入参数TestResult Result，传入一个核酸检测结果（阴性/阳性）；
    输入参数shared_ptr<Tube> aTube，传入需要添加核酸检测结果的Tube实例的指针
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void EntryStaffControl::AddResult(const TestResult& Result, shared_ptr<Tube> aTube)
{
    aTube->AddResult(Result);
}