"""
洗牌是一种用于随机化一副扑克牌的程序。由于标准的洗牌技术被认为是薄弱的，而且为了避免员工通过不充分的洗牌与赌徒合作的“内部工作”，
许多赌场都使用自动洗牌机。你的任务是模拟一台洗牌机。
该机器根据给定的随机顺序洗牌54张牌，并重复给定的次数。假设卡片组的初始状态按以下顺序排列：
S1，S2。。。，S13，
H1，H2。。。，H13，
C1，C2。。。，C13，
D1，D2。。。，D13，
J1、J2
其中“S”代表“Spade”，“H”代表“Heart”，“C”代表“Club”，“D”代表“Diamond”，“J”代表“Joker”。给定的数字序列是[1,54]中不同整数的置换。
如果第i个位置的数字是j，则意味着将牌从位置i移动到位置j。例如，假设我们只有5张牌：S3、H5、C1、D13和J2。
给定混洗顺序{4，2，5，3，1}，结果将是：J2，H5，D13，S3，C1。
如果我们再次重复洗牌，结果将是：C1、H5、S3、J2、D13。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含一个正整数K（≤20），它是重复次数。然后下一行包含给定的顺序。
一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，将混洗结果打印在一行中。所有的卡片都用一个空格隔开，并且在行的末尾不能有多余的空格。
Sample Input:
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
Sample Output:
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
"""
# 交换两张牌
def swapCards(index :int, num :int):
    cards[index], cards[num] = cards[num], cards[index]
    
# 列表推导式生成牌
cards = [f"{j}{i}" for j in ['S', 'H', 'C', 'D'] for i in range(1, 14)]
cards.append('J1')
cards.append('J2')

# 获取输入
N = int(input())
orders = list(map(int,input().split()))

for _ in range(N):
    for index, num in enumerate(orders):
        swapCards(index, num-1)
print(' '.join(cards))