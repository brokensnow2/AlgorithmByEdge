#include <iostream> // 引入iostream库以进行输入/输出操作
#include <vector>   // 引入vector库以使用向量数据结构
#include <cstring>  // 引入cstring库以使用memset函数

using namespace std; // 使用标准命名空间

const int MAXN = 505; // 定义常量MAXN，表示最大的人数

vector<int> g[MAXN]; // 定义一个向量数组g，表示每个女生愿意的男生列表
int used[MAXN]; // 定义一个数组used，表示每个男生是否已经被尝试过配对
int match[MAXN]; // 定义一个数组match，表示每个男生的配对情况

// 定义一个函数dfs，用于寻找从女生u开始的一个可行的配对方案
bool dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) { // 遍历女生u愿意的所有男生
        int v = g[u][i]; // 取出一个男生v
        if (!used[v]) { // 如果男生v还没有被尝试过配对
            used[v] = true; // 标记男生v已经被尝试过配对
            if (match[v] == -1 || dfs(match[v])) { // 如果男生v还没有配对，或者他的配对可以找到其他的男生
                match[v] = u; // 将男生v和女生u配对
                return true; // 返回true，表示找到了一个可行的配对方案
            }
        }
    }
    return false; // 如果没有找到可行的配对方案，返回false
}

int main() { // 主函数开始
    int K, M, N; // 定义三个整数K、M和N，分别表示可能的组合数目，女生的人数，男生的人数
    while (cin >> K && K) { // 输入可能的组合数目，如果K不为0，则继续执行
        cin >> M >> N; // 输入女生的人数和男生的人数

        for (int i = 1; i <= M; i++) { // 初始化每个女生愿意的男生列表
            g[i].clear();
        }

        memset(match, -1, sizeof(match)); // 初始化每个男生的配对情况

        for (int i = 0; i < K; i++) { // 输入每个可能的组合
            int u, v; // 定义两个整数u和v，表示女生和男生的编号
            cin >> u >> v; // 输入女生和男生的编号
            g[u].push_back(v); // 将男生v添加到女生u愿意的男生列表中
        }

        int ans = 0; // 定义一个整数ans，用于存储最多的配对数
        for (int i = 1; i <= M; i++) { // 对于每一个女生
            memset(used, 0, sizeof(used)); // 初始化每个男生是否已经被尝试过配对
            if (dfs(i)) { // 如果从女生i开始可以找到一个可行的配对方案
                ans++; // 配对数加1
            }
        }

        cout << ans << endl; // 输出最多的配对数
    }

    return 0; // 主函数结束
}
