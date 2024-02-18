"""
Given a string, you are supposed to output the length of the longest symmetric sub-string. 
For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.

Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:
For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
"""
"""
思路：可以通过动态规划来解决。
我们可以使用一个二维数组 dp 来记录字符串中任意两个位置之间的子串是否是对称的。然后，我们可以遍历这个数组，找出最长的对称子串。

动态规划递推式：

设 dp[i][j] 表示字符串中从第 i 个字符到第 j 个字符的子串是否是对称的。

当 i == j 时（子串长度为 1），dp[i][j] = 1
当 j == i + 1 时（子串长度为 2），dp[i][j] = (s[i] == s[j])
当 j > i + 1 时（子串长度大于 2），dp[i][j] = (dp[i+1][j-1] and s[i] == s[j])

"""

def longest_symmetric(s):  # 定义函数，输入是字符串s
    n = len(s)  # 获取字符串的长度
    dp = [[0]*n for _ in range(n)]  # 初始化一个二维数组，用于存储任意两个位置之间的子串是否是对称的
    ans = ""  # 初始化最长对称子串
    max_len = 0  # 初始化最长对称子串的长度
    for l in range(n):  # 遍历字符串的每个长度
        for i in range(n):  # 遍历字符串的每个起始位置
            j = i + l  # 计算子串的结束位置
            if j >= n:  # 如果结束位置超过字符串的长度，就跳出循环
                break
            if l == 0:  # 如果子串的长度为1，那么它一定是对称的
                dp[i][j] = 1
            elif l == 1:  # 如果子串的长度为2，那么它是对称的当且仅当它的两个字符相同
                dp[i][j] = (s[i] == s[j])
            else:  # 如果子串的长度大于2，那么它是对称的当且仅当它的首尾字符相同，并且去掉首尾字符后的子串也是对称的
                dp[i][j] = (dp[i+1][j-1] and s[i] == s[j])
            if dp[i][j] and l + 1 > max_len:  # 如果子串是对称的，并且它的长度大于当前找到的最长对称子串的长度
                max_len = l + 1  # 更新最长对称子串的长度
                ans = s[i:i+l+1]  # 更新最长对称子串
    return max_len  # 返回最长对称子串的长度

print(longest_symmetric(input()))  # 从标准输入读取字符串，并打印出最长对称子串的长度

