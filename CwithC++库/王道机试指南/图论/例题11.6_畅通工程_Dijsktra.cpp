#include <cstdio> // 包含C标准输入输出库
#include <iostream> // 包含C++标准输入输出库
#include <queue> // 包含队列库，用于实现优先队列
#include <vector> // 包含向量库，用于实现动态数组
#include <unordered_set> // 包含无序集合库，用于实现快速查找
using namespace std; // 使用标准命名空间

typedef vector<vector<pair<int, int>>> Graph; // 定义图的数据结构，图由一组边组成，每条边由一个节点对和一个权重组成

struct cmp // 定义比较函数，用于优先队列中的元素排序
{
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second; // 按照路径长度的升序排列
    }
};

int Dijsktra(Graph &graph, int start, int end) // 实现Dijkstra算法
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q; // 定义优先队列，队列中的元素是节点和从起点到该节点的路径长度
    unordered_set<int> visited; // 定义已访问节点集合
	q.push(make_pair(start, 0)); // 将起点放入队列，起点的路径长度为0
    while (!q.empty()) // 当队列非空时，反复执行以下操作
    {
        pair<int, int> node = q.top(); // 取出队列顶部的节点
        q.pop(); // 从队列中移除该节点
        if (node.first == end) // 如果该节点是终点，返回从起点到终点的路径长度
        	return node.second;
        if (visited.count(node.first) == 0) // 如果该节点未被访问过，将其加入已访问节点集合
        {    
            visited.insert(node.first);
        	for (auto i : graph[node.first]) // 遍历该节点的所有邻居
            	if (visited.count(i.first) == 0) // 如果邻居节点未被访问过，将其加入队列，并更新从起点到该节点的路径长度
                	q.push(make_pair(i.first, node.second + i.second));
        }
    }
    return -1; // 如果遍历完所有可达节点后仍未找到终点，返回-1，表示从起点到终点没有路径
}

int main() // 主函数
{
    int N, M; // N是节点数，M是边数
    int A, B, X; // A和B是一条边的两个节点，X是该边的权重
    cin >> N >> M; // 读入节点数和边数
    Graph graph(N); // 创建一个有N个节点的图
	while (M--) // 对于每条边
    {
		cin >> A >> B >> X; // 读入边的信息
        // 可以自定义结构体，不使用pair
        graph[A].push_back(make_pair(B, X)); // 将边添加到图中
        graph[B].push_back(make_pair(A, X)); // 因为是无向图，所以边是双向的
    }
    int S, T; // S是起点，T是终点
    cin >> S >> T; // 读入起点和终点
	int ans = Dijsktra(graph, S, T); // 调用Dijkstra算法计算最短路径长度
    cout << ans << endl; // 输出最短路径长度
}
