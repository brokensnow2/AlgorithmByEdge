/*
访问控制：
关键字 protected 与 private 相似，在类外只能用公有类成员
 来访问 protected 部分中的类成员。private 和 protected 之间的区别只有在基类派生的类中才会表现出来。派
 生类的成员可以直接访问基类的保护成员，但不能直接访问基类的私有成员。因此，对于外部世界来说，
 保护成员的行为与私有成员相似；但对于派生类来说，保护成员的行为与公有成员相似。
*/

#include <iostream>

// 父类
class Parent
{
private:
    int parentVar;

public:
    int parentFunction()
    {
        return parentVar;
    }
    Parent() {
        std::cout << "Parent construction init ..." << std::endl;
    }
    Parent(int var) : parentVar(var) {} // 初始化列表
};

// 子类
class Child : public Parent
{
public:
    int childVar;

public:
    void childFunction()
    {
        // 函数体
    }
    // 创建派生类对象时，程序首先创建基类对象
    Child() {}  // 如果不调用基类构造函数，程序将使用默认的基类构造函数
    Child(int p_var, int c_var) : Parent(p_var) // 初始化列表
    {
        childVar = c_var;
    }
};

int main()
{
    Child a;    // Child a(); is error; 这是定义了一个函数，使用类的默认构造函数不要加括号
    Child b(3, 5);
    std::cout << "extend parent var : " << b.parentFunction() << " child var : "<< b.childVar << std::endl;
}

/**
 * @brief 
 * 派生类与基类之间有一些特殊关系。其中之一是派生类对象可以使用基类的方法，条件是方法不是私有的
 * 
 * 另外两个重要的关系是：基类指针可以在不进行显式类型转换的情况下指向派生类对象；基类引用可以在不进行显式类型转换的情况下引用派生类对象
 * 
 * 
 */
