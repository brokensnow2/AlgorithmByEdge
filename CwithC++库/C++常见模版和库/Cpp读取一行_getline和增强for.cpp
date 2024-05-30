#include <iostream>
#include <sstream>
#include <vector>
#include <string>
//可以用来读取一行未知个数的数字和字符，但注意！！！只能读取字符串，一个空格，字符串，一个空格这样的。
//想读取中间有多个空格的，见2093.cpp，使用find_first_not_of(' '),不然会有空字符混入其中
int main() {
    std::string line;
    std::getline(std::cin, line); // 读取一行，第三个参数默认是换行符
    /**
     * @brief std::istringstream iss(line);是C++中的一行代码，
     * 它创建了一个std::istringstream（输入字符串流）对象iss，并使用字符串line初始化它。
     * std::istringstream是std::istream（输入流）的一个子类，它从一个字符串中读取数据，就像从输入流（如std::cin）中读取数据一样。
     * 可以使用>>运算符从std::istringstream对象中提取值，就像从std::cin或其他输入流中提取值一样。
     * 
     * @return std::istringstream 
     */
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;
    /**
     * std::getline(iss, word, ' ')：这个函数从输入流iss中读取字符，直到遇到空格（' '）为止，然后将读取的文本存储在word中。
     * 空格字符不会被存储到word中，而是从输入流中丢弃。如果成功读取了一个单词，那么这个函数返回iss，否则返回false。
     * 
     */
    while (std::getline(iss, word, ' ')) { // 根据空格分割
        words.push_back(word);
    }

    // 输出分割后的字符串
    /**
    *for (const auto& word : words): 这是一个基于范围的for循环，
    它遍历words容器中的每个元素。const auto&是一个类型说明符，
    它自动推断words中元素的类型，并创建一个名为word的常量引用。
    *

    *在C++中，const关键字用于声明一个常量，也就是说，一旦被赋值，就不能改变。在这段代码中，
    const auto& word表示word是一个引用，它引用的对象是不可修改的。
	使用const有几个好处：

		保护数据：如果你不想让数据被修改，可以使用const来保护它。
		提高代码可读性：const可以告诉读代码的人这个数据是不会被改变的。
		优化性能：编译器可能会对const数据进行优化。
    */
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
