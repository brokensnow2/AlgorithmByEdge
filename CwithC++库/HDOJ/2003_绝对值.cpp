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
        double ans = fabs(r);
        printf("%.2lf\n", ans); 
    }
}

/**
double my_fabs(double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}


*/