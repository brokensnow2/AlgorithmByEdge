/**
C++和Python中的元组（tuple）都是用来存储不同类型的数据的容器，但它们在使用和功能上有一些区别：

1. **可变性**：
    - **Python**：元组是不可变的，一旦创建就不能修改。
    - **C++**：`std::tuple`是可变的，你可以修改元组中的元素。

2. **索引**：
    - **Python**：你可以使用整数索引来访问元组中的元素，例如`my_tuple[0]`。
    - **C++**：你需要使用`std::get`函数和模板参数来访问元组中的元素，例如`std::get<0>(my_tuple)`。

3. **赋值**：
    - **Python**：你可以使用赋值语句来创建元组，例如`my_tuple = (1, "Test", 3.14)`。
    - **C++**：你需要使用构造函数来创建`std::tuple`，例如`std::tuple<int, std::string, double> my_tuple(1, "Test", 3.14)`。

4. **元素数量**：
    - **Python**：元组可以包含任意数量的元素。
    - **C++**：`std::tuple`的元素数量在编译时必须是已知的。

5. **其他功能**：
    - **Python**：元组支持解包，可以一次性赋值给多个变量，例如`a, b, c = my_tuple`。
    - **C++**：`std::tuple`支持结构化绑定，也可以一次性赋值给多个变量，例如`auto [a, b, c] = my_tuple`。

希望这个解答对你有所帮助！

*/
#include <iostream> // 引入输入输出库
#include <tuple>    // 引入元组库

int main() {
    std::tuple<int, std::string, double> t(1, "Test", 3.14); // 创建一个元组

    std::cout << "原始元组: " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << std::endl;

    std::get<0>(t) = 10; // 修改元组中的第一个元素
    std::get<1>(t) = "Changed"; // 修改元组中的第二个元素
    std::get<2>(t) = 2.718; // 修改元组中的第三个元素

    std::cout << "修改后的元组: " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << std::endl;

	auto[a,b,c] = t;
    std::cout << a << b << c << std::endl;
    return 0; // 程序正常结束
}
