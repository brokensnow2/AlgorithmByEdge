"""
假设二叉树中的所有键都是不同的正整数。给定后序和中序遍历序列，您应该输出相应二叉树的级序遍历序列。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行给出一个正整数N（≤30），即二叉树中的节点总数。
第二行给出了后序序列，第三行给出了中序序列。一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，在一行中打印相应二叉树的层次遍历序列。一行中的所有数字必须正好用一个空格分隔，并且行的末尾不能有多余的空格
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
"""
# 定义一个 Node 类，用于表示二叉树中的节点
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# 定义一个函数，根据给定的后序和中序遍历序列构建二叉树
def build_tree(postorder, inorder):
    # 如果中序遍历序列不为空
    if inorder:
        # 在中序遍历序列中找到后序遍历序列的最后一个元素的位置
        ind = inorder.index(postorder.pop())
        # 创建一个新的节点
        root = Node(inorder[ind])
        # 递归构建右子树
        root.right = build_tree(postorder, inorder[ind+1:])
        # 递归构建左子树
        root.left = build_tree(postorder, inorder[:ind])
        # 返回根节点
        return root
    # 如果中序遍历序列为空，返回 None
    return None

# 定义一个函数，返回二叉树的层次遍历序列
def level_order(root):
    # 初始化队列
    queue = [root]
    # 初始化结果列表
    result = []
    # 当队列不为空时
    while queue:
        # 从队列中取出一个节点
        node = queue.pop(0)
        # 将节点的数据添加到结果列表中
        result.append(str(node.data))
        # 如果节点有左子节点，将左子节点添加到队列中
        if node.left:
            queue.append(node.left)
        # 如果节点有右子节点，将右子节点添加到队列中
        if node.right:
            queue.append(node.right)
    # 返回结果列表
    return result

# 读取输入数据
N,B = map(int,input().split())
# 获取后序遍历序列
postorder = list(map(int, input().split()))
# 获取中序遍历序列
inorder = list(map(int, input().split()))
# 构建二叉树
tree = build_tree(postorder, inorder)
# 打印层次遍历序列
print(' '.join(level_order(tree)))

