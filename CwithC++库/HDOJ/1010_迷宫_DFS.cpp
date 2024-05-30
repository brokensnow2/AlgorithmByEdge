/**
 * todo 解题思路：
 * way1从终点开始广度优先搜索，搜索T轮，
 * 如果在T轮中刚好找到了'S',则表明小狗可以存活
 *
 * way2从起点开始深度优先搜索，搜索T轮，
 * 将所有T轮中访问的点标记，如果有'D',则成功
 * visited数组需要作为函数参数传递
 *
 * 感觉way2可行些，BFS主要用来求最优解
 * S . X .
 * . . X .
 * . . . D
 *
 * T=5和T=7都可以存活
 */
#include <bits/stdc++.h> // 包含所有标准库头文件的头文件
using namespace std; // 使用标准命名空间

// 定义全局变量
int n, m, t; // 迷宫的行数、列数和门打开的时间
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 定义四个方向的移动向量
char maze[10][10]; // 存储迷宫的数组
bool vis[10][10]; // 记录每个位置是否被访问过的数组
int sx, sy, ex, ey; // 小狗的起始位置和门的位置
bool flag; // 标记是否找到一条成功的路径

// 深度优先搜索函数
void DFS(int x, int y, int time)
{
    if (flag) // 如果已经找到一条成功的路径，就直接返回
        return;
    if (x == ex && y == ey && time == t) // 如果在门打开的时间到达门，就标记找到一条成功的路径，并返回
    {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++) // 遍历当前位置的四个方向
    {
        int nx = x + dx[i], ny = y + dy[i]; // 计算新的位置
        // 如果新的位置在迷宫内，没有被访问过，并且不是墙，就向这个位置移动
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && maze[nx][ny] != 'X')
        {
            vis[nx][ny] = true; // 标记这个位置已经被访问过
            // 如果当前路径的长度加上从当前位置到门的曼哈顿距离是偶数（这是因为小狗每秒只能移动一步，所以总的移动步数必须是偶数），就继续搜索
            //if ((t - time) % 2 == (abs(nx - ex) + abs(ny - ey)) % 2) // 不可以这么剪枝
            /* 
             *  ((t - time) % 2 == (abs(nx - ex) + abs(ny - ey)) % 2)确实是基于最小步数的，
             * 也就是从当前位置到门的曼哈顿距离。
             * 然而，实际上小狗的步数可以大于这个最小步数，只要总步数等于剩余的时间就可以。 
            */
                DFS(nx, ny, time + 1);
            vis[nx][ny] = false; // 回溯：撤销对这个位置的访问标记
        }
    }
}

int main()
{
    while (cin >> n >> m >> t && (n || m || t)) // 读入迷宫的行数、列数和门打开的时间，如果这三个数都不为0，就继续处理
    {
        for (int i = 0; i < n; i++) // 读入迷宫的布局
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j]; // 读入一个字符
                if (maze[i][j] == 'S') // 如果这个字符是'S'，就记录小狗的起始位置
                    sx = i, sy = j;
                if (maze[i][j] == 'D') // 如果这个字符是'D'，就记录门的位置
                    ex = i, ey = j;
            }
        memset(vis, false, sizeof(vis)); // 初始化vis数组，所有位置都没有被访问过
        flag = false; // 初始化flag，表示还没有找到一条成功的路径
        vis[sx][sy] = true; // 标记小狗的起始位置已经被访问过
        DFS(sx, sy, 0); // 从小狗的起始位置开始深度优先搜索
        if (flag) // 如果找到一条成功的路径，就输出"YES"
            cout << "YES" << endl;
        else // 否则，输出"NO"
            cout << "NO" << endl;
    }
    return 0; // 程序正常结束
}

