"""
输出抓牛的所有的最短路径
Input:
3 5
Output:
3 4 5
3 6 5

思想：记住层数来减枝
"""

import queue
# bfs来找到最小层数
def bfs():
    visited = [0]*100001
    q = queue.Queue()
    # (N,0):元组：数字，时间（层数:从0开始算）
    q.put((N,0))
    while not q.empty():
        node = q.get()
        if node[0] == K:
            return node[1]
            break
        # 防止越界
        if node[0]-1 >= 0 and visited[node[0]-1] == 0:
            q.put((node[0]-1,node[1]+1))
            visited[node[0]-1] = 1
        if node[0]+1 <= 100000 and visited[node[0]+1] == 0:
            q.put((node[0]+1,node[1]+1))
            visited[node[0]+1] = 1
        if node[0]*2 <= 100000 and visited[node[0]*2] == 0:
            q.put((node[0]*2,node[1]+1))
            visited[node[0]*2] = 1

# dfs获得所有路径
def dfs(node :int, layer: int, path = ""):
    """
    param layer:从1开始算。比如  3 4 5 :路径有三个点，三层
    """
    if node == K and layer+1 == maxLayer:
        print(f"{path} {K}")
    # 最后一层不加入访问节点：因为3->2->4,这里把4访问加入的话,3->4->5就不行
    # 倒数第二层往上要加入visited中
    if node not in visited and layer+1 != maxLayer :
        visited.add(node)
        path = path + f" {node}"
        layer += 1

        # 减枝,保证下方不会做太多无用功 ，其实上面layer+1 != maxLayer就已经减枝了，下方的所有if都在上面的if语句下
        #if layer > maxLayer:
        #    return
        
        # 同样防止越界
        if node*2 not in visited and node * 2 < 10000:
            dfs(node*2,layer,path)
        if node-1 not in visited and node-1 > 0:
            dfs(node-1,layer,path)
        if node+1 not in visited and node+1 < 10000:
            dfs(node+1,layer,path)

N,K = map(int,input().split())
visited = set()
# 用bfs来找到最小层数
maxLayer = bfs()+1
dfs(N,0)