"""
约翰要去钓鱼。他有h小时的可用时间（1<=h<=16），该地区有n个湖泊（2<=n<=25），所有湖泊都可以沿着一条单行道到达。
约翰从一号湖开始，但他可以在任何他想去的湖结束。他只能从一个湖到下一个湖，但除非他愿意，否则他不必在任何一个湖停下来。
对于每个i=1，。。。，n-1，从湖泊i到湖泊i+1所需的5分钟间隔的数量表示为ti（0<ti<=192）。
例如，t3＝4意味着从湖泊3行进到湖泊4需要20分钟。为了帮助计划他的钓鱼之旅，约翰收集了一些关于湖泊的信息。对于每个湖泊i，
预计在最初5分钟内捕获的鱼的数量是已知的，表示为fi（fi>=0）。每捕鱼5分钟，预计在接下来的5分钟内捕获的鱼的数量就会以恒定的di（di>=0）减少。
如果在一个间隔内预计捕获的鱼的数量小于或等于di，那么在下一个间隔中，湖中将不再有鱼了。为了简化计划，约翰假设没有其他人会在湖泊捕鱼，
从而影响他预计捕获的鱼的数量。
写一个程序来帮助约翰计划他的钓鱼之旅，以最大限度地增加预期捕获的鱼的数量。在每个湖上花费的分钟数必须是5的倍数。
输入
您将在输入中得到许多案例。每种情况:
都以包含n的一行开始。
后面是包含h的一行。
接下来，有一行n个整数指定fi（1<=i<=n），
然后是一行n整数di（1<=i<=n），
最后是一行n-1个整数ti（1<=i<=n-1）。输入被n＝0的情况终止。
输出
对于每个测试用例，打印在每个湖上花费的分钟数，用逗号分隔，以使计划达到预期捕获的最大鱼数（即使超过80个字符，也应将整个计划打印在一行上）。这后面是一条包含预期鱼类数量的线。
如果存在多个计划，请选择一个尽可能长时间呆在1号湖的计划，即使预计在某些时间段内不会抓到鱼。如果仍然有平局，请选择在2号湖停留尽可能长的一个，以此类推。在两个案例之间插入一条空行。
样例输入
2 
1 
10 1 
2 5 
2 
4 
4 
10 15 20 17 
0 3 4 3 
1 2 3 
4 
4 
10 15 50 30 
0 3 4 3 
1 2 3 
0 
样例输出
45, 5 
Number of fish expected: 31 

240, 0, 0, 0 
Number of fish expected: 480 

115, 10, 50, 35 
Number of fish expected: 724 

难点:
走路时间可多可少,不知道到底该花多长时间纯钓鱼才最好
(可能有好湖在很右边)。.
解决:
枚举最终停下来的湖,将方案分成n类。每类方案的走路时间就是确定的。在每类
方案里找最优解,然后再优中选优。

在确定停下来的湖是X的情况下,假定纯钓鱼时间是k个时间片。
用三元组(F,i,j)(1<=i<=x, 1 <=j<= k)表示湖的第j个时间片能够钓的鱼的数目
是F
将所有的(F,i,j)(共x*k个)按F值从大到小排序,选前k个,就构成了最佳钓鱼方案

"""
# n个湖
n = int(input())
# 小时
hours = int(input())
# 每个湖的初始鱼量
fi = list(map(int,input().split()))
# 每个时间片鱼减少的量
di = list(map(int,input().split()))
# 到下一个湖花的时间片
ti = list(map(int,input().split()))
# 总共的时间片
total_time = int(hours*60/5)
while n != 0:
    # 每个湖的三元组
    lakes = [[] for _ in range(n)]
    for i in range(n):
        j = 1
        lakes[i].append((fi[i],i,i))
        lest_fish = fi[i] - di[i]
        while lest_fish >= 0 and j < total_time:
            lakes[i].append((lest_fish,i,i+j))
            j += 1
            lest_fish = lest_fish - di[i]
    # 开始枚举:到前i个湖钓鱼
    for i in range(n):
        # 钓鱼的时间片
        fish_time = total_time
        if i >= 1: # 从第二个湖开始要花费ti了
            for j in range(i):
                fish_time -= ti[j]
        # 取出前fish_time个片最大的
        k = 0
        temp = []
        while k <= i:
            if len(lakes[k]) <= fish_time:
                temp = temp + lakes[k]
                k += 1
            else:
                temp += lakes[k][0:fish_time]
                k += 1
        temp.sort(reverse=True)
        sum = 0
        if len(temp) > fish_time:
            for i in range(fish_time):
                sum += temp[i][0]
        else:
            for i in temp:
                sum += i[0]
        print(sum)
    n = int(input())
    # 小时
    hours = int(input())
    # 每个湖的初始鱼量
    fi = list(map(int,input().split()))
    # 每个时间片鱼减少的量
    di = list(map(int,input().split()))
    # 到下一个湖花的时间片
    ti = list(map(int,input().split()))
    # 总共的时间片
    total_time = int(hours*60/5)       