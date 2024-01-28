"""
数字三角形中寻找一条从顶部到底边的路径，使得
路径，上所经过的数字之和最大。路径上的每一步都只能往左下或
石下走。只需要求出这个最大和即可，不必给出具体路径。
三角形的行数人于小于等于100.数字为0-99

输入格式:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
要求输出最大和

用递归会超时，有重复计算
"""
# 定义一个函数MaxDistance，输入参数为i和j
def MaxDistance(i,j):
        # 如果i等于line-1（也就是到达了矩阵的最后一行）
        if i == line-1:
                # 返回当前位置的值
                return matrix[i][j]
        # 计算从当前位置向下走一步的最大距离
        a = MaxDistance(i+1,j)
        # 计算从当前位置向右下角走一步的最大距离
        b = MaxDistance(i+1,j+1)
        # 返回两者中的最大值加上当前位置的值
        return max(a,b) + matrix[i][j]

# 输入行数
line = int(input())
# 初始化一个长度为line的列表
matrix = [None for _ in range(line)]
# 对于每一行
for i in range(0,line):
        # 输入每一行的值，并将其转换为整数列表
        matrix[i] = list(map(int,input().split()))
# 打印从(0,0)开始的最大距离
print(MaxDistance(0,0))

        

