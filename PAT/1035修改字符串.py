"""
为了准备PAT测试，有时必须为用户生成随机密码。问题是，总是有一些令人困惑的密码，
因为很难区分1（一）和l（小写L），或者0（零）和O（大写o）。
一种解决方案是将1（一）替换为@，将0（零）替换为%，将l替换为L，将O替换为o。
现在，您的工作是编写一个程序来检查生成的帐户，并帮助修改令人困惑的密码。
输入规范：
每个输入文件包含一个测试用例。每种情况都包含一个正整数N（≤1000），后面跟着N行帐户。
每个帐户由一个用户名和一个密码组成，两者都是不超过10个字符的字符串，没有空格。
输出规格：
对于每个测试用例，首先打印已修改的帐户数M，然后在下面的M行中打印修改的帐户信息，即用户名和相应的修改密码。
必须按读入时的顺序打印帐户。如果未修改任何帐户，则打印一行：There are N accounts and no account is modified，其中N是帐户总数。
但是，如果N为1，则必须打印There is 1 account and no account is modified
Sample Input 1:
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified
"""

# 设置一个整体修改标志
flag = 0
# 读取输入
N = int(input())
# 初始化
# accounts存的是一个个列表：账户和密码以及修改标志（0表示未修改，1表示修改了）
accounts = []
for _ in range(N):
    name,password = input().split()
    accounts.append([name,password,0])
# 判断和替换
for account in accounts:
    if '1' in account[1] or '0' in account[1] or 'l' in account[1] or 'O' in account[1]:
        flag += 1
        account[2] = 1
        # 创建一个转换表
        trans_table = str.maketrans('01lO', '%@Lo')
        # 转换
        newString = account[1].translate(trans_table)
        account[1] = newString

# 没有人被修改
if flag == 0:
    if N == 1:
        print(f"There is 1 account and no account is modified")
    else:
        print(f"There are {N} accounts and no account is modified")
else:
    print(flag)
    for i in accounts:
        # 该用户被修改了
        if i[2] == 1:
            print(f"{i[0]} {i[1]}")
