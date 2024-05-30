/**
 * todo 思路：
 * 通过动态规划（DP）和深度优先搜索（DFS）来解决
 * 需要在每个节点处做出是否占领该节点的决策，并根据剩余的士兵数量更新我们的状态。

以下是解决这个问题的主要思想：

建立图模型：首先，我们需要将给定的洞穴结构建模为一个图，其中节点表示房间，边表示隧道。我们还需要记录每个房间的虫子数量和包含大脑的可能性。
深度优先搜索：然后，我们从入口开始进行深度优先搜索。在每个节点，我们都有两个选择：占领这个房间，或者放弃这个房间并前进到下一个房间。
动态规划：我们使用一个动态规划数组来记录到达每个节点时的最大可能性总和。在每个节点，我们更新这个数组，考虑占领这个房间和不占领这个房间两种情况。
更新状态：在每个节点，我们需要更新我们的状态，包括剩余的士兵数量和已经占领的房间的大脑可能性总和。
找到最大值：最后，我们在所有节点中找到最大的可能性总和，这就是我们的答案。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn], w[maxn], v[maxn], head[maxn], num;
struct Edge
{
    int to, next;
} edge[maxn]; // Edge edge[maxn]

void add(int u, int v)
{
    edge[num].to = v;
    edge[num].next = head[u];
    head[u] = num++;
}

void dfs(int u, int fa, int m)
{
    for (int i = m; i >= w[u]; i--)
        dp[u][i] = v[u];
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u, m - w[u]);
        for (int j = m; j >= w[u]; j--)
            for (int k = 0; k <= j - w[u]; k++)
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m), n + 1)
    {
        memset(head, -1, sizeof(head));
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &w[i], &v[i]);
            w[i] = (w[i] + 19) / 20;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        memset(dp, 0, sizeof(dp));
        dfs(1, -1, m);
        printf("%d\n", dp[1][m]);
    }
    return 0;
}
