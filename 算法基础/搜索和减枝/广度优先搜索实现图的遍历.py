# 定义BFS函数
def BFS(graph, start, visited=None):
    # 队列
    quene = [start]
    if visited is None:
        visited = set()
    while quene != []:
        node = quene.pop()
        visited.add(node)
        for i in graph[node] - visited:
            quene.append(i)
    return visited

    

# 定义图
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
print(BFS(graph, 'A'))

# 定义图：连通
graph1 = [[1,2,3], # 0号节点
          [0,3], # 1号
          [0,1,4,5],
          [1,2,5],
          [1,3,5],
          [0,1,3]]

# 定义BFS函数
from collections import deque

def BFS1(graph, start):
    queue = [start]
    visited = set()  # 将visited初始化为一个集合
    visited.add(start)  # 将起始节点加入visited

    while queue:
        node = queue.pop(0)
        visited.add(node)  # 将新访问的节点加入visited
        for i in graph[node]:
            if i not in visited:  # 在将节点加入队列之前检查它是否已经被访问过
                queue.append(i)
    return list(visited)  # 如果需要的话，可以将visited转换回列表

print(BFS1(graph1,0))
