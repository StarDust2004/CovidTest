/******************************************************************************
【文件名】Tube.cpp
【功能模块和目的】试管类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】
    2022-07-19 由黄润一删改了部分函数，将一部分功能转移至TubeManager类
    2022-07-21 由黄润一添加、修改了注释
    2022-07-22 由黄润一添加函数GetIDList
******************************************************************************/
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream> 
#include "Tube.hpp"
#include "Constant.hpp"
#include "UserRecord.hpp"
#include "TubeManager.hpp"
using namespace std;

//异常类的定义
ExecptionTubeExists::ExecptionTubeExists() : invalid_argument("Tube Exist."){
}

/******************************************************************************
【函数名称】~Tube
【函数功能】Tube类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
Tube::~Tube() {

}

/******************************************************************************
【函数名称】Tube
【函数功能】Tube类的构造函数，可以创建Tube类的一个实例
【参数】输入参数string TubeNumber，试管编号
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改了注释
******************************************************************************/
Tube::Tube(const string& TubeNumber)
{
    m_TubeNumber = TubeNumber;//试管编号
    DateTime m_SamplingTime();//采样日期时间
    DateTime m_EntryTime();//结果录入日期时间
    m_Result = TestResult::Unknown;//核酸检测结果（阴性/阳性）
    vector<string> m_IDList{};//被试者身份证号列表初始化

    /*2022-07-19删除
    //将输入的一行字符串（试管编号）分割好，创建生产日期时间+六位数流水号
    unsigned int Year = stringToNum<unsigned int>(TubeNumber.substr(0, 4));//分割出年份
    unsigned int Month = stringToNum<unsigned int>(TubeNumber.substr(5, 2));//分割出月份
    unsigned int Day = stringToNum<unsigned int>(TubeNumber.substr(8, 2));//分割出日期
    unsigned int Hour = stringToNum<unsigned int>(TubeNumber.substr(11, 2));//分割出时
    unsigned int Minute = stringToNum<unsigned int>(TubeNumber.substr(14, 2));//分割出分
    unsigned int Second = stringToNum<unsigned int>(TubeNumber.substr(17, 2));//分割出秒
    string SerialNumber = TubeNumber.substr(20, 6);//分割出六位数流水号
    DateTime ProduceTime(Year, Month, Day, Hour, Minute, Second);//创建生产日期时间
  
    m_ProduceTime = ProduceTime;
    m_SerialNumber = SerialNumber;
    */
}

/******************************************************************************
【函数名称】AddSamplingTime
【函数功能】添加采样日期时间
【参数】输入参数DateTime SampleTime，传入采样日期时间
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void Tube::AddSamplingTime(const DateTime& SampleTime)
{
    m_SamplingTime = SampleTime;
}

/******************************************************************************
【函数名称】AddEntryTime
【函数功能】添加结果录入日期时间
【参数】输入参数DateTime EntryTime，传入结果录入日期时间
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void Tube::AddEntryTime(const DateTime& EntryTime)
{
    m_EntryTime = EntryTime;
}

/******************************************************************************
【函数名称】AddResult
【函数功能】添加核酸检测结果
【参数】输入参数TestResult Result，传入检测结果
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void Tube::AddResult(const TestResult& Result)
{
    m_Result = Result;
}

/******************************************************************************
【函数名称】AddIDNumber
【函数功能】添加一个被试者身份证号，如有需要，可多次调用
【参数】输入参数string IDNumber，传入被试者身份证号
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
void Tube::AddIDNumber(const string& IDNumber)
{
    m_IDList.push_back(IDNumber);
}

/******************************************************************************
【函数名称】GetTubeNumber
【函数功能】读取试管编号m_TubeNumber
【参数】无
【返回值】string，返回m_TubeNumber
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
string Tube::GetTubeNumber() const
{
    return m_TubeNumber;
}

/******************************************************************************
【函数名称】GetSamplingTime
【函数功能】读取采样日期时间m_SamplingTime
【参数】无
【返回值】DateTime，返回m_SamplingTime
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
DateTime Tube::GetSamplingTime() const
{
    return m_SamplingTime;
}

/******************************************************************************
【函数名称】GetEntryTime
【函数功能】读取结果录入日期时间m_EntryTime
【参数】无
【返回值】DateTime，返回m_EntryTime
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
DateTime Tube::GetEntryTime() const
{
    return m_EntryTime;
}

/******************************************************************************
【函数名称】GetResult
【函数功能】读取核酸检测结果（阴性/阳性）m_Result
【参数】无
【返回值】TestResult，返回m_Result
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
TestResult Tube::GetResult() const
{
    return m_Result;
}

/******************************************************************************
【函数名称】GetIDList
【函数功能】读取被试者身份证号列表m_IDList
【参数】无
【返回值】vector<string>，返回m_IDList
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-22
【更改记录】
******************************************************************************/
vector<string> Tube::GetIDList() const
{
    return m_IDList;
}

/******************************************************************************
【函数名称】operator<<重载
【函数功能】重载流插入运算符<<
【参数】
    输出参数ostream& Stream；
    输入参数Tube aTube;
【返回值】ostream&，返回Stream
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
ostream& operator<<(ostream& Stream, const Tube& aTube)
{
    int i;
    Stream << aTube.m_TubeNumber << endl << aTube.m_SamplingTime << endl 
        << aTube.m_IDList.size() << endl;
    for (i = 0; i < aTube.m_IDList.size(); i++)
    {
        Stream << aTube.m_IDList[i] << endl;
    }
    Stream << aTube.m_EntryTime << endl;
    switch (aTube.m_Result)
    {
        case TestResult::Positive:
            Stream << "Positive";
            break;
        case TestResult::Negative:
            Stream << "Negative";
            break;
        case TestResult::Unknown:
            Stream << "Unknown";
            break;
        default:
            break;
    }
    return Stream;
}

/******************************************************************************
【函数名称】operator>>重载
【函数功能】重载流提取运算符>>
【参数】
    输出参数istream& Stream；
    输入参数Tube aTube;
【返回值】istream&，返回Stream
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-9
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
istream& operator>>(istream& Stream, Tube& aTube)
{
    int n = 0;//被试者数量
    string res;//暂存从文件中读入的核酸检测结果（阴性/阳性）
    string TubeNumber;//暂存从文件中读入的一整行的试管编号
    string UserID;//暂存从文件中读入的
    //从流中依次提取试管编号、采样时间、被试者数量
    Stream.ignore();//清除缓存
    //m_TubeNumber需要读入一整行
    getline(Stream, TubeNumber);
    //Stream >> aTube.m_TubeNumber;
    //Stream >> TubeNumber;
    aTube.m_TubeNumber = TubeNumber;
    Stream >> aTube.m_SamplingTime;
    Stream >> n;
    //循环n次，从流中提取n个被试者身份证号，存入m_IDList列表中
    for (int i = 0; i < n; i++)
    {
        Stream >> UserID;
        aTube.m_IDList.push_back(UserID);
    }

    //从流中提取结果录入日期时间、核酸检测结果（阴性/阳性）（string类型暂存在string res中）
    Stream >> aTube.m_EntryTime >> res;
    if (res == "Positive")
    {
        aTube.m_Result = TestResult::Positive;
    }
    if (res == "Negative")
    {
        aTube.m_Result = TestResult::Negative;
    }
    if (res == "Unknown")
    {
        aTube.m_Result = TestResult::Unknown;
    }
    return Stream;
}

/*2022-07-19删除
//将string类型字符串转化为unsigned int类型
template <class Type>
Type stringToNum(const string& str){
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}
*/

/*转移至TubeManager类里
//静态数据成员必须在类外部显式初始化
//指向所有Tube对象(包括派生类对象)的智能指针列表的初始化
vector<shared_ptr<Tube>> Tube::m_AllTubes{};
*/