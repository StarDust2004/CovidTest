/******************************************************************************
【文件名】Constant.hpp
【功能模块和目的】定义一些在多个文件中调用的常量、枚举类等
【开发者及日期】黄润一(hry21@mails.tsinghua.edu.cn) 2022-7-6
【更改记录】2022-07-21 由黄润一添加注释
******************************************************************************/
#ifndef Constant_hpp
#define Constant_hpp

#include<string>
using namespace std;

//存储User对象的文件的路径名
//const string UsersFileName = "User.txt";
const string UsersFileName = "C:/Projects/CovidTest/Resource/User.txt";
//存储Tube对象的文件的路径名
//const string TubesFileName = "Tube.txt";
const string TubesFileName = "C:/Projects/CovidTest/Resource/Tube.txt";

//核酸检测结果枚举类
enum class TestResult {Positive, Negative, Unknown};

#endif