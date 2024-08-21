#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

int main() {
    std::string text;
    std::getline(std::cin, text);  // 读取输入文本

    std::unordered_map<std::string, int> wordCount;
    std::string word;

    // 将文本转换为小写并分词
    for (char& c : text) 
    {
        // 它会将输入的字符转换为小写字母。
        //如果输入的字符不是字母（例如数字、标点符号等），std::tolower 会直接返回该字符的原值，而不会对它做任何改变。 
        c = std::tolower(c);
        if (std::isalnum(c)) 
        {
            word += c;
        } else if (!word.empty()) // 遇到非空非字符数字代表一个word的结束
        {
            wordCount[word]++;
            word.clear();
        }
    }
    // 处理最后一个单词
    if (!word.empty()) 
    {
        wordCount[word]++;
    }

    // 找出出现次数最多的单词，字典序最小的单词
    std::string mostCommonWord;
    int maxCount = 0;

    for (const auto& entry : wordCount) 
    {
        if (entry.second > maxCount || 
            (entry.second == maxCount && entry.first < mostCommonWord)) 
            {
            mostCommonWord = entry.first;
            maxCount = entry.second;
        }
    }

    // 输出结果
    std::cout << mostCommonWord << " " << maxCount << std::endl;

    return 0;
}
