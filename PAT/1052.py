"""
A linked list consists of a series of structures, which are not necessarily adjacent in memory. 
We assume that each structure contains an integer key and a Next pointer to the next structure. 
Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive N (<10^5) and an address of the head node, 
where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. 
NULL is represented by −1.

Then N lines follow, each describes a node in the format:

Address Key Next
where Address is the address of the node in memory, Key is an integer in [−10^5,10^5], 
and Next is the address of the next node. 
It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:
For each test case, the output format is the same as that of the input, 
where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
"""

def sort_linked_list(nodes, head):
    nodes.sort(key=lambda x:x[1])
    length = len(nodes)
    for i in range(length-1):
        nodes[i][2] = nodes[i+1][0]
    nodes[-1][2] = -1
    print(f"{N} {nodes[0][0] :05}")
    for i in range(length-1):
        print(f"{nodes[i][0] :05} {nodes[i][1]} {nodes[i][2] :05}")
    print(f"{nodes[-1][0] :05} {nodes[-1][1]} -1")
    
N,head = map(int,input().split())
nodes = []
for i in range(N):
    nodes.append(list(map(int,input().split())))

sort_linked_list(nodes, head)