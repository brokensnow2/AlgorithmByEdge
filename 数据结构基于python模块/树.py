# 定义一个 Node 类，用于表示二叉树中的节点
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# 定义一个函数，根据给定的前序和中序遍历序列构建二叉树
def build_tree(preorder, inorder):
    # 如果中序遍历序列不为空
    if inorder:
        # 在中序遍历序列中找到前序遍历序列的第一个元素的位置
        ind = inorder.index(preorder.pop(0))
        # 创建一个新的节点
        root = Node(inorder[ind])
        # 递归构建左子树
        root.left = build_tree(preorder, inorder[:ind])
        # 递归构建右子树
        root.right = build_tree(preorder, inorder[ind+1:])
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
N = int(input())
# 获取前序遍历序列
preorder = list(map(int, input().split()))
# 获取中序遍历序列
inorder = list(map(int, input().split()))
# 构建二叉树
tree = build_tree(preorder, inorder)
# 打印层次遍历序列
print(' '.join(level_order(tree)))
