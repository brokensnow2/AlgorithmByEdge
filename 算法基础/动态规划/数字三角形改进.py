"""
数字三角形的记忆递归型动归程序
"""
# 定义一个函数MaxDistance，输入参数为i和j
def MaxDistance(i,j):
        # 如果i等于line-1（也就是到达了矩阵的最后一行）
        if i == line-1:
                # 返回当前位置的值
                return matrix[i][j]
        # 如果dp[i][j]已经计算过，直接返回结果
        if dp[i][j] != -1:
                return dp[i][j]
        # 计算从当前位置向下走一步的最大距离
        a = MaxDistance(i+1,j)
        # 计算从当前位置向右下角走一步的最大距离
        b = MaxDistance(i+1,j+1)
        # 将结果存入dp[i][j]中
        dp[i][j] = max(a,b) + matrix[i][j]
        # 返回dp[i][j]
        return dp[i][j]

# 输入行数
line = int(input())
# 初始化一个长度为line的列表
matrix = [None for _ in range(line)]
# 初始化dp矩阵，所有元素都为-1
dp = [[-1 for _ in range(line)] for _ in range(line)]
# 对于每一行
for i in range(0,line):
        # 输入每一行的值，并将其转换为整数列表
        matrix[i] = list(map(int,input().split()))
# 打印从(0,0)开始的最大距离
print(MaxDistance(0,0))
