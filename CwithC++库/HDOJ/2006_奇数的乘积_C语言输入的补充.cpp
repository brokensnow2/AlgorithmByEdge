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
    //n个数
    int n;
    //存储缓冲区的字符
    //char temp;

    while(scanf("%d",&n) != EOF)
    {
        //结果
    	int sum = 1;

		int temp;
    	//读取缓冲区多余的空格或者换行符
    	//scanf("%c",&temp);

        /**

        使用scanf("%c", &temp);来读取缓冲区中的空格或换行符是正确的，
        因为%c格式说明符可以用来读取一个字符，包括空格和换行符。
        然而，并不是必要的。

		在代码中，使用scanf函数读取整数和字符。
		当使用scanf("%d",&n)函数读取整数时，它会自动跳过空格和换行符。
        所以，可以直接读取你需要的整数，不需要读取和处理空格或换行符。
        
        如果你在scanf("%d", &n)中输入了一个字符，
        那么scanf函数将无法正确地读取这个字符，
        因为%d格式说明符是用来读取整数的，而不是字符。

		在这种情况下，scanf函数将返回0，表示没有成功读取任何值。
        变量n的值将不会被改变，它将保持原来的值。
        
        */

    	for (int i = 0;i < n; i++)
    	{
			scanf("%d",&temp);
        	//读取缓冲区多余的空格或者换行符
    		//scanf("%c",&temp);
        	if(temp % 2 == 1)
        		sum *= temp;
    	}
        printf("%d\n",sum);

    }
    
}