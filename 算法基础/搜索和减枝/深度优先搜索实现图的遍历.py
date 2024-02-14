# 定义DFS函数
def DFS(graph, start, visited :set, kidMap :list):
    visited.add(start)
    kidMap.append(start)
    # 访问节点邻居
    for next in graph[start] - visited:
        DFS(graph, next, visited, kidMap)

# 定义图:非连通
graph = {'A': set(['B', 'C']),
         'B': set(['A']),
         'C': set(['A']),
         'D': set(['E']),
         'E': set(['D', 'F']),
         'F': set(['E'])}

# 遍历;要for循环
visited = set()
kidMaps = []
for node in graph:
    if node not in visited:
        kidMap = []
        DFS(graph, node, visited, kidMap)
        kidMaps.append(kidMap)
print(kidMaps)