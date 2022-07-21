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

//构造函数
UserRecord::UserRecord(const string& TubeID, const string& UserID)
{
    m_TubeID = TubeID;
    m_UserID = UserID;
}

//析构函数
UserRecord::~UserRecord(){

}

//读取TubeID
string UserRecord::GetTubeID() const
{
    return m_TubeID;
}

//读取UserID
string UserRecord::GetUserID() const
{
    return m_UserID;
}
