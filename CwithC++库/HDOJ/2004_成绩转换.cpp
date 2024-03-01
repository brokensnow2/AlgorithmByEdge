extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
#include <math.h>
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <string> // 引入C++的string类
#define PI 3.1415927

using namespace std;

int main()
{
    double r;
	while(scanf("%lf",&r) != EOF)
    {
        if(r <= 100 && r >= 90)
        {
            printf("A\n");
        }
        else if(r <= 89 && r >= 80)
        	printf("B\n");
        else if(r <= 79 && r >= 70)
        	printf("C\n");
        else if(r <= 69 && r >= 60)
        	printf("D\n");
        else if(r <= 59 && r >= 0)
        	printf("E\n");
        else
        	printf("Score is error!\n");
    }
}