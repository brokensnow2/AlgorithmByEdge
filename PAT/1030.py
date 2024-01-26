"""
旅行者地图给出了高速公路沿线城市之间的距离，以及每条高速公路的成本。
现在你应该编写一个程序来帮助旅行者决定他/她的出发城市和目的地之间的最短路径。
如果这样的最短路径不是唯一的，那么你应该输出成本最低的路径，这保证是唯一的。

输入规范：
每个输入文件包含一个测试用例。每种情况都以一行开始，该行包含4个正整数N、M、S和D，
其中N（≤500）是城市的数量（因此城市的编号从0到N-1）；M是公路的数量；S和D分别是起点城市和终点城市。
接下来是M条线，每条线提供高速公路的信息，格式如下：
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
输出规格：
对于每个测试用例，在一行中打印从起点到目的地的最短路径上的城市，然后打印路径的总距离和总成本。
数字之间必须用空格隔开，并且在输出的末尾不能有多余的空格。
Sample Input:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output:
0 2 3 3 40
"""
# 导入heapq模块，用于实现优先队列
import heapq

# 定义dijkstra函数，用于找到从起点到终点的最短路径和最低成本
def dijkstra(graph, costs, start, end):
    # 初始化优先队列，开始节点的长度和成本都是0
    queue = [(0, 0, start, [start])]
    # 初始化一个集合来存储已访问过的节点
    visited = set()
    # 当队列不为空时，继续循环
    while queue:
        # 从队列中取出当前最短的路径
        (length, cost, node, path) = heapq.heappop(queue)
        # 如果当前节点没有被添加到集合
        if node not in visited:
            # 将当前节点添加到已访问集合中
            visited.add(node)
            # 如果当前节点是终点
            if node == end:
                # 返回长度，成本和路径
                return length, cost, path
            """
            代码中的 if edge not in visited:
                    # 将邻居节点添加到队列中
                    heapq.heappush(queue, (length + edge_length, cost + edge_cost, edge, path + [edge]))
                    是直接将所有该节点到所有邻居节点加入了优先权队列，
                    而不是像dijkstra原理的那样去更新源点到每个点的最短路径（也就是少了比较加更新），
                    因为使用了优先权队列来保证每次取出的都是最小未访问(未加入集合)的节点（其实这步相当于比较加选出）
            """
            # 遍历当前节点的所有邻居
            for edge, edge_length, edge_cost in graph[node]:
                # 如果邻居节点没有被添加到集合
                if edge not in visited:
                    # 将邻居节点添加到队列中
                    heapq.heappush(queue, (length + edge_length, cost + edge_cost, edge, path + [edge]))

# 定义main函数，用于读取输入并调用dijkstra函数
def main():
    # 读取城市数量，公路数量，起点和终点
    N, M, S, D = map(int, input().split())
    # 初始化图和成本数组
    graph = [[] for _ in range(N)]
    costs = [0 for _ in range(N)]
    # 读取公路信息
    for _ in range(M):
        city1, city2, distance, cost = map(int, input().split())
        # 将公路信息添加到图中
        graph[city1].append((city2, distance, cost))
        graph[city2].append((city1, distance, cost))
    # 调用dijkstra函数找到最短路径和最低成本
    length, cost, path = dijkstra(graph, costs, S, D)
    # 打印路径，长度和成本
    print(' '.join(map(str, path)), length, cost)

# 调用main函数
main()

