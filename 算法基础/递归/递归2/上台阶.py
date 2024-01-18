"""
例题:爬楼梯
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数,
求不同的走法数
例如:楼梯一共有3级，他可以每次都走一级，或者第一次走一
级，第二次走两级，也可以第一次走两级，第二次走一级，一
共3种方法。
输入
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <=
N <= 30输出不同的走法数。每一行输入对应一行
输出
不同的走法数，每一行输入对应一行输出

样例输入
5
8
10
样例输出
8
34
89

"""
# f(n) = f(n-1) + f(n-2)
def stair(n :int):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    else:
        return stair(n-1) + stair(n-2)
    

n = 2
while n > 1:
    n = int(input())
    print(stair(n))
