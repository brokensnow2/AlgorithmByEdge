#include <iostream>
#include <vector>
#include <cstdio>
/**
 * todo 使用数组存放图形
 * ? 1  3  5  7  9  11
 * ? 内 外 内 外 内 外筐花色
 * 所以 n%4 == 1 外框为中心花色
 * 从最外层开始填充字符，共(n+1)/2次
*/
using namespace std;

int main()
{
	int n;
    char inner, outer;
    bool firstCase = true;
    while (cin >> n >> inner >> outer)
    {
        /*
        vector<char> s(n);
        vector<vector<char>> shape(n, s); 
        */
       	//								匿名对象
		vector<vector<char>> shape(n, vector<char>(n));
        //
        if (firstCase)
        	firstCase = false;
        else
        	cout << endl;
		//
        for (int i = 0; i <= n/2; i++)
        {
            // 右下角坐标
            int j = n - i - 1;
            // current char need be printed
            char c;
            int length = n - 2 * i;
            if ((n / 2 - i) % 2 == 0) // inner
				c = inner;
            else
            	c = outer;

            for (int k = 0; k < length; k++)
            {
                shape[i][i+k] = c;
                shape[i+k][i] = c;
                shape[j][j-k] = c;
                shape[j-k][j] = c;
            }
        }
        if (n != 1)
        {
            shape[0][0] = ' ';
            shape[0][n-1] = ' ';
            shape[n-1][0] = ' ';
            shape[n-1][n-1] = ' ';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << shape[i][j];
            }
            cout << endl;
        }
    }
}