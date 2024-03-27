/**
 * todo 解题思路
 * 求有几个连通子图，使用并查集
*/
#include <cstdio>
#include <iostream>
#define MAX 1000
using namespace std;

int father[MAX]; //to mark element belong to which set
int height[MAX];

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i; // everyone belongs to a set
        height[i] = 0;
    }
}

int Find(int n)
{
	if (father[n] != n)
    	father[n] = Find(father[n]);
    return father[n];
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y) 
    {
        if (height[x] < height[y])
        	father[x] = y;
        else if (height[x] > height[y])
        	father[y] = x;
        else
        	father[y] = x;
            height[x]++;
    }
}

int main()
{
    int n;
    cin >> n;
    init(n);
    int temp; // 不使用邻接矩阵
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
        {	
            cin >> temp;
            if (temp)
            {
                if (Find(i) != Find(j))
                {
                    Union(i, j);
                }
            }
        }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
		if (Find(i) == i)
        	count++;
    }
    cout << count << endl;
}