"""
1074 反向链表
给定一个常数K和一个单向链表L，您应该反转L中的每个K元素。
例如，给定L为 1→2→3→4→5→6，如果K=3，那么必须输出 3→2→1→6→5→4;如果K=4，必须输出 4→3→2→1→5→6。

输入规格：
每个输入文件都包含一个测试用例。对于每种情况，第一行包含第一个节点的地址，
正数N (≤10^5），即节点总数;
正数K (≤N），这是要反转的子列表的长度。节点的地址是一个 5 位非负整数，NULL 用 -1 表示。
然后N行，每个行都以以下格式描述一个节点：
Address Data Next
其中Address是节点的位置，Data是一个整数，Next是下一个节点的位置。

输出规格：
对于每种情况，输出生成的有序链表。每个节点都占用一行，并以与输入相同的格式打印。

示例输入：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
示例输出：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
"""

def reverse_linked_list_by_k(start, K, nodes):
    linked_list = {}
    # 将输入的节点信息存储在字典 linked_list 中，键为地址，值为 (数据, 下一个节点的地址) 的元组
    for addr, data, next_addr in nodes:
        linked_list[addr] = (data, next_addr)

    # 初始化一个列表 seq 来按链表顺序存储节点的地址
    seq = []
    current = start
    # 遍历链表，按顺序将节点的地址添加到 seq 列表中
    while current != '-1':
        seq.append(current)
        current = linked_list[current][1]  # 更新 current 为下一个节点的地址

    # 按照 K 的值对链表节点进行反转处理
    for i in range(0, len(seq), K):
        # 如果当前分组的节点数等于 K，则反转该分组
        if i + K <= len(seq):
            seq[i:i+K] = reversed(seq[i:i+K])

    # 输出反转后的链表
    for i in range(len(seq)):
        if i == len(seq) - 1:
            # 如果是最后一个节点，Next 应为 -1
            print(f"{seq[i]} {linked_list[seq[i]][0]} -1")
        else:
            # 否则，Next 应为下一个节点的地址
            print(f"{seq[i]} {linked_list[seq[i]][0]} {seq[i+1]}")

# 接收输入
# 第一行包含第一个节点的地址、节点总数 N 和每组反转的长度 K
first_line = input().strip().split()
start_address = first_line[0]
N = int(first_line[1])
K = int(first_line[2])

nodes = []
# 读取接下来的 N 行输入，存储为一个三元组 (Address, Data, Next) 的列表
for _ in range(N):
    node_input = input().strip().split()
    nodes.append((node_input[0], int(node_input[1]), node_input[2]))

# 调用函数执行反转链表的操作
reverse_linked_list_by_k(start_address, K, nodes)
