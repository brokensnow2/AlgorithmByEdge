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
# 头节点地址，节点个数
startAddress,N = map(int,input().split())
# 所有节点，使用字典存储，方便查找O(1)
nodes = defaultdict(list)
# 存放访问过的节点abs(value)集合
visited = set()
# resulting linked list
result = []
# removed list. 
removed = []
# 初始化
for _ in range(N):
    addr,value,next = map(int,input().split())
    nodes[addr].append(value)
    nodes[addr].append(next)
result.append([startAddress,nodes[startAddress][0]])
visited.add(abs(nodes[startAddress][0]))
nextAddr = nodes[startAddress][1]


while nextAddr != -1:
    absoluteValue = abs(nodes[nextAddr][0])
    if absoluteValue not in visited:
        result[-1].append(nextAddr)
        result.append([nextAddr,nodes[nextAddr][0]])
        visited.add(absoluteValue)
    else:
        if removed != []:
            removed[-1].append(nextAddr)
        removed.append([nextAddr,nodes[nextAddr][0]])
    nextAddr = nodes[nextAddr][1]

# 修正链表next地址
result[-1].append(-1)
removed[-1].append(-1)

# 输出
for i in result:
    print(f"{i[0]:05} {i[1]} {i[2]}")
for i in removed:
    print(f"{i[0]:05} {i[1]} {i[2]}")