#include <iostream>
#include <string>

class Complex
{
public:
    // 数据成员
    double real;
    double imag;

    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 运算符重载：+ 运算符
    //注意： 左侧的操作数是调用对象
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // 运算符重载：- 运算符
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // 运算符重载：* 运算符
    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // 运算符重载：<< 运算符（用于输出）
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // 运算符重载：== 运算符
    bool operator==(const Complex &other) const
    {
        return (real == other.real && imag == other.imag);
    }

    // 运算符重载：!= 运算符
    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }
};

// 自定义比较结构体,见2066_.cpp
struct CompareComplex
{
    bool operator()(const Complex &a, const Complex &b)
    {
        return (a.real < b.real) || (a.real == b.real && a.imag < b.imag);
    }
};

// 测试运算符重载
int main()
{
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;
    std::cout << "c1 - c2: " << c4 << std::endl;
    std::cout << "c1 * c2: " << c5 << std::endl;

    // 测试相等运算符
    if (c1 != c2)
    {
        std::cout << "c1 and c2 are not equal." << std::endl;
    }

    return 0;
}
/**
### 知识点详解：

1. **基本概念**：
   - 运算符重载是允许用户定义或修改运算符的功能，使其适用于用户自定义类型（类）。
   - 重载的运算符可以使用与内置类型相同的语法进行操作。

2. **重载的方式**：
   - **成员函数**：对于需要一个隐式对象作为参数的运算符（如 `+`、`-`、`*`），可以通过成员函数重载。
   - **友元函数**：对于需要两个不同类型对象进行操作的运算符（如 `<<`、`>>`），通常用友元函数重载。

3. **常见重载的运算符**：
   - 算术运算符：`+`, `-`, `*`, `/`, `%`
   - 比较运算符：`==`, `!=`, `<`, `>`, `<=`, `>=`
   - 逻辑运算符：`&&`, `||`, `!`
   - 赋值运算符：`=`, `+=`, `-=`, `*=`, `/=`
   - 自增和自减运算符：`++`, `--`
   - 输入输出运算符：`<<`, `>>`
   - 大多数运算符都可以通过成员或非成员函数进行重载，但下面的运算符只能通过成员
函数进行重载。
    =, (), [], ->

11.2.2 重载限制
多数 C++运算符（参见表 11.1）都可以用这样的方式重载。重载的运算符（有些例外情况）不必是成
员函数，但必须至少有一个操作数是用户定义的类型。下面详细介绍 C++对用户定义的运算符重载的限制。
1．重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。
因此，不能将减法运算符（−）重载为计算两个 double 值的和，而不是它们的差。虽然这种限制将对创造
性有所影响，但可以确保程序正常运行。
2．使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符（%）重载成使用一个操
作数：

4. **注意事项**：
   - 保持运算符的直观性，重载运算符应符合其通常的语义。
   - 运算符重载不能改变运算符的优先级和结合性。
   - 需要考虑效率，尤其是涉及到拷贝构造时，尽量使用常量引用。
   - 对于涉及内存管理的类，确保遵循规则，防止内存泄漏。

### 总结：
运算符重载是一种强大的功能，可以使自定义类型更自然地与 C++ 的语法结合使用。
通过合理的设计和重载，可以增强代码的可读性和可维护性。
*/