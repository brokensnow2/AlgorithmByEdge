"""
递推，对的，但超时
"""
def solve(w, h, m):
    dp = [[[INF for _ in range(h + 1)] for _ in range(w + 1)] for _ in range(m + 1)]
    
    for i in range(1, w + 1):
        for j in range(1, h + 1):
            dp[0][i][j] = i * j

    for k in range(1, m + 1):
        for i in range(1, w + 1):
            for j in range(1, h + 1):
                SV = [INF]
                SH = [INF]

                for left_w in range(1, i):
                    for left_knife in range(k):
                        # 不要Si了，全放一起。就这点差距
                        SV.append(max(dp[left_knife][left_w][j], dp[k - 1 - left_knife][i - left_w][j]))

                for up_h in range(1, j):
                    for up_knife in range(k):
                        SH.append(max(dp[up_knife][i][up_h], dp[k - 1 - up_knife][i][j - up_h]))

                dp[k][i][j] = min(min(SV), min(SH))

    return dp[m][w][h]

ans = []
INF = float('inf')

w, h, m = map(int, input().split())

while w != 0 and h != 0 and m != 0:
    ans.append(solve(w, h, m - 1))
    w, h, m = map(int, input().split())

for i in ans:
    print(i)
