"""
有一块矩形大蛋糕，宽和高分别是整数width 、height。现要将其切成m块小蛋糕，每个小蛋糕都必须是矩形、且宽和高均为整数。
切蛋糕时，每次切一块蛋糕，将其分成两个矩形蛋糕。请计算：最后得到的m块小蛋糕中，最大的那块蛋糕的面积下限。
      宽
    ------
    |    |
    |    |  高
    |    |
    |----|
输入
共有多行，每行表示一个测试案例。每行是三个用空格分开的整数w, h, m ，其中1 ≤ w, h, m ≤ 20 ， m ≤ wh. 
当 w = h = m = 0 时不需要处理，表示输入结束。
输出
每个测试案例的结果占一行，输出一个整数，表示最大蛋糕块的面积下限。
样例输入
4 4 4
4 4 3
0 0 0
样例输出
4
6

解题思路：
设ways(w,h,m)表示宽和高分别是整数w 、h，被切m刀后，最大的那块蛋糕的面积最小值
题目就是要求ways(W, H, M-1)
边界条件:
if w*h<m+1
    INF # 因为面积最小为1，面积为n最多切n-1刀：面积为1切不了；面积为2最多切1刀
if m==0
    w*h

递推式:
SV为第一刀竖着切时能得到的最好结果，SH为第一刀横着切时能得到的最好结果，
则ways (w,h,m) = min(SV, SH)
SV=min{Si，i=1...w-1},
其中: Si=为第一刀左边宽为i的情况下的最好结果:
Si = min{ max(ways(i,h,k), ways(w-i,h, m-1-k)), k= 0... m-1 }
#  max(ways(i,h,k), ways(w-i,h, m-1-k): 取出该种切法下最大的那块
#  min{ max(ways(i,h,k), ways(w-i,h, m-1-k)) ： 取出不同切法下最大块相对更小的那块

SH = min{Sj, j=1,...,h-1}
其中: Sj=为第一刀上边高为j的情况下的最好结果:
Si = min{ max(ways(w,j,k), ways(w,h-j, m-1-k)), k= 0... m-1 }
"""


# 使用递归，但有dp矩阵
def solve(w, h, knife, memo):
    # 基本情况：如果不能再切割，返回剩余矩形的面积
    if knife == 0:
        return w * h
    
    # 检查当前状态是否已经在记忆中
    if memo[knife][w][h] != -1:
        return memo[knife][w][h]

    # 初始化SV（纵向切割）和SH（横向切割）数组
    SV = [INF]
    SH = [INF]

    # 考虑所有可能的纵向切割
    for left_w in range(1, w):
        for left_knife in range(knife):
            # 递归计算切割后左右两部分的最大值
            SV.append(max(solve(left_w, h, left_knife, memo), solve(w - left_w, h, knife - 1 - left_knife, memo)))

    # 考虑所有可能的横向切割
    for up_h in range(1, h):
        for up_knife in range(knife):
            # 递归计算切割后上下两部分的最大值
            SH.append(max(solve(w, up_h, up_knife, memo), solve(w, h - up_h, knife - 1 - up_knife, memo)))

    # 记忆当前状态的结果，存储SV和SH的最小值
    memo[knife][w][h] = min(min(SV), min(SH))

    # 返回记忆的结果
    return memo[knife][w][h]


# 输入
w, h, m = map(int, input().split())
ans = []
INF = float('inf')

# 处理每个测试案例
while w != 0 and h != 0 and m != 0:
    # 初始化记忆化数组
    memo = [[[-1 for _ in range(h + 1)] for _ in range(w + 1)] for _ in range(m)]
    # 计算并追加当前测试案例的结果
    ans.append(solve(w, h, m - 1, memo))
    # 读取下一个测试案例
    w, h, m = map(int, input().split())

# 输出结果
for i in ans:
    print(i)





"""
# 使用递推：但有几个测试点错误.不过分蛋糕2的思想还是这个。
def solve(w,h,knife):

    # param knife: 刀数

    # (刀数)在最外层： dp[i]:是（刀数）为i的面：就像一个个平行的面(由宽和高构成)堆叠
    # dp[i][j][k]:第一个下标是（刀数），第二个是(宽)，第三个是（高）
    dp = [[[INF for _ in range(h+1)] for _ in range(w+1)] for _ in range(knife+1)]
    # 初始化
    for i in range(1,w+1):
        for j in range(1,h+1):
            # 刀数为0的边界情况是面积
            dp[0][i][j] = i*j
    for i in range(1,knife+1): # 这个i是刀数：从1刀推到m刀
        for j in range(w+1): # 行(宽度)
            for k in range(h+1): # 列（高）
                # SV是竖着切
                SV = [INF]
                Si = [INF]
                if j > 1: # 如果宽度大于1，宽度等于1不能竖着切
                    for left_w in range(1,j): # 第一刀左边宽为i的情况下
                        for left_knife in range(i): # 左边切的刀数
                            Si.append(max(dp[left_knife][left_w][k],dp[i-1-left_knife][j-left_w][k]))
                        SV.append(min(Si))
                        Si = [INF]
                
                # SH是横着切
                SH = [INF]
                Sj = [INF]
                if h > 1:
                    for up_h in range(1,k):
                        for up_knife in range(i):
                            Sj.append(max(dp[up_knife][w][up_h],dp[i-1-up_knife][w][k-up_h]))
                        SH.append(min(Sj))
                        Sj = [INF]
                dp[i][j][k] = min(min(SV),min(SH))
    return dp[knife][w][h]


# 这个m是蛋糕块数
w,h,m = map(int,input().split())
ans = []
INF = float('inf')
while w != 0 and h != 0 and m != 0:
    ans.append(solve(w,h,m-1)) # 传递的是刀数
    w,h,m = map(int,input().split())

for i in ans:
    print(i)


"""



