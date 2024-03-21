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
#include <stdio.h>

using namespace std;

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

	//ASCII 每个char8位，存的是ASCII码
    for (int i = 0; i < str.size(); i++)
    	printf("%d %c \n",str[i], str[i]);

    return 0;
}

/**
* 其他操作：
	1. 可以通过下标访问
    2. insert()
    3. erase()
    4. clear()
    5. find() -> index or npos
    6. <,>,==,!=,<=,>=

*
*/

/**
string`库提供了许多用于操作字符串的函数。以下是一些常用的函数：

1. `size()`或`length()`: 返回字符串的长度。

2. `empty()`: 如果字符串为空（即长度为0），则返回`true`。

3. `substr(pos, len)`: 返回从位置`pos`开始、长度为`len`的子字符串。

4. `find(str)`: 返回字符串`str`在当前字符串中首次出现的位置。
如果未找到，则返回`string::npos`。
PS: npos:
在C++中，std::string::npos是一个特殊的值，
用于表示字符串中的“不存在的位置”。
它的实际值是-1，但由于它被定义为size_t类型（这是一个无符号整数类型），
所以它通常被表示为最大的可能的size_t值。

5. `rfind(str)`: 返回字符串`str`在当前字符串中最后一次出现的位置。
如果未找到，则返回`string::npos`。

6. `replace(pos, len, str)`: 
用字符串`str`替换从位置`pos`开始、长度为`len`的子字符串。

7. `insert(pos, str)`: 在位置`pos`处插入字符串`str`。

8. `erase(pos, len)`: 删除从位置`pos`开始、长度为`len`的子字符串。

9. `push_back(ch)`或`append(1, ch)`: 在字符串末尾添加字符`ch`。

10. `pop_back()`: 删除字符串末尾的字符。

这些函数提供了丰富的字符串操作功能，可以满足大多数字符串处理的需求。希望这个解答对你有所帮助！

*/

/**
 * C语言的字符串是以空字符（\0）作为结束标志的。
 * 当C语言的字符串被输出时，会从字符串的开始位置输出，
 * 直到遇到空字符为止。

而C++的std::string则不同。
std::string是一个类，它内部会记录字符串的长度，
所以在输出std::string时，并不需要依赖空字符来判断字符串的结束位置。
这就意味着，即使std::string中包含了空字符，这个字符串仍然可以被完整地输出。

至于C++的std::string是否以空字符结尾，这取决于编译器的实现。
标准并没有规定std::string必须以空字符结尾。
有些编译器会在std::string的结尾加上一个空字符，有些编译器则不会。
但无论编译器是否在std::string的结尾加上空字符，
这都不影响std::string的使用，因为std::string的长度信息已经被存储在了类的内部
 * 
*/