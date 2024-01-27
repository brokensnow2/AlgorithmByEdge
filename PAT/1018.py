"""
公共自行车管理中心（PBMC）持续监控所有站点的实时容量。如果一个加油站刚好满了一半，那么它就处于完美状态。
如果一个加油站已满或空，PBMC将收集或发送自行车，以将该加油站的状况调整到完美状态。此外，途中的所有车站也将进行调整。
当报告有问题的站点时，PBMC将始终选择到达该站点的最短路径。如果有多条最短路径，将选择PBMC发送的自行车数量最少的路径。

输入规范：
每个输入文件都包含一个测试用例。对于每种情况，第一行包含 4 个数字：
Cmax（<100），始终为偶数，为各站最大容量;
N（≤500），为站总数;
Sp，问题站的索引（站编号从1到N，PBMC用顶点0表示）;
M， 道路数
第二行包含N个非负数Ci（i=1，…，N）其中每个C
是目前S的自行车数量
分别地接下来是M行，每行包含3个数字：Si,Sj和Tij:其描述从Si到Sj的时间。
一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，将结果打印在一行中。首先输出PBMC必须发送的自行车数量。然后在一个空格后，以以下格式输出路径：0−>S
1−>……−>Sp.最后，在一个空格后,输出在S的条件下我们必须带回PBMC的自行车数量
调整到完美。
请注意，如果这样的路径不是唯一的，请将需要最少自行车数量的路径输出给PBMC。测试的数据保证了这种路径是唯一的。

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
"""
import heapq

def Dijsktra(graph,start,end):
    """
    param graph:图
    param start:起点
    param end:终点
    param send:发送
    param tske:带回
    """
    
    # 满了
    if cars[end] == Cmax:
        # 优先权队列 (花费时间;发送数量;带回数量;起点;路径)
        # 带回5辆
        queue = [(0,0,5,start,[start])]
    # 不然是空的
    else:
        # 发送5辆
        queue = [(0,5,0,start,[start])]
    # 访问数组
    visited = set()
    while queue:
        # 弹出最小的cost,send和take的node
        node = heapq.heappop(queue)
        if node[2] not in visited:
            # 弹出的添加进visited
            visited.add(node[2])
            if node[2] == end:
                return node[1],node[2],node[4]
            else:
                for i in graph[node[3]]:
                    if i[0] not in visited:
                        # 大于平衡要带回或者给其他需要的站--send不等于0
                        if cars[i[0]] > balance:
                            # --send不等于0
                            if node[1] != 0:
                                result = node[0] - (cars[i[0]] - balance)
                                # send还有剩:还需要发送
                                if result > 0:
                                    heapq.heappush(queue,(node[0]+i[1], result, node[2], i[0], node[4]+[i[0]]))
                                # 不需要发送，也许要带回
                                else:
                                    heapq.heappush(queue,(node[0]+i[1], 0, abs(result), i[0], node[4]+[i[0]]))
                            # send等于0
                            else:
                                heapq.heappush(queue,(node[0]+i[1], 0, node[2] + cars[i[0]] - balance, i[0], node[4]+[i[0]]))
                        # 小于平衡就要发送
                        else:
                            # 如果有要带回的
                            if node[2] != 0:
                                result = node[2] - (balance - cars[i[0]])
                                if result > 0 :
                                    # 还要带回
                                    heapq.heappush(queue,(node[0]+i[1], node[1], result, i[0], node[4]+[i[0]]))
                                    




Cmax,N,Sp,M = map(int,input().split())
# 地图，邻接表
stations = [[] for _ in range(N+1)]
# 每个车站的车辆数
cars = [0]
# 车站编号从1开始
cars = cars + list(map(int,input().split()))
for i in range(M):
    Si,Sj,Tij = map(int,input().split())
    stations[Si].append((Sj,Tij))
    stations[Sj].append((Si,Tij))
balance = Cmax // 2
send,take,path = Dijsktra(stations,0,Sp)
print(f"{send} {'->'.join(path)} {take}")
