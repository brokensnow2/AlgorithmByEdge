"""
场景中包括多个长度和高度各不相同的平台。
地面是最低的平台,高度为零,长度无限。
Jimmy老鼠在时刻0从高于所有平台的某处开始下落
它的下落速度始终为1米/秒。当Jimmy落到某个平台.上
时,游戏者选择让它向左还是向右跑,它跑动的速度
也是1米/秒。当Jimmy跑到平台的边缘时,开始继续下
落。Jimmy每次下落的高度不能超过MAX米, 不然就
会摔死
游戏也会结束。
设计一-个程序,计算Jimmy到地面时可能的最早时间。
输入数据
第1行是测试数据的组数t (0 <= t <= 20 )。每组测试数据的第一行是
四个整数N , X, Y , MAX ,用空格分隔。N是平台的数目(不包括地面)
X和Y是Jimmy开始下落的位置的横竖坐标, MAX是一次下落的最大高度。接
下来的N行每行描述一个平台 ,包括三个整数, X1[i] , X2[i]和H[i]。H[i]表示
平台的高度, X1[i]和X2[i]表示平台左右端点的横坐标。1 <= N <= 1000 ,
-20000<=X,X1[i],X2[i]<=20000，0<H[i]<Y<=20000(i=1..N)。
所有坐标的单位都是米。
Jimmy的大小和平台的厚度均忽略不计。如果Jimmy恰好落在某个平台的
边缘,被视为落在平台上。所有的平台均不重叠或相连。测试数据保证Jimmy
一定能安全到达地面。

输出要求
对输入的每组测试数据,输出一个整数,
Jimmy到地面时可能的最早时间。
输入样例
3 8 17 20
0 10 8
0 10 13
4 14 3
输出样例
23


"""

from heapq import *

INF = 1 << 60  # 定义一个无穷大的数

class Platform:
    def __init__(self, x1, x2, h):
        self.x1 = x1  # 平台左端点的横坐标
        self.x2 = x2  # 平台右端点的横坐标
        self.h = h  # 平台的高度

def solve():
    platforms.sort(key=lambda p: p.h)  # 按照平台的高度进行排序
    dp = [INF] * (N+2)  # 初始化动态规划数组
    dp[0] = 0  # 初始状态，Jimmy在最高的平台上，所以逆序数为0
    heap = [(0, 0)]  # 初始化堆，存储每个平台的最小花费
    while heap:  # 当堆不为空时
        cost, idx = heappop(heap)  # 弹出堆顶元素，即当前花费最小的平台
        if dp[idx] < cost:  # 如果当前平台的最小花费已经被更新，则跳过
            continue
        for i in range(N+2):  # 遍历所有平台
            if abs(platforms[i].h - platforms[idx].h) > MAX:  # 如果下落的高度超过MAX，则跳过
                continue
            tmp = abs(platforms[i].x1 - platforms[idx].x2) + abs(platforms[i].h - platforms[idx].h)  # 计算从当前平台跳到下一个平台的花费
            if dp[i] > dp[idx] + tmp:  # 如果新的花费小于原来的花费，则更新
                dp[i] = dp[idx] + tmp
                heappush(heap, (dp[i], i))  # 将新的花费和平台索引推入堆中
            tmp = abs(platforms[i].x2 - platforms[idx].x2) + abs(platforms[i].h - platforms[idx].h)  # 计算从当前平台的另一端跳到下一个平台的花费
            if dp[i] > dp[idx] + tmp:  # 如果新的花费小于原来的花费，则更新
                dp[i] = dp[idx] + tmp
                heappush(heap, (dp[i], i))  # 将新的花费和平台索引推入堆中
    return dp[N+1]  # 返回到达地面的最小花费

T = int(input())  # 读取测试数据的组数
for _ in range(T):  # 对于每组测试数据
    N, X, Y, MAX = map(int, input().split())  # 读取N, X, Y, MAX
    platforms = [Platform(X, X, Y)]  # 初始化平台列表，首先添加Jimmy开始下落的位置
    for _ in range(N):  # 对于每个平台
        x1, x2, h = map(int, input().split())  # 读取平台的信息
        platforms.append(Platform(x1, x2, h))  # 将平台添加到列表中
    platforms.append(Platform(-INF, INF, 0))  # 添加地面作为一个平台
    print(solve())  # 调用solve函数计算并打印结果

