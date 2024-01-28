"""
A graph which is connected and acyclic can be considered a tree. 
The height of the tree depends on the selected root. 
Now you are supposed to find the root that results in a highest tree. 
Such a root is called the deepest root.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive integer N (≤10^4) which is the number of nodes, 
and hence the nodes are numbered from 1 to N. Then N−1 lines follow, 
each describes an edge by given the two adjacent nodes' numbers.

Output Specification:
For each test case, print each of the deepest roots in a line. 
If such a root is not unique, print them in increasing order of their numbers. 
In case that the given graph is not a tree, print Error: K components where K is the number of connected components 
in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
"""

# 导入 defaultdict，用于创建默认字典
from collections import defaultdict

# 定义深度优先搜索函数
def DFS(node, graph, visited):
    # 标记节点为已访问
    visited[node] = True
    # 初始化深度和最深根节点列表
    depth = -1
    deepest_roots = []
    # 使用栈进行深度优先搜索
    stack = [(node, 0)]
    while stack:
        # 弹出栈顶节点
        node, node_depth = stack.pop()
        # 更新深度和最深根节点列表
        if node_depth > depth:
            depth = node_depth
            deepest_roots = [node]
        elif node_depth == depth:
            deepest_roots.append(node)
        # 将未访问的邻居节点压入栈中
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                stack.append((neighbor, node_depth + 1))
    # 返回最深根节点列表
    return deepest_roots

# 读取节点数量
N = int(input())
# 创建图
graph = defaultdict(list)
# 读取边的信息
for _ in range(N - 1):
    node1, node2 = map(int, input().split())
    # 将边添加到图中
    graph[node1].append(node2)
    graph[node2].append(node1)

# 初始化访问标记列表
visited = [False] * (N + 1)
# 执行深度优先搜索找到最深根节点
deepest_roots1 = DFS(1, graph, visited)

# 检查图是否是一棵树
if not all(visited[1:]):
    print(f"Error: {visited.count(False) - 1} components")
else:
    # 重新初始化访问标记列表
    visited = [False] * (N + 1)
    # 再次执行深度优先搜索找到最深根节点
    deepest_roots2 = DFS(deepest_roots1[0], graph, visited)
    # 找到所有最深根节点
    deepest_roots = sorted(set(deepest_roots1 + deepest_roots2))
    # 打印最深根节点
    print("\n".join(map(str, deepest_roots)))

