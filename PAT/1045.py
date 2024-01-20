"""
动态规划的方法来解决。我们可以定义一个状态dp[i]，
表示在给定的颜色序列中，以第i个颜色为结尾的最长子序列的长度。
状态转移方程为：如果颜色j在颜色i之前，并且颜色j在伊娃喜欢的颜色顺序中位于颜色i之前，
则dp[i] = max(dp[i], dp[j] + 1)。最后，dp数组中的最大值就是我们要求的结果。
"""

def max_length_of_favorite_stripes(N, favorite_colors, L, colors):
    # 初始化dp数组和颜色顺序数组
    dp = [1] * L
    color_order = [-1] * (N+1)
    # 设置颜色顺序
    for i in range(len(favorite_colors)):
        # 值越小优先级越高：0,1,2...，-1表示不在喜欢的颜色中
        color_order[favorite_colors[i]] = i
        # 将favorite_colors转换为集合
    favorite_colors_set = set(favorite_colors)
    # 动态规划求解
    for i in range(L):
        if colors[i] in favorite_colors_set:
            for j in range(i):
                # 前面的子串优先级应该大于等于i，即值小于i：color_order[colors[j]] <= color_order[colors[i]]
                if color_order[colors[j]] <= color_order[colors[i]] and color_order[colors[j]] != -1 :
                    dp[i] = max(dp[i], dp[j] + 1)
    # 返回最大长度
    return max(dp)

# 测试
N = int(input())
line2 = list(map(int, input().split()))
M = line2[0]
favorite_colors = line2[1:]
line3 = list(map(int, input().split()))
L = line3[0]
colors = line3[1:]
print(max_length_of_favorite_stripes(N, favorite_colors, L, colors))
