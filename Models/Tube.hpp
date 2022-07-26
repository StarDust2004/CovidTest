/******************************************************************************
【文件名】Tube.hpp
【功能模块和目的】试管类的声明、试管异常类的声明
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至TubeManager类
    2022-07-21 由黄润一添加、修改了注释
    2022-07-22 由黄润一添加函数GetIDList
******************************************************************************/
#ifndef Tube_hpp
#define Tube_hpp

#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include"DateTime.hpp"
#include"Constant.hpp"
using namespace std;

//试管编号重复异常类
class ExecptionTubeExists : public invalid_argument
{
public:
    ExecptionTubeExists();
};

/*************************************************************************
【类名】Tube
【功能】试管类的操作
【接口说明】
    构造函数Tube(const string& TubeNumber)，给定试管编号（生产日期时间
    +流水号）创建一个试管对象；
    析构函数~Tube(),考虑到后续扩展的可能性，写为虚函数；
    函数AddSamplingTime添加采样日期时间；
    函数AddEntryTime添加录入日期时间；
    函数AddResult添加核酸检测结果；
    函数AddIDNumber添加一个被试者身份证号；
    函数GetTubeNumber用于读取试管编号m_TubeNumber；
    函数GetSamplingTime用于读取采样日期时间m_SamplingTime；
    函数GetEntryTime用于读取结果录入日期时间m_EntryTime；
    函数GetResult用于读取核酸检测结果（阴性/阳性）m_Result；
    函数GetIDList用于读取被试者身份证号列表；
    重载流插入运算符<<；
    重载流提取运算符>>；
    数据成员m_TubeNumber，试管编号（生产日期时间+六位数流水号）;
    数据成员m_SamplingTime，采样日期时间；
    数据成员m_EntryTime，结果录入日期时间；
    数据成员m_Result，核酸检测结果（阴性/阳性）;
    动态数组m_IDList，被试者身份证号列表
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至TubeManager类
    2022-07-21 由黄润一添加、修改了注释
    2022-07-22 由黄润一添加函数GetIDList
*************************************************************************/
class Tube
{
public:
    //不允许默认构造
    Tube() = delete;
    //拷贝构造和赋值对象delete
	Tube(const Tube& aTube) = delete; 
	Tube& operator=(const Tube& aTube) = delete;

    //根据试管编号（生产日期时间+六位数）创建一个试管对象
    //Tube(const DateTime& ProduceTime, const string& SerialNumber);
    Tube(const string& TubeNumber);
    //析构函数
    virtual ~Tube();

    //添加采样日期时间
    void AddSamplingTime(const DateTime& SampleTime);
    //添加录入日期时间
    void AddEntryTime(const DateTime& EntryTime);
    //添加核酸检测结果
    void AddResult(const TestResult& Result);
    //添加一个被试者身份证号，如有需要，可多次调用
    void AddIDNumber(const string& IDNumber);

    //读取试管编号m_TubeNumber
    string GetTubeNumber() const;
    //读取采样日期时间m_SamplingTime
    DateTime GetSamplingTime() const;
    //读取结果录入日期时间m_EntryTime
    DateTime GetEntryTime() const;
    //读取核酸检测结果（阴性/阳性）m_Result
    TestResult GetResult() const;
    //读取被试者身份证号列表
    vector<string> GetIDList() const;

    //流插入运算符<<的运算符重载函数
    friend ostream& operator<<(ostream& Stream, const Tube& aTube);
    //流提取运算符>>的运算符重载函数
    friend istream& operator>>(istream& Stream, Tube& aTube);

    /*2022-07-19修改
    //----------转移到TubeManager类----------
    //查找某个给定ID是否在
    //给定身份证号，在所有Tube列表中查找某个含有用户的Tube对象，返回shared_ptr<User>指针
    static shared_ptr<Tube> SearchTube(const string& IDNumber);
    //----------转移到TubeManager类----------
    */
    /*写在TubeManager类里
    //类函数(静态的，没有对象的函数):保存所有tube到指定的文件，包括派生的对象
    static void SaveToFile(const string& FileName);
    //类函数(静态的，没有对象的函数):从指定的文件中读取和创建所有tube对象
    static void LoadFromFile(const string& FileName);
    */
private:
    //试管编号（生产日期时间+六位数流水号）
    //“2022/07/09 00:00:00 000001”形式
    string m_TubeNumber;
    DateTime m_SamplingTime;//采样日期时间
    DateTime m_EntryTime;//结果录入日期时间
    TestResult m_Result;//核酸检测结果（阴性/阳性）
    vector<string> m_IDList;//被试者身份证号列表

    /*2022-07-19删除
    DateTime m_ProduceTime;//生产日期时间
    string m_SerialNumber;//六位数流水号
    //----------转移到TubeManager类----------
    //所有试管对象的智能指针列表，包括派生类对象
    static vector<shared_ptr<Tube>> m_AllTubes;
    //----------转移到TubeManager类----------
    */
};//end class Tube

#endif