extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}
#include <iostream> //Cpp的标准输入输出库
#include <algorithm> // 引入C++的算法库
#include <vector> // 引入C++的向量库
#include <tuple>

using namespace std; // 使用标准命名空间

int main()
{
    int x,y,z; // 大鸡，小鸡，小小鸡
    int n; // n元
    // 类似python的list，列表中的元素是元祖
    vector<tuple<int,int,int>> ans;
    cin >> n;
    if (n < 34) //全买小鸡
    	cout << "No way";
    else
    {
        // 从100只小小鸡开始枚举
		for (z = 100; z >= 0; z--)
        {
            for (y = 0; y <= 100-z; y++)
            {
                x = 100 - z - y;
                if (5*x + 3*y +z/3 <= n)
                {
					tuple<int, int, int> t = make_tuple(x, y, z);
                    cout << "大鸡：" << x << " 小鸡：" << y << " 小小鸡：" << z << endl;
                }
            }
        }
        
    }
    
}