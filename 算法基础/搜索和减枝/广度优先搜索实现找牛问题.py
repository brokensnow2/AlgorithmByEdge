"""
抓住那头牛(P0J3278)

农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上
农夫起始位于点N (0<=N<=100000)，牛位于点K (0<=K<=1 00000)
农夫有两种移动方式:
1、从X移动到X-1或X+1， 每次移动花费一分钟
2、从X移动到2*X，每次移动花费一分钟
假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多久才能抓到那头牛

"""
import queue

N,K = map(int,input().split())
visited = [0]*100001
q = queue.Queue()
# (N,0):元组：数字，时间（层数）
q.put((N,0))
while not q.empty():
    node = q.get()
    if node[0] == K:
        print(node[1])
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
