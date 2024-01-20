"""

"""
def longest_common_subsequence(X, Y):
    # 初始化dp数组
    dp = [[0 for _ in range(len(Y)+1)] for _ in range(len(X)+1)]
    # 遍历两个字符串中的每个字符
    for i in range(1, len(X)+1):
        for j in range(1, len(Y)+1):
            # 如果两个字符相同，则dp[i][j]等于左上角的值加1
            if X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            # 否则，dp[i][j]等于左边和上边的最大值
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    # 返回dp数组右下角的值，即最长公共子序列的长度
    return dp[-1][-1]

# 测试
X = input()
Y = input()
print(longest_common_subsequence(X, Y))
