"""
假设一家银行有N个窗口可供服务。窗户前有一条黄线，把等候区分成两部分。顾客排队等候的规则是：
每个窗口前面的黄色线内的空间足以容纳一行M个客户。因此，当所有N条路都满了时，
在（NM+1）条路之后（包括）的所有客户将不得不在黄线之后的线路中等待。
每位顾客在越过黄线时都会选择最短的队伍等候。如果有两条或多条相同长度的线，客户将始终选择数量最小的窗口。
前N位客户的服务时间假定为上午8:00
现在，考虑到每个客户的处理时间，您应该告诉客户完成业务的确切时间。

输入规范：
每个输入文件包含一个测试用例。每种情况都以一行开始，该行包含4个正整数：
N（≤20，窗口数）、M（≤10，黄线内每行的最大容量）、K（≤1000，客户数）和Q（≤1000、客户查询数）。
下一行包含K个正整数，这是K个客户的处理时间。
最后一行包含Q个正整数，表示询问完成交易时间的客户。客户编号从1到K。
输出规格：
对于每个Q客户，在一行中打印他/她的交易完成的时间，格式为HH:MM，其中HH在[08，17]中，MM在[00，59]中。
请注意，由于银行每天17:00后关闭，对于17:00前无法服务的客户，您必须输出Sorry
Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

Sample Output:
08:07
08:06
08:10
17:00
Sorry

解题思路:
前NM个顾客是按照窗口号0,1,2,3,4,5...,N-1,0,1,2,3,...这样排的
第NM+1个会加入第一个结束时间最早的窗口
队列存每个窗口的顾客
堆用来存窗口结束时间
"""
N,M,K,Q = map(int,input().split())
# 每个客户处理时间，编号从1开始
spendTime = [0] + list(map(int,input().split()))
# 查询的客户
queryCostomers = list(map(int,input().split()))
import heapq
# 窗口
windows = []
import queue
# 排队的人
lines = [queue.Queue() for i in range(N)]
# 每个人的结束时间
endTime = [None for i in range(K+1)]

if K > N * M: # 先把前NM个顾客排好
    for i in range(N * M):
        lines[i % N].put(i+1)
        
    for i in range(N): # 插入结束时间,窗口编号,顾客编号
        heapq.heappush(windows,(480+spendTime[i+1], i, i+1))

    for i in range(1,K+1):
        node = heapq.heappop(windows)
        endTime[node[2]] = node[0]
        lines[node[1]].get() # 用完了就走
        if N*M+i <= K:
            # 加入队列
            lines[node[1]].put(N*M+i)
        if not lines[node[1]].empty(): # 该队列不为空
            nextNode = lines[node[1]].queue[0] # 查看第一个元素，不取
            heapq.heappush(windows,(node[0]+spendTime[nextNode],node[1],nextNode))

else: # 要是小于N*M的话
    for i in range(K):
        lines[i % N].put(i+1)
    if K >= N:
        for i in range(N): # 插入结束时间,窗口编号,顾客编号
            heapq.heappush(windows,(480+spendTime[i+1], i, i+1))
    else:
        for i in range(K):
            heapq.heappush(windows,(480+spendTime[i+1], i, i+1))
    for i in range(1,K+1):
        node = heapq.heappop(windows)
        endTime[node[2]] = node[0]
        lines[node[1]].get() # 用完了就走
        if N*M+i <= K:
            # 加入队列
            lines[node[1]].put(N*M+i)
        if not lines[node[1]].empty(): # 该队列不为空
            nextNode = lines[node[1]].queue[0] # 查看第一个元素，不取
            heapq.heappush(windows,(node[0]+spendTime[nextNode],node[1],nextNode))

for i in queryCostomers:
    if endTime[i] is not None and endTime[i] <= 1020:
        hours, minutes = divmod(endTime[i], 60)
        print(f"{hours:02d}:{minutes:02d}")
    else:
        print("Sorry")
