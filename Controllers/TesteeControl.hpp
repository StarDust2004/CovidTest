/******************************************************************************
【文件名】TesteeControl.hpp
【功能模块和目的】被试者控制器类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-19 由黄润一删改了部分功能
    2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef TesteeControl_hpp
#define TesteeControl_hpp

#include "../Models/User.hpp"
#include "../Models/Tube.hpp"
#include "ControlerAbstractBase.hpp"
#include "../Models/Constant.hpp"
#include "../Models/UserRecord.hpp"
#include "../Models/TubeManager.hpp"
using namespace std;

/*************************************************************************
【类名】TesteeControl
【功能】被试者控制器类的操作
【接口说明】
    构造函数TesteeControl(shared_ptr<User> CurrentUser);
    析构函数~TesteeControl(),考虑到后续扩展的可能性，写为虚函数；
    函数SearchLatest遍历m_TubeList，查找到含有该被试者的结果录入时间最近的
    那个试管；
    函数GetLatestSample读取最近采样日期时间；
    函数GetLatestEntry读取最近结果录入日期时间；
    函数GetLatestResult读取最近核酸检测结果；
    数据成员m_TubeList用来存符合条件的Tube的智能指针的动态数组;
    数据成员m_LatestTest用来存储该被试者最近一次的检测结果所在的试管指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-19 由黄润一删改了部分功能
    2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class TesteeControl : public ControlerAbstractBase
{
public:
    //构造函数
    TesteeControl(shared_ptr<User> CurrentUser);
    //析构函数
    virtual ~TesteeControl();

    //遍历m_TubeList，查找到结果录入时间最近的那个试管
    //将该试管指针存入m_LatestTest中
    void SearchLatest(shared_ptr<TubeManager> aTubeManager, 
        shared_ptr<User> pCurrentUser);

    //读取最近采样日期时间
    DateTime GetLatestSample() const;
    //读取最近结果录入时间
    DateTime GetLatestEntry() const;
    //读取最近核酸检测结果
    TestResult GetLatestResult() const;

    /*2022-07-19删除
    //在UserRecord中查找指定被试者的身份证号:
    //遍历RecordList,
    //将每个符合条件的测试信息的指针存入m_Records中
    void SearchID(const string& IDNumber);
    */
private:
    //用来存符合条件的Tube的智能指针的动态数组
    vector<shared_ptr<Tube>> m_TubeList;

    //用来存储指定被试者最近一次的检测结果所在的试管指针
    shared_ptr<Tube> m_LatestTest;

    /*2022-07-19删除
   //用于存储m_IDList中有该被试者的Tube对象
   vector<shared_ptr<Tube>> m_Tubes;
   //用来存储有该被试者的测试信息对象（UserRecord对象）
   vector<shared_ptr<UserRecord>> m_Records;
   */
};//end class TesteeControl

#endif