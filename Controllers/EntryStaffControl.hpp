/******************************************************************************
【文件名】EntryStaffControl.hpp
【功能模块和目的】录入员控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef EntryStaffControl_hpp
#define EntryStaffControl_hpp

#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "ControlerAbstractBase.hpp"
#include "../Models/Constant.hpp"
using namespace std;

/*************************************************************************
【类名】EntryStaffControl
【功能】录入员控制器类的操作
【接口说明】
    构造函数EntryStaffControl(shared_ptr<User> CurrentUser);
    析构函数~EntryStaffControl(),考虑到后续扩展的可能性，写为虚函数；
    函数AddEntry向传入的试管添加一个结果录入日期时间；
    函数AddResult向传入的试管添加一个核酸检测结果（阴性/阳性）
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-17
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class EntryStaffControl : public ControlerAbstractBase
{
public:
    //构造函数
    EntryStaffControl(shared_ptr<User> CurrentUser);
    //析构函数
    virtual ~EntryStaffControl();
    
    //传入试管指针，向其添加结果录入日期时间
    void AddEntry(const DateTime& EntryTime, shared_ptr<Tube> aTube);
    //传入试管指针，向其添加核酸检测结果（阴性/阳性）
    void AddResult(const TestResult& Result, shared_ptr<Tube> aTube);
};

#endif