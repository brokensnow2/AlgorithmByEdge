"""
思想差不多，原代码是乘，这个是除
从2开始循环，630%2=0;继续:315%3=0；继续：105%4！=0；退出；
再从3开始：630 % 3=0，继续：310%4！=0，退出，。。。
到5了，630%5=0,126%6=0，21%7=0...
"""
def find_consecutive_factors(N):  # 定义一个函数，输入是一个正整数N
    max_len = 0  # 初始化连续因子的最大数量为0
    start = 0  # 初始化连续因子的起始值为0
    for i in range(2, int(N**0.5)+1):  # 从2开始，到N的平方根结束，尝试所有可能的起始因子
        temp = N  # 将N的值赋给临时变量temp
        j = i  # 设置当前因子为起始因子
        while temp % j == 0:  # 当temp能被j整除时，继续循环
            temp /= j  # 更新temp的值，将其除以当前的因子j
            if j - i + 1 > max_len:  # 如果当前的连续因子数量大于最大连续因子数量
                max_len = j - i + 1  # 更新最大连续因子数量
                start = i  # 更新连续因子的起始值
            j += 1  # 尝试下一个因子
    if max_len == 0:  # 如果没有找到连续因子
        return 1, [N]  # 返回1和N本身
    else:  # 如果找到了连续因子
        return max_len, list(range(start, start+max_len))  # 返回最大连续因子数量和连续因子序列

# 测试用例
N = int(input())  # 从用户那里获取输入
max_len, factors = find_consecutive_factors(N)  # 调用函数，获取最大连续因子数量和连续因子序列
print(max_len)  # 打印最大连续因子数量
print('*'.join(map(str, factors)))  # 打印连续因子序列，因子之间用*分隔
