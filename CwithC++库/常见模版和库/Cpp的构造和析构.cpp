// 在C++中，析构函数是一种特殊的成员函数，它在每次删除所创建的对象时执行。
// 析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数¹。
// 析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源¹。

#include <iostream>
using namespace std;

class Line {
public:
    void setLength( double len );
    double getLength( void );
    Line();   // 这是构造函数声明
    ~Line();  // 这是析构函数声明

private:
    double length;
};

// 成员函数定义，包括构造函数
Line::Line(void) {
    cout << "Object is being created" << endl;
}

Line::~Line(void) {
    cout << "Object is being deleted" << endl;
}

void Line::setLength( double len ) {
    length = len;
}

double Line::getLength( void ) {
    return length;
}

// 程序的主函数
int main( ) {
    Line line;  // 创建对象

    // 设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;

    return 0;
}

/**
 * @brief 在这个例子中，当对象`line`的生命周期结束时，析构函数`~Line()`会被自动调用，输出"Object is being deleted"，
 * 表示对象正在被删除¹。这就是析构函数的基本作用和使用方法。
 * 在实际编程中，析构函数常常被用来做一些清理工作，如释放对象占用的内存，关闭文件等¹。²。
 * 
 * 
 */

