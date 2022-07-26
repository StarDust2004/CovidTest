//
//  Date.cpp
//  DEMO_DAY_04_USER_XCODE
//
//  Created by Jingtao Fan on 2021/8/5.
//
/******************************************************************************
【更改记录】2022-07-8 由黄润一修改部分注释、删改部分功能
******************************************************************************/

#ifndef Date_hpp
#define Date_hpp

#include <ctime>
#include <iostream>
using namespace std;

class Date{
public:
	//带有参数和默认值的构造函数
	Date(unsigned int Year = 1900,	unsigned int Month = 1,	
		unsigned int Day = 1);
	//拷贝构造函数
	Date(const Date& Source);
	//重载赋值运算符
	Date& operator=(const Date& Source);
	//析构函数，Date为基类，析构函数应该为虚函数
	virtual ~Date();

	//检查输入的值并设置私有成员
    void Set(unsigned int Year, unsigned int Month, unsigned int Day);

	//重载关系运算符
	bool operator> (const Date& d) const;
    bool operator< (const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;

    //重载++运算符，增加一天
    Date& operator++();
    Date  operator++(int);
    //重载--运算符，减少一天
    Date& operator--();
    Date  operator--(int);
    
    //返回两个日期之间的天数，今天-昨天是1，昨天-今天是-1
    long long operator-(const Date& aDate) const;
   
    //工作日的枚举
    enum class WeekDayType {MON = 1, TUES = 2, WED = 3, THUR = 4, FRI = 5, 
		SAT = 6 , SUN = 0};
    
    //return if the year is leap, form AD
    bool IsLeapYear() const;
    //return if the date is valid, form AD
    bool IsValid() const;

	//class function(static, no object's function), return if an Year is leap, form AD
    static bool IsLeapYear(unsigned int Year);
    //class function(static, no object's function), return if a date is valid, form AD
    static bool IsValid(unsigned int Year, unsigned int Month, unsigned int Day);
    
    //return the days'count from 0001-01-01, 0001-01-01 is the first(1, not 0) day
    unsigned int InDaysFromAD() const;

	//overloading stream insertion(extraction) operators
    friend ostream& operator<<(ostream& Stream, const Date& aDate);
    friend istream& operator>>(istream& Stream, Date& aDate);

    //class function(static, no object's function) to get a date object means today;
    static Date Today();
    
    //数据成员的常引用，只读
    const unsigned int& Year;
    const unsigned int& Month;
    const unsigned int& Day;
    const WeekDayType& WeekDay;
    
    //0001/01/01，日期最小值
    static const Date MIN_DATE;
    //UINT32_MAX-12-31，日期最大值
    static const Date MAX_DATE;

private:
	//数据成员
	unsigned int m_uYear;
	unsigned int m_uMonth;
	unsigned int m_uDay;
	WeekDayType m_WeekDay;

	//数组，一行存闰年的每月日数，一行存非闰年的每月日期数。
	//DaysInMonth[0][1~12],平年
	//DaysInMonth[0][1~12],闰年
	static const unsigned int DaysInMonth[2][13];
	 
    //YEAR 1582
    //Pope Gregor VIII issued a decree on February 24, 1582, permanently erasing the period from October 5, 1582 to October 14, 1582. There have never been these 10 days in history. October 4, 1582 is Thursday, and its next day is Friday, October 15, 1582.
    //Before this year, there was a leap year every four years; After that, people used the current method of calculating leap years
    static const unsigned int GrigoreyYear;
};//end Date

#endif /* Date_hpp */
