"""
如果灯原来是点亮的，就会被熄灭
如果灯原来是熄灭的，则会被点亮
在矩阵角上的按钮改变3盏灯的状态
在矩阵边上的按钮改变4盏灯的状态
其他的按钮改变5盏灯的状态
与一盏灯毗邻的多个按钮被按下时,一个操作会抵消另一次操
作的结果

给定矩阵中每盏灯的初始状态，求一-种按按钮方案，使得所有
的灯都熄灭

样例输入:
2
011010
100111
001001
100101
011100
001010
101011
001011
101100
010100

样例输出:
PUZZLE #1
101001
110101
00l011
100100
010000
PUZZLE #2
100111
110000
000100
110101
101101

"""


N = int(input())
rows = 5
matrix_list = [[None for _ in range(rows)] for _ in range(N)] # 创建二维列表
# print(matrix_list)# N个5行[[None, None, None, None, None],[None, None, None, None, None],...]
for i in range(N):
    for j in range(rows):
        str = input()
        row = list(str)
        matrix_list[i][j] = row # 每个元素都是大小为6的列表，matrix_list是3维列表了
# print(matrix_list[0]) # [['1', '1', '1', '1', '1', '1'], ['1', '1', '1', '1', '1', '1'], ['1', '1', '1', '1', '1', '1'], ['1', '1', '1', '1', '1', '1'], ['1', '1', '1', '1', '1', '1']]
# print(type(matrix_list[0][0])) # <class 'list'>
