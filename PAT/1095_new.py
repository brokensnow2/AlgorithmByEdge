import heapq
from collections import defaultdict

def time2sec(time :str) -> int:
    hour,minute,second = map(int,time.split(':'))
    return hour * 3600 + minute * 60 + second

# N个记录，K条查询
N,K = map(int,input().split())
# 字典一，用来排序和合成时间对
records = defaultdict(list)
# 字典2，存储不同车的时间对
records2 = defaultdict(list)
# 初始化数据结构
for _ in range(N):
    ID,*record = input().split()
    sec = time2sec(record[0])
    records[ID].append((sec,record[1]))
for i in records:
    records[i].sort()
    for j in range(len(records[i])):
        if records[i][j][1] == 'out':
            pass
        else:
            if j+1 <= len(records[i])-1 and records[i][j+1][1] == 'out':
                records2[i].append((records[i][j][0],records[i][j+1][0]))

# Query列表
query = []
for _ in range(K):
    query.append(time2sec(input()))

# 使用堆来存储当前在校园内的车辆
heap = []
# 遍历所有的车辆和它们的进出记录，将它们添加到堆中
for car_id, time_pairs in records2.items():
    for pair in time_pairs:
        # 将进入时间和车牌号添加到堆中
        heapq.heappush(heap, (pair[0], car_id))
        # 将离开时间和车牌号添加到堆中
        heapq.heappush(heap, (pair[1], car_id))

# 查询的结果
ans = []
# 当前在校园内的车辆
current_cars = set()
# 遍历所有的查询
for q in query:
    # 将所有在查询时间之前进入校园的车辆添加到current_cars中
    while heap and heap[0][0] <= q:
        time, car_id = heapq.heappop(heap)
        if car_id in current_cars:
            current_cars.remove(car_id)
        else:
            current_cars.add(car_id)
    # 将当前在校园内的车辆数量添加到结果中
    ans.append(len(current_cars))

for i in ans:
    print(i)

# 寻找停车时间最长的汽车
max_parked_time = 0
max_parked_cars = []
for car_id, time_pairs in records2.items():
    parked_time = 0
    for pair in time_pairs:
        parked_time += pair[1] - pair[0]
    if parked_time > max_parked_time:
        max_parked_time = parked_time
        max_parked_cars = [car_id]
    elif parked_time == max_parked_time:
        max_parked_cars.append(car_id)

# 输出停车时间最长的汽车
max_parked_cars.sort()
print(" ".join(max_parked_cars), end=" ")
print("{:02d}:{:02d}:{:02d}".format(max_parked_time // 3600, (max_parked_time % 3600) // 60, max_parked_time % 60))
