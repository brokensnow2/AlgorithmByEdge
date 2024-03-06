#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // m行n列
    int m,n;
    while(cin >> m >> n)
    {
        if (m==0 && n==0)
        {
			break;
        }
		// 只开辟一行
    	vector<int> array(n);
    	// 存结果的 什么数的绝对值能小于0？
    	int index_x=1, index_y=1,max=0;
		//
    	int temp;
    	// 行列从1开始
    	for (int i = 1; i < m+1; i++)
    	{
        	for (int j = 1; j < n+1; j++)
        	{
            	cin >> temp;
				if (abs(temp) > abs(max))
            	{
                	index_x = i;
                	index_y = j;
                	max = temp;
            	}
        	}
    	}
    	cout << index_x << " " << index_y << " " << max << endl;
    }

}