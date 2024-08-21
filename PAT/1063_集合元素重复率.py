"""
给定两组整数，集合的相似度定义为Nc/Nt * 100%
Nc是两个集合共享的不同公共数的数量，并且Nt是两个集合中非重复数的总数。
你的工作是计算任何一对给定集合的相似性。

输入规格：
每个输入文件都包含一个测试用例。每个情况首先给出一个正整数N (≤50），这是集合的总数。
然后N紧随其后的是每行，每行都给出一个带有正数的集合M (≤10^4），然后是M范围 [0,10^9].
在输入集合之后，一个正整数K (≤2000） 给出，后跟K查询行。
每个查询都给出一对集合编号（集合的编号从1到N).一行中的所有数字都用空格分隔。

输出规格：
对于每个查询，在一行中打印集合的相似性，以百分比形式精确到小数点后 1 位。
"""


N = int(input())
sets = [set() for _ in  range(N)]
for i in range(N):
    _, *s = map(int, input().split())
    sets[i] = set(s)

K = int(input())
for i in range(K):
    num1, num2 = map(int, input().split())
    print(f"{len(sets[num1-1] & sets[num2-1]) / len(sets[num1-1] | sets[num2-1]) * 100 :.1f}%")

