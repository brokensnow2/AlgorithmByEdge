"""
在Python中，邻接矩阵和邻接表可以通过使用列表或字典来实现。以下是一些示例：
邻接矩阵：邻接矩阵通常用二维列表来实现。例如，对于一个有4个顶点（0, 1, 2, 3）的图，其邻接矩阵可以如下表示：
Python
"""
# 初始化邻接矩阵
adj_matrix = [[0, 1, 0, 1], 
              [1, 0, 1, 1], 
              [0, 1, 0, 1], 
              [1, 1, 1, 0]]

# 输出邻接矩阵
for row in adj_matrix:
    print(row)
# 在这个邻接矩阵中，adj_matrix[i][j]表示顶点i和顶点j之间是否存在边。
    

"""
邻接表：邻接表通常用字典或列表来实现。例如，对于同样的图，其邻接表可以如下表示：
Python
"""
# 使用字典实现邻接表
adj_list = {0: [1, 3], 
            1: [0, 2, 3], 
            2: [1, 3], 
            3: [0, 1, 2]}

# 输出邻接表
for vertex, edges in adj_list.items():
    print(vertex, edges)
# 在这个邻接表中，adj_list[i]表示与顶点i相邻的所有顶点的列表。
    
# 使用列表实现邻接表
adj_list = [[1, 3], 
            [0, 2, 3], 
            [1, 3], 
            [0, 1, 2]]

# 输出邻接表
for i, edges in enumerate(adj_list):
    print(i, edges)
"""
在这个邻接表中，adj_list[i]表示与顶点i相邻的所有顶点的列表。这种表示方法在处理无向图时非常方便，
因为你可以直接通过索引来访问任何顶点的邻居列表。然而，如果你正在处理有向图，或者边有权重，那么使用字典可能会更方便，
因为它可以更容易地存储和检索额外的信息。
"""

# 初始化邻接表
adj_list = [[1, 3], 
            [0, 2, 3], 
            [1, 3], 
            [0, 1, 2]]

# 添加一个顶点
def add_vertex(v):
    adj_list.append([])
    print(f"Vertex {v} is added.")

# 添加一条边
def add_edge(v1, v2):
    adj_list[v1].append(v2)
    adj_list[v2].append(v1)
    print(f"Edge between {v1} and {v2} is added.")

# 获取所有顶点
def get_vertices():
    return [i for i in range(len(adj_list))]

# 获取所有边
def get_edges():
    edges = []
    for v1 in range(len(adj_list)):
        for v2 in adj_list[v1]:
            if {v1, v2} not in edges and {v2, v1} not in edges:
                edges.append({v1, v2})
    return edges

# 获取一个顶点的所有邻居
def get_neighbors(v):
    return adj_list[v]

# 测试代码
add_vertex(4)
add_edge(4, 0)
print("Vertices:", get_vertices())
print("Edges:", get_edges())
print("Neighbors of 0:", get_neighbors(0))

