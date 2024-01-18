"""
农夫John建造了1座很长的畜栏(数轴)，它包括N (2<=N<=100,000)个隔
间，这些小隔间的位置为X0,...Xn-1 (0<=Xi<=1000000000,均为整数,各不相
同).
John的C (2<=C<=N)头牛每头分到一个隔间。牛都希望互相离得远点省得互
相打扰。怎样才能使最近的两头牛之间的距离尽可能的大，这个"最大的
最近距离D"是多少呢?

"""
def check(mid, x, c):
    count = 1
    last = x[0]
    for i in range(1, len(x)):
        if x[i] - last >= mid:
            last = x[i]
            count += 1
    return count >= c

def max_distance(x, c):
    x.sort()
    left = 0
    # x[-1]和x[len(x)-1]都是指的列表x的最后一个元素。这是因为Python支持负索引，-1表示最后一个元素，-2表示倒数第二个元素，以此类推
    right = x[-1] - x[0] 
    while right - left > 1:
        mid = (left + right) // 2 # 用来计算 left 和 right 两个数的整数平均值的
        if check(mid, x, c):
            left = mid
        else:
            right = mid
    return left

# 测试
x = [1, 2, 4, 8, 9]
c = 3
print(max_distance(x, c))  # 输出：3
