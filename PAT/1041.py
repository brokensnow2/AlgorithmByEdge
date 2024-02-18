"""
独特对火星上的人们来说是如此重要，甚至他们的彩票都是以独特的方式设计的。获胜的规则很简单：一个人在从[1,10^4]中选择的数字上下注
第一个在唯一数字上下注的人获胜。例如，如果有7个人在｛5 31 5 88 67 88 17｝上下注，那么第二个下注31的人获胜。
输入规范：
每个输入文件包含一个测试用例。每种情况都包含一行，该行以正整数N（≤10^5)然后进行N次下注。这些数字用空格隔开。
输出规格：
对于每个测试用例，将中奖号码打印成一行。如果没有赢家，请打印“无”。
Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
"""


def find_winner(bets):
    count = {}  # 记录每个下注的计数
    order = {}  # 记录每个下注第一次出现的位置
    for i, bet in enumerate(bets):
        if bet not in count:
            count[bet] = 0
            order[bet] = i
        count[bet] += 1
    # 按照下注第一次出现的位置排序，并找出第一个计数为1的下注
    for bet in sorted(order, key=order.get):
        if count[bet] == 1:
            return bet
    return "None"  # 如果没有赢家，返回"None"

# 测试
bets = list(map(int,input().split()))
print(find_winner(bets[1:]))
