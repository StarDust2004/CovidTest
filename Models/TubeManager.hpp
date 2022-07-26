/******************************************************************************
【文件名】TubeManager.hpp
【功能模块和目的】管理Tube类的数据和UserRecord类的数据的类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-21 由黄润一添加、修改了注释
    2022-07-22 由黄润一增加了函数AddRecord
******************************************************************************/
#ifndef TubeManager_hpp
#define TubeManager_hpp

#include<vector>
#include<accctrl.h>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include"DateTime.hpp"
#include"Constant.hpp"
#include"Tube.hpp"
#include"UserRecord.hpp"
#include"User.hpp"
using namespace std;

/*************************************************************************
【类名】TubeManager
【功能】管理Tube类的数据和UserRecord类的数据的类的操作
【接口说明】
    构造函数TubeManager();
    析构函数~TubeManager()，考虑后续扩展的可能性，写为虚函数；
    函数AddTube用于添加一个Tube类对象，并将其指针存入列表中；
    函数SearchTube根据试管编号TubeNumber，查找试管，返回试管指针；
    函数SaveToFile保存所有tube到指定的文件；
    函数LoadFromFile从指定的文件中读取和创建所有tube对象；
    函数SearchID在UserRecord中查找指定被试者的身份证号，遍历m_AllRecords,
    将一个存储了所有符合条件的试管的智能指针动态数组传入参数中；
    函数AddUserRecord将一个UserRecord的实例指针添加到m_AllRecords里；
    函数AddRecord将给定试管的编号和所有被试者ID一一传入m_AllRecords；
    数据成员m_AllTubes，所有Tube对象的智能指针列表；
    数据成员m_AllRecords，存UserRecord的实例的智能指针的列表
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-21 由黄润一添加、修改了注释
    2022-07-22 由黄润一增加了函数AddRecord
*************************************************************************/
class TubeManager
{
public:
    //构造函数
    TubeManager();
    //析构函数
    virtual ~TubeManager();

    //用于添加一个Tube类对象
    //根据试管编号（生产日期时间+六位数）创建一个试管对象
    //该函数需要负责查验输入的试管编号是否与已存在试管编号重复
    //重复则抛出异常
    //未重复则调用Tube类构造函数Tube(const string& TubeNumber)创建一个新对象
    shared_ptr<Tube> AddTube(const string& TubeNumber);

    //根据试管编号TubeNumber，查找试管，返回试管指针
    shared_ptr<Tube> SearchTube(const string& TubeNumber);
   
    //保存所有tube到指定的文件
    void SaveToFile(const string& FileName);
    //从指定的文件中读取和创建所有tube对象
    void LoadFromFile(const string& FileName);

    //在UserRecord中查找指定被试者的身份证号:
    //遍历m_AllRecords,
    //将一个存储了所有符合条件的试管的智能指针动态数组传入参数中
    void SearchID(vector<shared_ptr<Tube>>& TubeList, const string& IDNumber);

    //将一个UserRecord的实例指针添加到m_AllRecords里
    void AddUserRecord(shared_ptr<UserRecord> aUserRec);

    //向UserRecord列表添加实例
    //将给定试管的编号和所有被试者ID一一传入m_AllRecords；
    void AddRecord(shared_ptr<Tube> aTube);
private:
    //所有Tube对象的智能指针列表
    vector<shared_ptr<Tube>> m_AllTubes;

    //存UserRecord的实例的智能指针的列表
    vector<shared_ptr<UserRecord>> m_AllRecords;
};//end class TubeManager

#endif