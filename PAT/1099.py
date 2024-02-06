"""
1099 Build A Binary Search Tree

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, 
there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. 
You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100) 
which is the total number of nodes in the tree. 
The next N lines each contains the left and the right children of a node in the format left_index right_index, 
provided that the nodes are numbered from 0 to N−1, and 0 is always the root. 
If one child is missing, then −1 will represent the NULL child pointer. 
Finally N distinct integer keys are given in the last line.

Output Specification:
For each test case, print in one line the level order traversal sequence of that tree. 
All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
"""

"""
解题思路：中序遍历：将从小到大的值依次填入节点中
树不使用类和指针；用字典tree；key为编号，value是[左孩子，右孩子]；从tree[0]开始利用中序遍历，
value变为[左孩子，右孩子,数值]
最后tree[0]开始层次遍历
"""
def inorder(node):
    if node == -1:
        return
    inorder(tree[node][0])
    tree[node].append(keys.pop(0))
    inorder(tree[node][1])

def levelorder(root):
    queue = [root]
    res = []
    while queue:
        node = queue.pop(0)
        res.append(str(tree[node][2]))
        if tree[node][0] != -1:
            queue.append(tree[node][0])
        if tree[node][1] != -1:
            queue.append(tree[node][1])
    return ' '.join(res)

N = int(input())
tree = {}
keys = []

for i in range(N):
    left, right = map(int, input().split())
    tree[i] = [left, right]

keys = list(map(int, input().split()))
keys.sort()

inorder(0)
print(levelorder(0))