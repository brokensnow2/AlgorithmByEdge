/**
 * 描述
查找一个数组的第K小的数，注意同样大小算一样大。 如  2 1 3 4 5 2 
第三小数为3。
输入描述：
输入有多组数据。 每组输入n，然后输入n个整数(1<=n<=1000)，再输入k。
输出描述：
输出第k小的整数。
输入：
6
2 1 3 5 2 2
3
输出：
3
 * 
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> q;
    int n, temp;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
			cin >> temp;
            q.push(temp);
        }
        int k, value;
        cin >> k;
        int count = 0;
        int precedence = -9999999;
		while (count != k)
        {
			value = q.top();
            q.pop();
            if (precedence != value)
            {
            	count++;
                precedence = value;
            }
        }
        cout << value << endl;
    }
}