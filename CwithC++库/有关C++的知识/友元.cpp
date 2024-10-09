/**
 * 友元有 3 种：
 * 友元函数
 * 友元类
 * 友元成员函数
 * 
 */

/*
创建友元函数的第一步是将其原型放在类声明中，并在原型声明前加上关键字 friend：
该原型意味着下面两点：
friend Time operator *(double m, const Time & t);
虽然 operator *( )函数是在类声明中声明的，但它不是成员函数，因此不能使用成员运算符来调用；
虽然 operator *( )函数不是成员函数，但它与成员函数的访问权限相同。

第二步是编写函数定义。因为它不是成员函数，所以不要使用 Time::限定符。另外，不要在定义中使用friend

                            友元是否有悖于 OOP 
乍一看，您可能会认为友元违反了 OOP 数据隐藏的原则，因为友元机制允许非成员函数访问私有数据。
然而，这个观点太片面了。相反，应将友元函数看作类的扩展接口的组成部分。例如，从概念上看，double
乘以 Time 和 Time 乘以 double 是完全相同的。也就是说，前一个要求有友元函数，后一个使用成员函数，
这是 C++句法的结果，而不是概念上的差别。通过使用友元函数和类方法，可以用同一个用户接口表达这
两种操作。另外请记住，只有类声明可以决定哪一个函数是友元，因此类声明仍然控制了哪些函数可以访
问私有数据。总之，类方法和友元只是表达类接口的两种不同机制。
*/
#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHours(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    friend Time operator*(double n, const Time & t);
    friend ostream & operator<<(ostream & os, const Time & t);
};

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    this->hours = h;
    this->minutes = m;
}

void Time::AddMin(int m)
{
    int Min_new = m + this->minutes;
    this->minutes = Min_new % 60;
    this->hours += Min_new / 60;
}

void Time::AddHours(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    this->hours = h;
    this->minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = minutes + 60 * hours;
    tot2 = t.minutes + 60 * t.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}
/// @brief 不可以A = 2.5 * B;只能A = B * 2.5; // A, B 是Time类的对象
/// @param n 
/// @return 
Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = minutes * n + hours * n * 60;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return result;
}

/// @brief 友元函数，不是Time类的成员函数
/// @param n 
/// @param t 
/// @return 
Time operator*(double n, const Time &t)
{
    return t * n;
}

ostream & operator<<(ostream &os, const Time &t)
{
    // TODO: 在此处插入 return 语句
    os << t.hours << " hours; " << t.minutes << " minutes. " << endl;
    return os;
}

// 重载<<运算符

int main()
{
    Time aisa(3, 25);
    cout << "Time is " << aisa << endl;
    cout << aisa * 3.5;
}