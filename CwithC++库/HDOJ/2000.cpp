extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <string>

using namespace std; //使用标准命名空间，省去写std::

int main()
{
    char a[3];
    while (scanf("%c%c%c",&a[0],&a[1],&a[2]) != EOF)
    {
        sort(a,a+3);
        printf("%c %c %c \n",a[0],a[1],a[2]);
        char temp;
        scanf("%c",&temp);
    }
}
