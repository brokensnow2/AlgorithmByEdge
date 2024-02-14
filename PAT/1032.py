"""
要存储英语单词，一种方法是使用链表并逐字母存储单词。为了节省一些空间，如果单词共享相同的后缀，我们可以让它们共享相同的子列表。
您应该找到公共后缀的起始位置.
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含两个节点地址和一个正整数N（≤10^5)，其中，这两个地址是这两个单词共的第一个节点的地址，
N是节点的总数。节点的地址是一个5位数的正整数，NULL由−1表示。
接下来是N行，每行以以下格式描述一个节点：
Address Data Next
其中Address是节点的位置，Data是该节点包含的字母，它是从{a-z，a-z}中选择的英文字母，Next是下一个节点的位置。
输出规格：
对于每种情况，只需输出通用后缀的5位数起始位置。如果这两个单词没有通用后缀，请改为输出-1。
样本输入：
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
样本输出：
67890
"""

"""
可以从两个单词的末尾开始，使用两个指针分别向前移动。
如果两个指针指向的节点地址不同，那么我们就找到了公共后缀的起始位置。这个方法的时间复杂度为O(N)，其中N是节点的总数。
"""
def find_common_suffix(start1, start2, nodes):
    # 创建两个链表的列表
    list1, list2 = [], []
    while start1 != -1:
        list1.append(start1)
        start1 = nodes[start1][1]
    while start2 != -1:
        list2.append(start2)
        start2 = nodes[start2][1]
    # 如果两个链表都为空，返回-1
    if not list1 or not list2:
        return -1
    # 从后向前遍历两个链表，找到第一个不同的节点
    res = -1
    while list1 and list2 and list1[-1] == list2[-1]:
        res = list1[-1]
        list1.pop()
        list2.pop()
    return res

# 读取输入
start1, start2, n = map(int, input().split())
nodes = {}
for _ in range(n):
    address, data, next_node = input().split()
    nodes[int(address)] = (data, int(next_node))

# 找到公共后缀的起始位置并输出
result = find_common_suffix(start1, start2, nodes)
if result != -1:
    print(f"{result :05}")
else:
    print(-1)


"""
或者：
可以首先计算两个链表的长度，然后让较长的链表的指针先移动，使得两个指针在同一起点开始移动。
这样，当两个指针相遇时，就是公共后缀的起始位置。

def find_common_suffix(start1, start2, nodes):
    # 计算两个链表的长度
    len1, len2 = 0, 0
    temp1, temp2 = start1, start2
    while temp1 != -1:
        len1 += 1
        temp1 = nodes[temp1][1]
    while temp2 != -1:
        len2 += 1
        temp2 = nodes[temp2][1]
    # 让较长的链表的指针先移动
    if len1 > len2:
        for _ in range(len1 - len2):
            start1 = nodes[start1][1]
    else:
        for _ in range(len2 - len1):
            start2 = nodes[start2][1]
    # 同时移动两个指针，直到它们相遇
    while start1 != start2:
        start1 = nodes[start1][1]
        start2 = nodes[start2][1]
    return start1 if start1 != -1 else -1

# 读取输入
start1, start2, n = map(int, input().split())
nodes = {}
for _ in range(n):
    address, data, next_node = input().split()
    nodes[int(address)] = (data, int(next_node))

# 找到公共后缀的起始位置并输出
result = find_common_suffix(start1, start2, nodes)
if result != -1:
    print(f"{result :05}")
else:
    print(-1)
"""