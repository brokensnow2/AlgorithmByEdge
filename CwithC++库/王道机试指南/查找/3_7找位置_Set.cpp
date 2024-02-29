extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}

#include <sstream> // 引入字符串流库
#include <algorithm> // 引入C++的算法库
#include <iostream>
#include <unordered_map>

using namespace std;

//使用字典,当然也可以用集合
void printDups(std::string str) {
    std::unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        if (count[str[i]]++ >= 1)
        {
            cout << str[i] << ',' << i+1 << " ";
        }
        
    }

}

int main() {
    std::string str = "abcaaAB12";
    printDups(str);
    return 0;
}

/**C语言根据ASCII实现（相当于map）
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void printDups(char *str) {
    int count[MAX_CHAR] = {0};
    int i;

    for (i = 0; *(str + i); i++)
        count[*(str + i)]++;

    for (i = 0; i < MAX_CHAR; i++)
        if(count[i] > 1)
            printf("%c, count = %d \n", i, count[i]);
}

int main() {
    char str[] = "abcaaAB12";
    printDups(str);
    return 0;
}


*/
