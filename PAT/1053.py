"""
给定一个根为R、权重为W的非空树
分配给每个树节点T
从R到L的路径的权重被定义为沿着从R到任何叶节点L的路径所有节点的权重之和。
现在给定任何加权树，你应该找到所有路径的权重等于给定的数字。对于每个节点，上面的数字是节点ID，这是一个两位数的数字，
下面的数字是该节点的权重。假设给定的数量是24，那么存在4条具有相同给定权重的不同路径：{10 5 2 7}、{10 4 10}、{10 3 6 2}和{10 33 6 2}，
它们对应于图中的红色边。
输入规范：
每个输入文件包含一个测试用例。每种情况都以一行开始，该行包含0<N≤100、树中的节点数；M（<N）、非叶节点数和0<S<2^30，
给定的重量数字。下一行包含N个正数，其中Wi（<1000）对应于树节点Ti
接下来是M行，每行的格式如下：
ID K ID[1]ID[2]...ID[K]
其中ID是表示给定非叶节点的两位数，K是其子节点的数量，后面跟着其子节点两位数的ID序列。为了简单起见，让我们将根ID固定为00。

输出规格：
对于每个测试用例，以不递增的顺序打印权重为S的所有路径。
每条路径占据一行，按顺序从根到叶，打印权重。所有的数字都必须用一个空格隔开，行的末尾不能有多余的空格。
Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
"""

"""
解法：深度优先搜索 --关键在于prefix,prefix记住了前缀，有点动态规划的意思?有点类似于数字三角形，全排列。加上减枝
用字典来构建一颗树key是ID，value是孩子ID
用列表来存储节点权重
"""
def findPaths(currentNode :int, target :int, prefix = []):
    if tree[currentNode] == []:
        if target == W[currentNode]:
            result.append(prefix + [W[currentNode]])
            return
        else:
            return
    else:
        newTarget = target - W[currentNode]
        if newTarget > 0:
            for i in tree[currentNode]:
                findPaths(i,newTarget,prefix+[W[currentNode]])
        # 等于0的非叶和大于target减枝掉
        else:
            return

from collections import defaultdict
# 节点个数，非叶节点个数，目标数字
N,M,S = map(int,input().split())
# 节点权重
W = list(map(int,input().split()))
# 树
tree = defaultdict(list)
# 初始化
for _ in range(M):
    ID,num,*kids = map(int,input().split())
    for i in kids:
        tree[ID].append(i)
# 答案序列
result = []
findPaths(0,S)
result.sort(reverse=True)
for i in result:
    print(' '.join(map(str,i)))