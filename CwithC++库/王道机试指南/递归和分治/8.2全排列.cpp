/**
 * 分析：如果循环：第一层从小到大
 * 第二层除了第一层的那个字母，再从小到大
 * 第三层除了第一，第二层字母，再从小到大
 * 
 * 如果用递归的话
 * 
 * 
*/

#include <iostream>
#include <string>

using namespace std;

void printOthers(const std::string& str, const std::string& prefix = "") {
    if (str.size() == 1) {
        std::cout << prefix << str << std::endl;
    } else {
        for (char c : str) {
            printOthers(str.substr(0, str.find(c)) + str.substr(str.find(c) + 1), prefix + c);
        }
    }
}

int main() {
    std::string input;
    getline(std::cin, input);
    printOthers(input);
    return 0;
}
