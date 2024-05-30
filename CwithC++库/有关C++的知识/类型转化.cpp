/**
在C++中，你可以使用以下方法来进行类型转换：

1. **将int转换为string**：
你可以使用`std::to_string`函数来将一个整数转换为字符串。
std::to_string函数是C++标准库的一部分，它定义在<string>头文件中。
这个函数可以将基本数据类型（如int，long，long long，float，double，long double）转换为字符串。

    ```cpp
    int num = 123;
    std::string str = std::to_string(num); // str现在是"123"
    ```

2. **将string转换为int**：你可以使用`std::stoi`函数来将一个字符串转换为整数。

    ```cpp
    std::string str = "123";
    int num = std::stoi(str); // num现在是123
    ```

需要注意的是，如果字符串不能被解析为一个有效的整数，`std::stoi`函数会抛出一个`std::invalid_argument`异常。如果转换的数字超出了整数的范围，`std::stoi`函数会抛出一个`std::out_of_range`异常。在实际编程中，你可能需要使用try/catch语句来处理这些异常。

此外，C++还提供了其他的函数来进行不同类型的转换，例如`std::stol`，`std::stoll`，`std::stof`，`std::stod`，`std::stold`等等，这些函数可以将字符串转换为long，long long，float，double，long double等类型。


*/