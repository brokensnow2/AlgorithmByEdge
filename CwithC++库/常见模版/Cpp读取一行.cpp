#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line); // 读取一行
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
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
