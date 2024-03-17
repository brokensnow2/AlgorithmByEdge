#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int father[1000]; // 父亲结点 
int height[1000]; // 结点高度

void Init(int n)
{
	for (int i = 0; i <= n; i++)
    {
        father[i] = i; // 初始化时每个结点的父亲是自己(每个结点都处在编号为自己下标的集合里)
        height[i] = 0;
    }
}

int Find(int n) // 查找根结点
{
    if (father[n] != n)
    {
        father[n] = Find(father[n]); // 路径压缩
    }
    return father[n];
}

void Union(int x, int y) // 合并集合
{
    x = Find(x);
    y = Find(y);
    if (x != y) // 矮树作为高树子树
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
    int n, m;
    while (cin >> n && n != 0)
    {
		cin >> m;
        Init(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            if (Find(i) == i)
                ans++;
        }
        cout << ans << endl;
    }
}