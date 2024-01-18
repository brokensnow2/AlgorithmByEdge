"""
例题:放苹果
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问
共有多少种不同的分法? 5，1，1和1，5，1是同一种分法。
输入:
第一行是测试数据的数目t (0 <= t <= 20)。以下每行均包含二个整
数M和N，以空格分开。1<=M， N<=10。
输出:
对输入的每组数据M和N，用一行输出相应的K。

样例输入
1
7 3
样例输出
8

"""

"""
设i个苹果放在k个盘子里放法总数是f(i,k)，则:
k > i时，
f (i,k) = f (i,i)

k <= i时，总放法=有盘子为空的放法+没盘子为空的放法
f(i,k) = f(i,k-1) + f (i-k,k)

"""

def fang(m :int,n :int):
    if m < n:
        return fang(m,m)
    if m == 0:
        return 1
    if n == 0:
        return 0
    return fang(m,n-1) + fang(m-n,n)
    
count = int(input())
while count > 0:
    mn = input().split()
    print(fang(int(mn[0]),int(mn[1])))
    count -= 1