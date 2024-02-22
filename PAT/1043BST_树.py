"""
二叉搜索树（BST）递归定义为具有以下属性的二叉树：
节点的左子树仅包含键小于节点键的节点。
节点的右子树仅包含键大于或等于节点键的节点。
左子树和右子树也必须是BST。
如果我们交换每个节点的左右子树，则生成的树称为BST的镜像。
现在给定一个整数键序列，您应该判断它是BST的预序遍历序列还是BST的镜像。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行都包含一个正整数N（≤1000）。然后在下一行中给出N个整数键。一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，如果序列是BST或BST的镜像的前序遍历序列，则首先在一行中打印“是”，如果不是，则打印“否”。
然后，如果答案是YES，则在下一行打印该树的后序遍历序列。一行中的所有数字都必须用空格隔开，并且行的末尾不能有多余的空格。

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
"""

class node(object):
    def __init__(self, key) -> None:
        self.key = key
        self.left = None
        self.right = None

# 利用先序遍历和BST的性质建树
# 本来想利用BST中序是递增，BST's Image中序是递减的性质，可是如果树都没建好，没法用
# 用栈来构建BST树

# 后序遍历
def postOrder(root :node):
    if root != None:
        postOrder(root.left)
        postOrder(root.right)
        print(root.key)
# 输入
N = int(input())
preOrder = list(map(int,input().split()))
# 根节点
root = node(preOrder[0])
# 建树加判断
if len(preOrder) > 1:
    # BST's Image or (BST just has right tree) --> but also is BST'Image that just has left tree,
    # the order could build BST'Image just has left tree
    if preOrder[0] < preOrder[1]:
        if(createBstImage(root)):
            print("Yes")
            postOrder(root)
        else:
            print("No")
    # BST or BST's Image just has left tree --> also is BST that just has right tree
    else:
        if(createBST(root)):
            print("Yes")
            postOrder(root)
        else:
            print("No")
else:
    print("Yes")
    print(preOrder[0])
if (createBST(preOrder[1:], root)):
    postOrder(root)
else:
    print("No")