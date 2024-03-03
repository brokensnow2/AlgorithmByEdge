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

    int n;

	// 注意不能scanf("%d",&n) != 0 ：因为scanf返回的是个数
    while(scanf("%d",&n) != EOF )
    {
		if(n == 0)
		{
			break;
		}
        //结果
    	int pos=0,neg=0,zero=0;
		//
		double temp;

    	for (int i = 0;i < n; i++)
    	{
			scanf("%lf",&temp);
        	if(temp < 0)
        		neg += 1;
            else if(temp > 0)
            	pos += 1;
            else
            	zero += 1;
    	}
        printf("%d %d %d\n",neg,zero,pos);

    }
    
}