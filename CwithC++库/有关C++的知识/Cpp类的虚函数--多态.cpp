/* 在C++中，
子类可以通过**重写**（override）父类的成员函数来改变其行为。
重写是面向对象编程中的一个重要特性，实现了多态。

在这个例子中，`Child`类重写了`Parent`类的`myFunction()`函数。
这意味着，当我们通过`Child`类的对象调用`myFunction()`时，将执行`Child`类中定义的版本，而不是`Parent`类中的版本。
注意以下几点：
- 父类中的函数需要声明为`virtual`，这样才能在子类中被重写。
- 子类中重写的函数需要使用`override`关键字，这可以帮助编译器检查我们是否正确地重写了父类的函数。 
*/

// 父类
class Parent {
public:
    virtual void myFunction() {   // 虚函数
        // 父类的函数体
    }
};

// 子类
class Child : public Parent {
public:
    void myFunction() override {  // 重写父类的函数
        // 子类的函数体
    }
};

/* 
虚函数使用的其核心目的是通过基类访问派生类定义的函数。
所谓虚函数就是在基类定义一个未实现的函数名，为了提高程序的可读性，建议后代中虚函数都加上virtual关键字。
https://blog.csdn.net/qq_42048450/article/details/117282640
https://blog.csdn.net/changyi9995/article/details/108245614
 */


