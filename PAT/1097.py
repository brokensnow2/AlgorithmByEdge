"""
Given a singly linked list L with integer keys, 
you are supposed to remove the nodes with duplicated absolute values of the keys. 
That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. 
At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, 
you must output 21→-15→-7, and the removed list -15→15.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, 
and a positive N (≤10^5) which is the total number of nodes. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4
 , and Next is the position of the next node.

Output Specification:
For each case, output the resulting linked list first, then the removed list. 
Each node occupies a line, and is printed in the same format as in the input.
Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854

Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
"""
from collections import defaultdict

# 定义节点类
class Node:
    def __init__(self, address, key, next):
        self.address = address
        self.key = key
        self.next = next

# 读取输入
startAddress, N = map(int, input().split())

# 使用字典存储所有节点，方便查找
nodes = defaultdict(list)
for _ in range(N):
    addr, value, next = map(int, input().split())
    nodes[addr] = Node(addr, value, next)

# 初始化结果链表和移除链表
result = [nodes[startAddress]]
removed = []

# 存放访问过的节点abs(value)集合
visited = {abs(nodes[startAddress].key)}

# 当前节点
current = nodes[startAddress].next

# 遍历链表
while current != -1:
    node = nodes[current]
    # 如果节点的绝对值已经出现过，将其添加到移除链表
    if abs(node.key) in visited:
        removed.append(node)
    else:
        # 否则，将其添加到结果链表，并将其绝对值添加到已访问集合
        result.append(node)
        visited.add(abs(node.key))
    current = node.next

# 输出结果链表
for i in range(len(result) - 1):
    print(f"{result[i].address:05} {result[i].key} {result[i+1].address:05}")
print(f"{result[-1].address:05} {result[-1].key} -1")

# 输出移除链表
for i in range(len(removed) - 1):
    print(f"{removed[i].address:05} {removed[i].key} {removed[i+1].address:05}")
print(f"{removed[-1].address:05} {removed[-1].key} -1")
