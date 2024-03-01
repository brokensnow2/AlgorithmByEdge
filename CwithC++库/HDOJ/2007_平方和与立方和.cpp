extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
#include <math.h>
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <string> // 引入C++的string类

using namespace std;

int main()
{
    int x,y;
    int EvenPow2 = 0,OddPow3 = 0;
    while(scanf("%d%d",&x,&y) != EOF)
    {
        for(;x <= y; x++)
        {
            if(x % 2 == 0)
            {
				EvenPow2 += pow(x,2);
            }
            else
            	OddPow3 += pow(x,3);
        }

        printf("%d %d\n",EvenPow2,OddPow3);
        EvenPow2 = 0;
        OddPow3 = 0;
    }
}