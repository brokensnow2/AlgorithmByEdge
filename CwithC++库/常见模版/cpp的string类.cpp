/**
 * @file cpp的string类.cpp
 * @author your name (you@domain.com)
 * @brief std::string和char*都可以用于表示字符串，但它们之间存在一些重要的区别：

    内存管理：std::string是一个类，它自动管理内存。当你向std::string添加或删除字符时，它会自动调整内存。
    而对于char*，你需要手动分配和释放内存，这可能会导致错误，如内存泄漏或越界访问。

    安全性：std::string提供了一些成员函数，如length()和size()，可以安全地获取字符串的长度。
    而对于char*，你需要手动查找终止字符(‘\0’)来确定字符串的长度，这可能会导致越界访问。
    功能：std::string提供了一些用于操作字符串的成员函数，如append()、substr()和find()。
    而char*没有这些函数，你需要使用C标准库中的函数，如strcat()、strstr()等。
    但是，std::string没有strcmp和strcat这样的函数，但它提供了一些类似的成员函数：

    std::string::compare()函数可以用于比较两个字符串，类似于strcmp。
    std::string::operator+和std::string::append()函数可以用于连接两个字符串，类似于strcat。
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // 比较字符串
    if (str1.compare(str2) == 0) {
        std::cout << "Strings are equal" << std::endl;
    } else {
        std::cout << "Strings are not equal" << std::endl;
    }

    // 连接字符串
    std::string str3 = str1 + " " + str2;
    std::cout << str3 << std::endl;


    // char*转换为std::string
    char* cstr = "Hello, World!";
    std::string str = cstr;
    std::cout << str << std::endl;

    return 0;
}
