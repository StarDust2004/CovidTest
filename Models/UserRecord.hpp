/******************************************************************************
【文件名】UserRecord.hpp
【功能模块和目的】存储核酸检测信息的类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#ifndef UserRecord_hpp
#define UserRecord_hpp

#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include"DateTime.hpp"
#include"Constant.hpp"
#include"User.hpp"
using namespace std;

/*************************************************************************
【类名】UserRecord
【功能】
    存储核酸检测信息的类的操作。
    这个类用来存储每一个核酸检测试管编号和一条对应的用户身份证号，便于查找指定
    被试者（testee）的最近一次核酸检测结果
【接口说明】
    构造函数UserRecord(const string& TubeID, const string& UserID);
    析构函数~UserRecord()，考虑后续扩展的可能性，写为虚函数；
    函数GetTubeID读取试管编号m_TubeID；
    函数GetUserID读取被试者身份证号m_UserID;
    数据成员m_TubeID，试管编号；
    数据成员m_UserID，被试者身份证号
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
*************************************************************************/
class UserRecord
{
public:
    //默认构造函数delete
    UserRecord() = delete;
    //构造函数
    UserRecord(const string& TubeID, const string& UserID);
    //析构函数
    virtual ~UserRecord();
    //读取TubeID
    string GetTubeID() const;
    //读取UserID
    string GetUserID() const;
private:
    string m_TubeID;//试管编号
    string m_UserID;//用户ID（身份证号）
};

#endif