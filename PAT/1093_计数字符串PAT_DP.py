"""
字符串APPAPT包含两个PAT作为子字符串。第一个由第2个、第4个和第6个字符组成，第二个由第3个、第四个和第六个字符组成。
现在给定任何字符串，您应该告诉字符串中包含的PAT的数量。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，只有一行给出不超过10^5的字符串
仅包含P、A或T的字符。
输出规格：
对于每个测试用例，在一行中打印字符串中包含的PAT的数量。由于结果可能是一个巨大的数字，您只需要输出模以1000000007的结果。
Sample Input:
APPAPT
Sample Output:
2

"""
# 这个代码使用了动态规划的思想，通过遍历字符串中的每个字符，记录以当前字符结尾的合法组合数量
MOD = 1000000007

def count_PAT(s):
    count_P = 0
    count_PA = 0
    result = 0

    for char in s:
        if char == 'P':
            count_P += 1
        elif char == 'A':
            count_PA = (count_PA + count_P)
        elif char == 'T':
            result = (result + count_PA) % MOD

    return result

# 读取输入
s = input().strip()

# 计算并输出结果
result = count_PAT(s)
print(result)
