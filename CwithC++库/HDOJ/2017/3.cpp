#include <bits/stdc++.h>
using namespace std;
int n, m, N, M;
int ans = 0;
char map1[1005][1005];
char map2[1005][1005];
bool check(int x, int y)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map2[i][j] != map1[x + i][y + j])
                return false;
        }
    }
    return true;
}
void cut(int x, int y)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map1[x + i][y + j] = '-';
        }
    }
}
void nocut(int x, int y)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map1[x + i][y + j] = map2[i][j];
        }
    }
}
void dfs(int x, int y, int num)
{
    if (x == N || y == M)
        return;
    if (num > ans)
        ans = num;
    for (int i = y; i < N; i++)
    {
        if (check(x, i))
        {
            cut(x, i); 
            dfs(x, i + n, num + 1);
            nocut(x, i); 
        }
    }
    dfs(x + 1, 0, num);
}
int main() 
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map1[i][j];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map2[i][j];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}