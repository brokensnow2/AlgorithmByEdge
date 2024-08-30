"""
浙江大学有8个校区和许多大门。我们可以从每个大门收集通过大门的汽车的进出时间和车牌号。
现在，有了所有可用的信息，你应该在任何特定的时间点告诉校园里停车的汽车数量，并在一天结束时找到停车时间最长的汽车。
输入规范：
每个输入文件包含一个测试用例。每种情况都以两个正整数N（≤10^4.)，记录的数量，以及K（≤8×10^4.)查询的数量。
接下来是N行，每行给出一条记录，格式如下：
板材编号hh:mm:ss状态
其中plate_number是由7个英文大写字母或1位数组成的字符串；hh:mm:ss按小时：分钟：秒表示一天中的时间点，最早时间为00:00:00，
最晚时间为23:59:59；并且状态是in或out。
请注意，所有时间都将在一天内。每个输入记录都与同一辆车的按时间顺序排列的下一个记录配对，前提是它是一个输出记录。
任何未与出记录配对的入记录都将被忽略，未与入记录配对的出记录也将被忽略。
可以保证至少有一辆车在输入中配对良好，并且没有一辆车同时进出。使用24小时时钟记录时间。
接下来是K行查询，每行都以hh:mm:ss的格式给出一个时间点。注：查询按时间升序排列。
输出规格：
对于每个查询，在一行中输出校园内停车的汽车总数。最后一行输出应该给出停车时间最长的汽车的车牌号和相应的时间长度。
如果这样的汽车不是唯一的，那么按字母顺序输出它们的所有车牌号，并用空格隔开。

16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
"""
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

# 查询的结果
ans = []

# 遍历,三层for，太慢了
for i in query:
    count = 0
    for j in records2:
        for k in records2[j]:
            if i >= k[0] and i < k[1]:
                count += 1
    ans.append(count)
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
