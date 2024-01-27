"""
Suppose a bank has K windows open for service. 
There is a yellow line in front of the windows which devides the waiting area into two parts. 
All the customers have to wait in line behind the yellow line, 
until it is his/her turn to be served and there is a window available. 
It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, 
you are supposed to tell the average waiting time of all the customers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^4) 
- the total number of customers, and K (≤100) - the number of windows.
Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, 
and P - the processing time in minutes of a customer. 
Here HH is in the range [00, 23], MM and SS are both in [00, 59]. 
It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. 
Anyone arrives early will have to wait in line till 08:00, 
and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:
For each test case, print in one line the average waiting time of all the customers, 
in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
"""
import heapq

# 将时间转换为秒
def time_to_sec(t):
    h, m, s = map(int, t.split(':'))
    return h * 3600 + m * 60 + s

# 将秒转换为时间
def sec_to_time(sec):
    h = sec // 3600
    m = (sec % 3600) // 60
    s = sec % 60
    return f"{h:02}:{m:02}:{s:02}"

# 输入客户数量和窗口数量
N, K = map(int, input().split())
# 存储客户信息的列表
customers = []
for _ in range(N):
    t, p = input().split()
    # 只处理在银行营业时间内到达的客户
    if t < "17:00:01":
        customers.append((time_to_sec(t), int(p) * 60))
# 按照到达时间排序
customers.sort()
# 初始化窗口队列
windows = [8 * 3600] * K
# 总等待时间
total_wait = 0
for arrive, process in customers:
    # 弹出最早空闲的窗口
    free = heapq.heappop(windows)
    if arrive < free:
        # 如果客户在窗口空闲之前到达，他需要等待
        total_wait += free - arrive
        # 窗口的下一个空闲时间
        next_free = free + process
    else:
        # 如果客户在窗口空闲之后到达，他不需要等待
        # 窗口的下一个空闲时间
        next_free = arrive + process
    # 将窗口的下一个空闲时间插入队列
    heapq.heappush(windows, next_free)
# 输出平均等待时间
print(f"{total_wait / 60 / len(customers):.1f}")
