"""
思路：顺着走，逆着走，min()
注意编号从1开始
会超时，重复计算
"""
# 行1
line1 = list(map(int,input().split()))
# N个出口,刚好出口编号和下标都从1开始
N = line1[0]
# 要计算的次数
count = int(input())
pairList = []
for _ in range(count):
    pairList.append(list(map(int,input().split())))
# 输出
for i in range(count):
    origin = pairList[i][0]
    to = pairList[i][1]
    sum = 0
    sum1 = 0
    if origin < to:
        # 正着走
        for i in range(origin,to):
            sum += line1[i]
        # 逆着走
        for i in range(to,N+1):
            sum1 += line1[i]
        for i in range(1,origin):
            sum1 += line1[i]
    else:
        # 正着走
        for i in range(origin,N+1):
            sum1 += line1[i]
        for i in range(1,to):
            sum1 += line1[i]
        # 逆着走
        for i in range(to,origin):
            sum += line1[i]
    print(min(sum,sum1))