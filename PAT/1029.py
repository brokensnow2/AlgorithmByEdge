"""
给定 N 个整数的递增序列 S，中位数是中间位置的数字。例如，S1 = { 11， 12， 13， 14 } 的中位数为 12，
S2 = { 9， 10， 15， 16， 17 } 的中位数为 15。两个序列的中位数定义为包含两个序列的所有元素的非递减序列的中位数。
例如，S1 和 S2 的中位数为 13。
给定两个递增的整数序列，要求您找到它们的中位数。
输入规范：
每个输入文件都包含一个测试用例。每个案例占据 2 行，每个行给出一个序列的信息。对于每个序列，第一个正整数 N （≤2 * 10^5） 
是该序列的大小。然后是 N 个整数，用空格分隔。保证所有整数都在 long int 的范围内。

输出规格：
对于每个测试用例，您应该在一行中输出两个给定序列的中位数。

示例输入：
4 11 12 13 14
5 9 10 15 16 17
示例输出：
13
"""
def find_median_of_two_sorted_sequences():
    # 读取第一个序列
    n1, *s1 = map(int, input().split())
    # 读取第二个序列
    n2, *s2 = map(int, input().split())
    # 计算中位数的位置
    median_pos = (n1 + n2 - 1) // 2
    # 初始化两个指针
    i = j = 0
    while i + j <= median_pos:
        if j >= n2 or (i < n1 and s1[i] < s2[j]):
            value = s1[i]
            i += 1
        else:
            value = s2[j]
            j += 1
    # 输出中位数
    print(value)

# 调用函数
find_median_of_two_sorted_sequences()

"""
def find_median_of_two_sorted_sequences():
    # 读取第一个序列
    n1, *s1 = map(int, input().split())
    # 读取第二个序列
    n2, *s2 = map(int, input().split())
    # 计算中位数的位置
    median_pos = (n1 + n2 - 1) // 2
    # 合并两个序列
    merged = sorted(s1 + s2)
    # 输出中位数
    print(merged[median_pos])

# 调用函数
find_median_of_two_sorted_sequences()
"""
