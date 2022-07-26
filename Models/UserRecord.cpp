/******************************************************************************
【文件名】UserRecord.cpp
【功能模块和目的】存储核酸检测信息的类的的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include"DateTime.hpp"
#include"Constant.hpp"
#include"User.hpp"
#include"UserRecord.hpp"
using namespace std;

/******************************************************************************
【函数名称】UserRecord
【函数功能】UserRecord类的构造函数，可以创建一个UserRecord类的实例
【参数】
    输入参数TubeID，传入试管编号；
    输入参数UserID，传入一个对应的被试者身份证号
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
UserRecord::UserRecord(const string& TubeID, const string& UserID)
{
    m_TubeID = TubeID;
    m_UserID = UserID;
}

/******************************************************************************
【函数名称】~UserRecord
【函数功能】UserRecord类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
UserRecord::~UserRecord(){

}

/******************************************************************************
【函数名称】GetTubeID
【函数功能】读取TubeID
【参数】无
【返回值】string，返回m_TubeID
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
string UserRecord::GetTubeID() const
{
    return m_TubeID;
}

/******************************************************************************
【函数名称】GetUserID
【函数功能】读取UserID
【参数】无
【返回值】string，返回m_UserID
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
string UserRecord::GetUserID() const
{
    return m_UserID;
}
