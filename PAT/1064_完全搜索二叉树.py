"""
二叉搜索树（BST）被递归地定义为具有以下属性的二叉树：

节点的左子树仅包含键小于该节点键的节点。
节点的右子树仅包含键大于或等于该节点键的节点。
左子树和右子树也必须是二叉搜索树。
完全二叉树 (CBT) 是完全填充的树，但底层可能是个例外，它是从左到右填充的。

现在给定一系列不同的非负整数键，如果要求树也必须是 CBT，则可以构造唯一的 BST。  你应该输出这个二叉搜索树的层序遍历序列。

输入规格：
每个输入文件包含一个测试用例。  对于每种情况，第一行包含一个正整数 N (≤1000)。  然后下一行给出 N 个不同的非负整数键。  一行中的所有数字均以空格分隔，且不大于 2000。

输出规格：
对于每个测试用例，在一行中打印相应的完全二叉搜索树的层序遍历序列。  一行中的所有数字必须用空格分隔，并且行尾不能有多余的空格。

"""

# todo 对输入的整数序列进行排序，因为二叉搜索树的中序遍历会产生一个有序的序列。
# todo 按照中序遍历来构建树，同时考虑到CBT的性质：左孩子的编号是 2*i + 1; 右孩子的编号是 2*i + 2

def buildCBST(sorted_keys, n):
    def build_tree(index):
        # 如果索引超出范围，返回None，表示没有节点
        if index >= n:
            return None
        # 左子树节点数量，使用完全二叉树的性质计算
        left_size = (index * 2 + 1)
        # 递归构建左子树
        left = build_tree(left_size)
        # 当前根节点，弹出排序后的列表中的第一个元素
        root = sorted_keys.pop(0)
        # 递归构建右子树
        right = build_tree(left_size + 1)
        # 返回一个三元组，表示当前节点及其左右子树
        return root, left, right
    
    # 构建树的入口，从索引0开始
    return build_tree(0)

def level_order_traversal(tree):
    result = []  # 保存层序遍历结果
    queue = [tree]  # 用于层序遍历的队列，初始时包含根节点
    while queue:
        node = queue.pop(0)  # 取出队列中的第一个节点
        if node:
            result.append(node[0])  # 将当前节点的值加入结果列表
            queue.append(node[1])  # 将左子树加入队列
            queue.append(node[2])  # 将右子树加入队列
    return result  # 返回层序遍历结果

# 读取输入的节点数量N
N = int(input())
# 读取所有的键值，并转换为整数列表
keys = list(map(int, input().split()))

# 对键值进行排序，以满足二叉搜索树的性质
keys.sort()

# 构建满足完全二叉树（CBT）性质的二叉搜索树（BST）
tree = buildCBST(keys, N)

# 获取树的层序遍历结果
result = level_order_traversal(tree)

# 输出结果，使用空格分隔，并转换为字符串输出
print(" ".join(map(str, result)))
