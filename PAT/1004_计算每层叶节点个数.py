"""
家庭等级通常由系谱树表示。你的工作是计算那些没有孩子的家庭成员。

输入规格：
每个输入文件包含一个测试用例。
每个case都以一行开头，其中包含0<N<100（树中的节点数）和M（<N）（非叶节点数）。
然后是M行，每行格式为：
ID K ID[1]ID[2]… ID[K]
其中ID是表示给定非叶节点的两位数ID，K是其子节点的数量，后跟其子节点的两位数ID序列。
为简单起见，让我们将根ID固定为01。
输入以N为0结束。这种情况不能处理。

输出规格：
对于每个测试用例，您应该从根开始计算每一代（树的每一层）级别的那些没有孩子的家庭成员。
数字必须打印在一行中，用空格分隔，每行末尾不得有额外的空格。

示例案例表示只有2个节点的树，其中01是根，02是它的唯一子节点。
因此，在根01的层上，有0个叶节点；在下一层，有1个叶节点。然后我们应该在一行中输出0 1。

示例输入：
2 1
01 1 02
样品输出：
0 1
"""
from collections import deque, defaultdict

while True:
    # 读取 N 和 M
    line = input().strip()
    if line == "0":
        break
    N, M = map(int, line.split())

    # 构建树结构，使用字典存储每个节点及其子节点
    tree = defaultdict(list)
    for _ in range(M):
        data = input().strip().split()
        parent = data[0]
        children = data[2:]  # 获取子节点列表
        tree[parent] = children

    # BFS 初始化
    queue = deque(["01"])  # 从根节点 '01' 开始
    leaf_counts = []

    # 开始 BFS（层次遍历）
    while queue:
        level_size = len(queue)
        leaf_count = 0
        for _ in range(level_size):
            node = queue.popleft()
            if node in tree:  # 当前节点有子节点
                queue.extend(tree[node])  # 将子节点加入队列
            else:  # 当前节点没有子节点，是叶节点
                leaf_count += 1
        leaf_counts.append(leaf_count)

    # 输出结果
    print(" ".join(map(str, leaf_counts)))
    break