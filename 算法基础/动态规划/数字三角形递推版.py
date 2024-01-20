"""
循环版
进一步考虑，连maxSum数组都可以不要，直接用D的
第n行替代maxSum即可。
节省空间，时间复杂度不变

"""

# 输入行数
line = int(input())
# 初始化一个长度为line的列表
matrix = [None for _ in range(line)]
# 对于每一行
for i in range(0,line):
        # 输入每一行的值，并将其转换为整数列表
        matrix[i] = list(map(int,input().split()))
# maxSum指向第n行
maxSum = matrix[line-1]
# 从下往上更新maxSum
"""
range(n-1, 0, -1)是一个生成器，它会生成一个从n-1开始，到1结束（不包括0），步长为-1的整数序列。
也就是说，它会生成n-1, n-2, ..., 3, 2, 1这样的一个序列。
"""
for i in range(line-2, -1, -1):
    for j in range(0, i+1):
        maxSum[j] = max(maxSum[j], maxSum[j+1]) + matrix[i][j]
# 输出最大和
print(maxSum[0])