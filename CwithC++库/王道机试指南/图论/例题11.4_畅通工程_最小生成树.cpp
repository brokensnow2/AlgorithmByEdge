#include <iostream>
#include <cstdio>
#include <algorithm> // 使用sort

using namespace std;

struct Edge
{
    int from; // 弧尾(边的起点)
    int to; // 弧头(边的终点)
    int length; // 边的长度
    bool operator< (const Edge &e) // 重载操作符为了sort函数，也可以写个compare函数实现sort
    {
        return length < e.length;
    }
};

Edge edge[10000];
int father[100];
int height[100];

void Init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
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
        if (height[x] > height[y])
        	father[y] = x;
        else if (height[x] < height[y])
        	father[x] = y;
        else
        	father[y] = x;
            height[x]++;
    }
}

int Kruskal(int n, int edgeNum)
{
    Init(n);
    sort(edge, edge+edgeNum);
    int sum = 0;
    for (auto i : edge)
    {
        if (Find(i.from) != Find(i.to))
        {
            Union(i.from, i.to);
            sum += i.length;
        }
    }
    return sum;
}

int main()
{
	int n;
    while (cin >> n && n != 0)
    {
        int edgeNum = n * (n - 1) / 2;
        for (int i = 0; i < edgeNum; i++)
            cin >> edge[i].from >> edge[i].to >> edge[i].length;
		int ans = Kruskal(n, edgeNum);
        cout << ans << endl;
    }
}