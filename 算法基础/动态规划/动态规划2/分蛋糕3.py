"""
为了进一步优化性能，我们可以考虑使用一些技巧。一个常见的优化方法是减小状态空间的维度。
在这里，我们可以考虑将dp数组从三维降为二维，因为当前状态只与上一刀的状态有关。
"""
def solve(w, h, m):
    dp = [[INF for _ in range(h + 1)] for _ in range(w + 1)]

    for i in range(1, w + 1):
        for j in range(1, h + 1):
            dp[i][j] = i * j

    for k in range(1, m + 1):
        new_dp = [[INF for _ in range(h + 1)] for _ in range(w + 1)]

        for i in range(1, w + 1):
            for j in range(1, h + 1):
                SV = [INF]
                SH = [INF]

                for left_w in range(1, i):
                    SV.append(max(dp[left_w][j], dp[i - left_w][j]))

                for up_h in range(1, j):
                    SH.append(max(dp[i][up_h], dp[i][j - up_h]))

                new_dp[i][j] = min(min(SV), min(SH))

        dp = new_dp

    return dp[w][h]

ans = []
INF = float('inf')

w, h, m = map(int, input().split())

while w != 0 and h != 0 and m != 0:
    ans.append(solve(w, h, m - 1))
    w, h, m = map(int, input().split())

for i in ans:
    print(i)
