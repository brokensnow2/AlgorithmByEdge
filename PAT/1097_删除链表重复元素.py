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

# 定义节点类
class Node:
    def __init__(self, address, key, next):
        self.address = address
        self.key = key
        self.next = next

# 读取输入
startAddress, N = input().split()
N = int(N)

# 使用字典存储所有节点，键为字符串类型的地址
nodes = {}
for _ in range(N):
    addr, value, next_addr = input().split()
    nodes[addr] = Node(addr, int(value), next_addr)

# 初始化结果链表的头和尾，以及移除链表的头和尾
result_head = result_tail = None
removed_head = removed_tail = None

# 存放访问过的节点绝对值的集合
visited = set()

# 遍历链表
current = startAddress
while current != '-1':
    node = nodes[current]
    if abs(node.key) in visited:
        # 如果是移除的节点，添加到移除链表中
        if removed_head is None:
            removed_head = removed_tail = node
        else:
            removed_tail.next = node.address
            removed_tail = node
    else:
        # 如果是结果链表节点，添加到结果链表中
        visited.add(abs(node.key))
        if result_head is None:
            result_head = result_tail = node
        else:
            result_tail.next = node.address
            result_tail = node
    current = node.next

# 最后一个节点的 next 应该指向 -1
if result_tail is not None:
    result_tail.next = '-1'
if removed_tail is not None:
    removed_tail.next = '-1'

# 输出结果链表
current = result_head
while current is not None:
    print(f"{current.address} {current.key} {current.next}")
    current = nodes[current.next] if current.next != '-1' else None

# 输出移除链表
current = removed_head
while current is not None:
    print(f"{current.address} {current.key} {current.next}")
    current = nodes[current.next] if current.next != '-1' else None

