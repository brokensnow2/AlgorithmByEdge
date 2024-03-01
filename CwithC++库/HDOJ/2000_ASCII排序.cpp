extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <string> // 引入C++的string类

using namespace std;

int main()
{
    char chars[3];
    while(scanf("%c%c%c",&chars[0],&chars[1],&chars[2]) != EOF)
    {
        sort(chars,chars+3);
        printf("%c %c %c\n",chars[0],chars[1],chars[2]);
        // 接取缓冲区的多余的换行
        char temp;
        scanf("%c",&temp);
    }

}