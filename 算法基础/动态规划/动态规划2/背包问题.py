"""
有N件物品和一个容积为M的背包。第i件物品的体积w[i],价值是d[i]。
求解将哪些物品装入背包可使价值总和最大。每种物品只有一件，可以选择放或者不放
(N<=3500, M <= 13000)

用F[i][j] 表示取前i种物品，使它们总体积不超过j的
最优取法取得的价值总和。要求F[N][M]
边界:   if (w[1] <= j)
            F[1][j] = d[1];
        eIse
            F[1][j] = 0;


递推:
F[i][j] = max(F[i-1][j],F[i-1][j-w[i]]+d[i])
取或不取第i种物品，两者选优
(j-w[i] >= 0才有第二项)


# dp:
        体积为0  体积为1  体积2  体积3 。。。
前1件 value=0
前2件
前3件
。。。

"""
N, M = map(int,input().split())
# 体积
w = [0] + list(map(int,input().split()))
# 价值
d = [0] + list(map(int,input().split()))
# 初始化滚动数组(第一行/边界)
dp = []
for i in range(M+1):
    if w[1] <= i:
        dp.append(d[1])
    else:
        dp.append(0)

# 开始人人为我型递推
# 从第二行开始：2~N行
for i in range(2,N+1):
    
    # 注意：体积从M到1！！！
    for j in range(M,-1,-1):
        if j - w[i] >= 0: # 如果体积够
            # dp = 上一行正上方F[i-1][j]，还有上一行左侧F[i-1][j-w[i]]+d[i]
            # i省略，因为是滚动数组
            dp[j] = max(dp[j],dp[j-w[i]]+d[i])
        
        else: # 不够就等于正上方值
            pass

print(dp[M])
