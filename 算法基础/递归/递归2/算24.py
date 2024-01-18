"""
给出4个小于10个正整数，你可以使用加减乘除4种运算以及括
号把这4个数连接起来得到一个表达式。现在的问题是，是否存
在一种方式使得得到的表达式的结果等于24。
这里加减乘除以及括号的运算结果和运算的优先级跟我们平常
的定义一致(这里的除法定义是实数除法)
。
比如，对于5，5，5，1，我们知道5*(5-1/5)=24，因
比可以得到24。又比如，对于1，1，4，2,
我们怎么都不能得到24。

"""

"""
输入:
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整
数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用
处理。
输出:
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”;
否则，输出“NO”

"""

"""
n个数算24， 必有两个数要先算。这两个数算的结果，和剩余n-2个数，就构
成了n-1个数求24的问题4
枚举先算的两个数，以及这两个数的运算方式。

"""
import math
def count24(value :list,n :int):
    if n == 1:
        if math.isclose(value[0],24):
            return True
        else:
            return False
    temp = []
    for i in range(n-1):
        for j in range(i+1,n):
            m = 0
            for k in range(n):
                if k != i and k != j :
                    temp.append(list[k])
                    m += 1
            temp.append(list[i]+list[j])
            if count24(temp,m+1):
                return True
            temp[m] = list[i]-list[j]
            if count24(temp,m+1):
                return True
            temp[m] = list[i]*list[j]
            if count24(temp,m+1):
                return True
            if math.isclose(list[j],0):
                temp[m] = list[i]/list[j]
                if count24(temp,m+1):
                    return True
            if math.isclose(list[i],0):
                temp[m] = list[j]/list[i]
                if count24(temp,m+1):
                    return True
    return False  

num = int(input())
while num > 0:
    str = input().split()
    str = list(map(float, str))
    print(f"{str},{len(str)}")
    ans = count24(str,len(str))
    if ans:
        print("yes")
    else:
        print("no")
    num -= 1
