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

int daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool isLeapYear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    	return true;
    else
    	return false;
}

int main()
{
    //存储年，月，日
	int year,month,day;
    while(scanf("%d/%d/%d",&year,&month,&day) != EOF)
    {
        // 天数
        int num = 0;
        //判断闰年还是平年
        int row;
		if(isLeapYear(year))
        	row = 0;
        else
        	row = 1;
        //累加
        for (int i = 0;i < month; i++)
        {
            num += daytab[row][i];
        }
        num += day;
        
		printf("%d\n",num);
    }
	return 0;
}