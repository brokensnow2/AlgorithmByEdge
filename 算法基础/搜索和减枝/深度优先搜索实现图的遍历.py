# 定义DFS函数
def DFS(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    # 访问节点邻居
    for next in graph[start] - visited:
        DFS(graph, next, visited)
    return visited

# 定义图
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}

print(DFS(graph, 'A'))
