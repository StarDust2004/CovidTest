/******************************************************************************
【文件名】TubeManager.cpp
【功能模块和目的】管理Tube类的数据和UserRecord类的数据的类的实现
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加、修改了注释
******************************************************************************/
#include<accctrl.h>
#include<string>
#include<memory>
#include<iostream>
#include<stdexcept>
#include<fstream>
#include<algorithm> 
#include"DateTime.hpp"
#include"Constant.hpp"
#include"Tube.hpp"
#include"TubeManager.hpp"
using namespace std;

/******************************************************************************
【函数名称】TubeManager
【函数功能】TubeManager类的构造函数，可以创建一个TubeManager类的实例
【参数】无
【返回值】构造函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
TubeManager::TubeManager()
{

}

/******************************************************************************
【函数名称】~TubeManager
【函数功能】TubeManager类的析构函数
【参数】无
【返回值】析构函数没有返回值
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
TubeManager::~TubeManager(){

}

/******************************************************************************
【函数名称】AddTube
【函数功能】
    用于添加一个Tube类对象。该函数需要负责查验输入的试管编号是否与已存在试管
    编号重复，重复则抛出异常，未重复则根据试管编号（生产日期时间+六位数），
    调用Tube类构造函数Tube(const string& TubeNumber)创建一个新对象。
【参数】输入参数TubeNumber，传入试管编号
【返回值】shared_ptr<Tube> TubeManager，返回新建的Tube实例的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<Tube> TubeManager::AddTube(const string& TubeNumber)
{
    //遍历Tube列表
    for (const auto& n : m_AllTubes)
    {
        //核对:是否存在试管编号TubeNumber与传入的数据重复
        if (n->GetTubeNumber() == TubeNumber)
        {
            throw ExecptionTubeExists();//试管已存在
        }//重复则抛出异常
    }
    //未重复则创建一个Tube类的新对象
    Tube* aTube = new Tube(TubeNumber);

    //将新试管的指针保存到列表中去
    m_AllTubes.push_back(shared_ptr<Tube>(aTube));
    //把新建的Tube实例的指针当做返回值传回去
    return shared_ptr<Tube>(aTube);
}

/******************************************************************************
【函数名称】SearchTube
【函数功能】根据试管编号TubeNumber查找试管
【参数】输入参数string TubeNumber，传入试管编号
【返回值】shared_ptr<Tube> TubeManager，返回查找到的试管实例的指针
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
shared_ptr<Tube> TubeManager::SearchTube(const string& TubeNumber)
{
    //用于试管编号比较的Lambda函数对象
    auto Finder = [&TubeNumber](shared_ptr<Tube> ptr)->bool{
        return (ptr->GetTubeNumber() == TubeNumber);};
    //找出由试管编号指定的第一个用户
    auto it = find_if(m_AllTubes.begin(), m_AllTubes.end(), Finder);
    //Found 
    return *it;
}

/******************************************************************************
【函数名称】SaveToFile
【函数功能】
    保存所有tube到指定的文件。
    如果文件无法打开，则尝试创建文件；
    如果无法创建文件，将抛出invalid_argument异常。
【参数】输入参数string FileName，传入文件名
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void TubeManager::SaveToFile(const string& FileName)
{
    //打开或创建由FileName指定的文件
    ofstream File(FileName);
    //Can't create or open file
    if (!File.is_open()) 
    {
        throw invalid_argument("Can't open/Create for saving, File : " 
            + FileName);
    }
    //用于保存一个用户的Lambda表达式
    auto Saver = [&File](shared_ptr<Tube> Ptr) {File << *Ptr << endl;};
    //首先，将Tube对象计数（试管数）保存到文件的开头
    File << m_AllTubes.size() << endl;
    //遍历并保存所有Tube对象数据
    for_each(m_AllTubes.begin(), m_AllTubes.end(), Saver);
    //关闭文件
    File.close();
}

/******************************************************************************
【函数名称】LoadFromFile
【函数功能】
    从指定的文件中读取和创建所有tube对象。
    如果文件无法打开，则尝试创建文件；
    如果无法创建文件，将抛出invalid_argument异常。
【参数】输入参数string FileName，传入文件名
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】
    2022-07-21 由黄润一修改注释
    2022-07-22 由黄润一删改部分函数
******************************************************************************/
void TubeManager::LoadFromFile(const string& FileName)
{
    //尝试打开指定文件
    ifstream File(FileName);
    //无法打开
    if (!File.is_open()) 
    {
        //尝试通过文件名创建文件
        ofstream NewFile(FileName);
        //无法创建文件
        if (!NewFile.is_open()) 
        {
            throw invalid_argument("Can't open/create for loading, file: " 
                + FileName);
        }
        //设置初始试管数为0
        NewFile << 0 << endl;
        //关闭文件
        NewFile.close();

        //打开新文件
        File.open(FileName);
    }
    unsigned int TubeCount;//文件中的试管计数（试管对象数）
    //从文件中获取试管数
    File >> TubeCount;

    //删除在试管计数后的endl
    //File.get();
    
    //清除所有用户
    m_AllTubes.clear();
    //试管数为0
    if (TubeCount < 1) 
    {
        throw invalid_argument("No tube in this file");
    }
    //至少有一个用户
    else
    {
        for (unsigned long i = 0; i < TubeCount; i++) 
        {
            //通过简单的试管编号动态创建试管;
            Tube* aTube = new Tube{string("")};
            //将新实例的指针保存到列表中去，插入到末尾;
            m_AllTubes.push_back(shared_ptr<Tube>(aTube));
            //然后从文件流中更新试管信息，
            File >> *(*(m_AllTubes.end() - 1));
            
            //向UserRecord的RecordList中添加文件中的信息
            shared_ptr<Tube>& pTube = *(m_AllTubes.end() - 1);
            AddRecord(pTube);     
        }
    }
    //关闭文件
    File.close();
}

/******************************************************************************
【函数名称】SearchID
【函数功能】
    在UserRecord中查找指定被试者的身份证号，遍历m_AllRecords，
    将一个存储了所有符合条件的试管编号的动态数组传入参数中。
【参数】
    输入参数string IDNumber，传入需搜索的身份证号；
    输出参数vector<shared_ptr<Tube>>& TubeList，存储所有符合条件的试管指针。
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void TubeManager::SearchID(vector<shared_ptr<Tube>>& TubeList, 
    const string& IDNumber)
{
    //遍历UserRecord列表m_AllRecords
    for (const auto& n : m_AllRecords)
    {
        //如果某个UserRecord对象的UserID符合；
        if (n->GetUserID() == IDNumber)
        {
            //通过其TubeNumber查找到该试管，将试管智能指针传入TubeList中
            TubeList.push_back(SearchTube(n->GetTubeID()));
        }
    }
}

/******************************************************************************
【函数名称】AddUserRecord
【函数功能】将一个UserRecord的实例指针添加到m_AllRecords里
【参数】输入参数shared_ptr<UserRecord> aUserRec
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-19
【更改记录】2022-07-21 由黄润一修改注释
******************************************************************************/
void TubeManager::AddUserRecord(shared_ptr<UserRecord> aUserRec)
{
    m_AllRecords.push_back(aUserRec);
}

/******************************************************************************
【函数名称】AddRecord
【函数功能】
    向UserRecord列表添加实例，将给定试管的编号和所有被试者ID一一传入m_AllRecords；
【参数】输入参数aTube，需要遍历查找的试管指针
【返回值】无
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-22
【更改记录】
******************************************************************************/
void TubeManager::AddRecord(shared_ptr<Tube> aTube)
{
    for (const auto& n : aTube->GetIDList())
    {
        //将一条被试者ID&试管编号的信息添加到一个新的UserRecord实例;
        shared_ptr<UserRecord> aUserRecord =
            make_shared<UserRecord>(aTube->GetTubeNumber(), n);
        //并将这个新的UserRecord实例添加到TubeManager中的m_AllRecords列表中
        AddUserRecord(aUserRecord);
    }
}

