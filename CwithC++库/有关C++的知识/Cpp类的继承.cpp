/*
访问控制：

*/


// 父类
class Parent {
public:
    int parentVar;
    void parentFunction() {
        // 函数体
    }
};

// 子类
class Child : public Parent {
public:
    int childVar;
    void childFunction() {
        // 函数体
    }
};
