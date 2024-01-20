"""
在战争中，让所有城市通过高速公路连接起来至关重要。
如果一个城市被敌人占领，则所有进出该城市的高速公路都将关闭。我们必须立即知道我们是否需要修复任何其他高速公路以保持其他城市的连接。
给定标记了所有剩余高速公路的城市地图，您应该快速告诉需要修复的高速公路数量。
例如，如果我们有3个城市和2条高速公路连接城市1-城市2和城市1-城市3。那么如果城市1被敌人占领了，我们必须修复一条公路，那就是城市2-城市3
输入规范：
每个输入文件包含一个测试用例。每种情况都从一条包含3个数字N（<1000）、M和K的线开始，
这3个数字分别是城市总数、剩余高速公路数量和要检查的城市数量。
接下来是M条线，每条线用2个整数来描述一条公路，这是公路连接的城市的数量。
城市的编号从1到N。
最后有一条包含K个数字的线，代表我们关注的城市。
输出规格：
对于K个城市中的每一个，如果该城市丢失，则一条线路中需要修复的公路数量。
Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
"""

"""
图判断连通分量,有两个就要修一条路，三个修两条路
使用深度优先搜索（DFS）或广度优先搜索（BFS）来找出每个城市被占领后，剩余城市的连通分量的数量。
如果一个城市被占领后，剩余城市的连通分量的数量增加了，那么就需要修复一些公路来保持所有城市的连通性。
"""
def dfs(city, graph, visited):
    visited[city] = True
    for neighbor in graph[city]:
        if not visited[neighbor] :
            dfs(neighbor, graph, visited)

def count_components(graph, occupied):
    visited = [False] * len(graph)
    visited[occupied] = True
    count = 0
    for city in range(len(graph)):
        if not visited[city]:
            dfs(city, graph, visited)
            count += 1
    return count


N, M, K = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    # 编号从1开始，下标从0开始
    city1, city2 = map(int, input().split())
    graph[city1-1].append(city2-1)
    graph[city2-1].append(city1-1)
concerned_cities = list(map(int, input().split()))

for city in concerned_cities:
    print(count_components(graph, city-1) - 1)
