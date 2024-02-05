"""
族层次结构通常由谱系树表示，其中同一级别上的所有节点都属于同一代。你的任务是找到人口最多的一代人。
输入规范：
每个输入文件包含一个测试用例。每种情况都以两个正整数N（＜100）和M（＜N）开始，
N是树中家庭成员的总数（因此假设所有成员的编号从01到N），M是有孩子的家庭成员的数量。接下来是M行，每行包含以下格式的家庭成员信息：
ID K ID[1]ID[2]。。。ID[K]
其中ID是代表家庭成员的两位数，K（>0）是他/她的孩子的编号，后面是他/她孩子的两位数ID序列。
为了简单起见，让我们将根ID固定为01。一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，在一行中打印最大的总体数量和相应生成的级别。假设这样的生成是唯一的，并且根级别被定义为1。
Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
"""
from collections import defaultdict

# 节点数，非叶节点数
N,M = map(int,input().split())
# 家庭成员信息
memberData = defaultdict(list)
# 每层的节点总数：(总数，层次)
level_total = [(1,1)]
# 计数器
count = 0
floor = 2

# 初始化
for i in range(M):
    ID,*kids = map(int,input().split())
    memberData[ID].append(kids) # 值是列表套着层列表 eg: 1:[[4, 3, 2, 4, 5]]

# 初始a是第一层
a = [1]
# b作为中转列表，存下一层的节点
b = []

while a != []:
    for i in a:
        if memberData[i] != []:
            count += memberData[i][0][0]
            b += memberData[i][0][1::]
        else:
            pass
    a = b
    b = []
    level_total.append((count,floor))
    count = 0
    floor += 1
result = max(level_total, key=lambda x:x[0])
print(result[0],result[1])
