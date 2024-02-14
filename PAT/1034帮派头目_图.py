"""
警方找到团伙头目的一种方法是查看人们的电话。
如果A和B之间有电话，我们说A和B是有关系的。关系的权重被定义为两个人之间进行的所有电话呼叫的总时间长度。
一个“帮派”是由两个以上的人组成的集群，他们彼此有关联，总关联权重大于给定的阈值K。
在每个帮派中，总权重最大的是头部。现在给你一个电话列表，你应该找到帮派和头目。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含两个正数N和K（均小于或等于1000），分别是通话记录和权重threthold。
接下来是N行，每行的格式如下：
Name1 ame2 Time
其中Name1和Name2是通话两端的人名，Time是通话的长度。人名是从A-Z中选择的三个大写字母的字符串。时间长度是不超过1000分钟的正整数。
输出规格：
对于每个测试用例，首先在一行中打印帮派的总数。然后，对每个帮派，在一行中打印首领的名字和成员的总数。保证每个帮派的首领都是独一无二的。
输出必须按照标题名称的字母顺序进行排序。
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
"""

"""
解法：是图的问题;深度优先遍历改
要找到所有最大连通子图，且子图节点大于2，所有边权重和加起来大于阈值
并且找到权重最大的节点：即连接它的所有边权重和最大
"""

from collections import defaultdict
# 获取输入
N,K = map(int,input().split())
# 创建关系图
relatedMap = defaultdict(list)
# 获取输入和初始化
for _ in range(N):
    # 解包
    name1,name2,time = input().split()
    # 更新
    try:
        # index会throw 
        index = [i[0] for i in relatedMap[name1]].index(name2)
        index2 = [i[0] for i in relatedMap[name2]].index(name1)
        relatedMap[name1][index][1] += int(time)
        relatedMap[name2][index2][1] += int(time)
    # 如果两节点还没有记录
    except ValueError:
        relatedMap[name1].append([name2,int(time)])
        relatedMap[name2].append([name1,int(time)])

# 深度优先遍历
def dfs(node, visited :set, gang :list, total_time):
    visited.add(node)
    gang.append((node,sum([i[1] for i in relatedMap[node]])))
    # 计算总时间
    total_time += sum([i[1] for i in relatedMap[node] if i[0] not in visited])
    for neighbor, time in relatedMap[node]:
        if neighbor not in visited:
            total_time = dfs(neighbor, visited, gang, total_time)
    return total_time

visited = set()
gangs = []
# 遍历所有节点
for node in relatedMap:
    if node not in visited:
        gang = []
        total_time = dfs(node, visited, gang, 0)
        if len(gang) > 2 and total_time > K:
            gangs.append(gang)
# 输出
print(len(gangs))
for i in gangs:
    # 逆序排序
    i.sort(key = lambda x:-x[1])
    print(f"{i[0][0]} {len(i)}")
