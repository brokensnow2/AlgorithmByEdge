// 在C++中，析构函数是一种特殊的成员函数，它在每次删除所创建的对象时执行。
// 析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数¹。
// 析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源¹。

#include <iostream>
using namespace std;

//写法1：类中只声明
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


// 写法2：
/**
 * 在 C++ 中，可以在类或结构体的构造函数中使用初始化列表来初始化成员变量。
 * 初始化列表中的括号里的内容是用于初始化成员变量的参数。
 * 
 * 冒号:用于初始化类或结构体的成员变量。这种初始化方式被称为初始化列表。
 * 
 例如，在MyStruct(int val) : x(val) {}中，x(val)就是一个初始化列表。
 这意味着，当我们创建一个MyStruct的实例并传入一个参数val时，成员变量x会被初始化为val的值。
 * 
 * 
*/
class MyClass {
public:
	int x;
    MyClass() : x(0) {}  // 默认构造函数
    MyClass(int val) : x(val) {}  // 带参数的构造函数
    MyClass(const MyClass& other) : x(other.x) {}  // 复制构造函数
};

// 写法3：类似java
class MyClass1 {
    double length;
public:
	MyClass1(){}

    MyClass1(double len){
		length = len;
    }
};

struct S
{
    int value;
	S() : value() {};
    S(int v) : value(v) {
        cout << "ok" << endl;
    };
    void print()
    {
        cout << "It is S" << endl;
    }
};

// 程序的主函数
int main( ) {
    Line line;  // 创建对象
	MyClass my; //
    MyClass1 my1(10.0);
    // 设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;
    cout << "Length of MyClass : " << my.x <<endl;

	S s(100);
    s.print();
    return 0;
}

/**
 * @brief 在这个例子中，当对象`line`的生命周期结束时，析构函数`~Line()`会被自动调用，输出"Object is being deleted"，
 * 表示对象正在被删除¹。这就是析构函数的基本作用和使用方法。
 * 在实际编程中，析构函数常常被用来做一些清理工作，如释放对象占用的内存，关闭文件等¹。²。
 * 
 * 
 */


/**
 * std::vector<int>::iterator it = v.begin() // v是一个vector对象
 * 在C++中，`::`运算符有两种主要的用途：

1. **命名空间运算符**：第一个`::`是命名空间运算符，用于指定命名空间。
	例如，在`std::vector<int>`中，`std`是命名空间，
    `vector`是该命名空间下的一个模板类。

2. **作用域解析运算符**：第二个`::`是作用域解析运算符，用于指定类或结构体的成员。
	例如，在`std::vector<int>::iterator`中，`iterator`是`vector`类的一个成员类型。

	所以，`std::vector<int>::iterator it = v.begin();`
    这行代码的意思是，创建一个`std::vector<int>`的`iterator`
    类型的变量`it`，并将其初始化为`v`的起始迭代器。
 * 
 * 
 * 在C++中，.运算符用于访问类或结构体的成员，但是它只能用于对象或者结构体的实例。
 * 而::运算符用于访问类或结构体的静态成员，或者命名空间中的元素。
 * 
*/

/*
C++的结构体可以有构造函数。以下是一些常见的构造函数的写法：

默认构造函数：这是一个没有任何参数的构造函数。如果你没有为结构体提供任何构造函数，编译器会自动为你生成一个默认构造函数。
struct MyStruct {
    int x;
    MyStruct() {}  // 默认构造函数
};

带参数的构造函数：这是一个带有参数的构造函数，可以用来初始化结构体的成员。
struct MyStruct {
    int x;
    MyStruct(int val) : x(val) {}  // 带参数的构造函数
};

多参数的构造函数：这是一个带有多个参数的构造函数，可以用来初始化结构体的多个成员。
struct MyStruct {
    int x;
    double y;
    MyStruct(int val1, double val2) : x(val1), y(val2) {}  // 多参数的构造函数
};

复制构造函数：这是一个特殊的构造函数，用于创建一个新的结构体实例，该实例是现有实例的副本。
struct MyStruct {
    int x;
    MyStruct(const MyStruct& other) : x(other.x) {}  // 复制构造函数
};

默认和带参数的构造函数：你可以同时定义默认构造函数和带参数的构造函数。这样，你可以选择在创建结构体实例时是否提供参数。
struct MyStruct {
    int x;
    MyStruct() : x(0) {}  // 默认构造函数
    MyStruct(int val) : x(val) {}  // 带参数的构造函数
};


*/
