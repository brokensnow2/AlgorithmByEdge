# 定义函数以找到图中从起点到终点的所有路径
def find_all_paths(graph, start, end, path=[]):
    # 将起点添加到路径中
    path = path + [start]
    # 如果起点和终点相同，那么我们找到了一条路径
    if start == end:
        return [path]
    # 如果起点不在图中，返回空列表
    if start not in graph:
        return []
    # 初始化路径列表
    paths = []
    # 遍历起点的所有邻居节点
    for node in graph[start]:
        # 如果邻居节点不在当前路径中
        if node not in path:
            # 递归地找到从邻居节点到终点的所有路径 
            newpaths = find_all_paths(graph, node, end, path)
            
            # 将找到的新路径添加到路径列表中
            for newpath in newpaths:
                paths.append(newpath)
    # 返回所有找到的路径
    return paths

# 测试代码
# 定义图
graph = {'A': ['B', 'C'],
         'B': ['C', 'D'],
         'C': ['D'],
         'D': ['C'],
         'E': ['F'],
         'F': ['C']}

print(find_all_paths(graph, 'A', 'D')) # [['A', 'B', 'C', 'D'], ['A', 'B', 'D'], ['A', 'C', 'D']]
print(find_all_paths(graph, 'F', 'B')) # []
