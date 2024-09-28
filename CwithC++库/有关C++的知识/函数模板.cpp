#include <iostream>
#include <string>

using namespace std;

/*
在 C++ 中，template <class T> 和 template <typename T> 这两种写法在功能上完全等价，都用于声明模板参数。

1. template <class T>
这是较早的写法，C++ 最初使用 class 关键字来表示模板参数，无论模板参数是否代表一个类。
这个写法更常见于一些旧代码或经典教材中。

2. template <typename T>
typename 是后来引入的关键字，用于表示模板参数是一个类型，表示得更加清晰。
现在很多开发者倾向于使用 typename，因为它更直观地表达了模板参数是类型的含义。

注意，函数模板不能缩短可执行程序。对于程序，最终仍将由独立的函数定义，就像以
手工方式定义了这些函数一样。最终的代码不包含任何模板，而只包含了为程序生成的实际函数。使用模
板的好处是，它使生成多个函数定义更简单、更可靠。
更常见的情形是，将模板放在头文件中，并在需要使用模板的文件中包含头文件。
*/
// 使用 class
template <class T>
T add(T a, T b) 
{
    return a + b;
}

// 使用 typename
template <typename T>
T add1(T a, T b) 
{
    return a + b;
}

template <class Tm>
void swap1(Tm & a, Tm & b)
{
    Tm temp = b;
    b = a;
    a = temp;
}

int main()
{
    cout << add(5, 17) << endl;
    cout << add1(1.1, 2.2) << endl;
    int a = 10, b = 20;
    swap1(a, b);
    cout << a << " " << b << endl;
}

/**
 * **显式具体化**（Explicit Specialization）是 C++ 模板编程中的一个特性，用来为特定类型提供专门的实现。
 * 当你写一个模板时，模板可以处理多种类型，而显式具体化允许你为某些特定的类型提供不同的实现方式。

### 1. **模板的默认行为**
当你定义一个模板时，它可以用于多种类型。编译器会根据你传入的类型自动实例化模板。例如：

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int result = add(1, 2);      // 实例化 T 为 int
    double result2 = add(1.5, 2.5); // 实例化 T 为 double
    return 0;
}
```

上面的 `add` 函数模板可以处理 `int`、`double` 等类型，编译器自动根据参数类型实例化模板。


### 2. **显式具体化**
显式具体化允许你为某些类型提供专门的实现。例如，如果你想为 `double` 类型提供专门的实现，而对其他类型使用模板的默认实现，可以使用显式具体化：

```cpp
template <typename T>
T add(T a, T b) {
    return a + b; // 通用模板
}

// 为 double 类型提供显式具体化
template <>
double add(double a, double b) {
    std::cout << "Using specialized add for double" << std::endl;
    return a + b;
}

int main() {
    int result = add(1, 2);      // 使用通用模板
    double result2 = add(1.5, 2.5); // 使用显式具体化
    return 0;
}
```

在这个例子中，`add<int>` 和其他类型都会使用通用模板，而 `add<double>` 将使用专门的实现。编译器会根据传入的类型选择合适的模板或具体化实现。

### 3. **显式具体化的规则**
- **显式具体化声明**必须使用 `template <>`，并且不再有模板参数列表，例如 `template <> double add(double a, double b)`。
- 显式具体化的定义应该与普通模板函数的定义类似，只不过专门针对特定的类型。

### 4. **部分具体化**
**部分特化**（Partial Specialization）是模板类的概念，允许你为部分类型或某些模板参数模式提供定制的实现。不过，C++ 不支持对**函数模板**的部分特化，只能对**类模板**进行部分特化。

### 5. **使用场景**
显式具体化通常在你需要为某些特定类型提供不同的算法或优化时使用。例如，如果对于 `int` 和 `double` 类型，处理方式完全相同，但对于 `std::string` 类型需要专门的处理逻辑，你就可以为 `std::string` 类型提供一个显式具体化。

显式具体化是模板编程中的一个强大工具，允许在同一代码库中使用灵活的模板设计，同时也能针对特殊情况进行优化或调整。
 * 
 * 
 * 
 * 
 */