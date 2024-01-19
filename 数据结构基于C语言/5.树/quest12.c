#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 递归查找值为x的节点，并打印其所有祖先
bool printAncestors(struct TreeNode* root, int x) {
    if (root == NULL) {
        return false;
    }

    // 如果找到了目标节点x，直接返回true
    if (root->val == x) {
        return true;
    }

    // 否则继续在左子树和右子树中查找目标节点x
    bool found_in_left = printAncestors(root->left, x);
    bool found_in_right = printAncestors(root->right, x);

    // 如果在左子树或右子树中找到了目标节点x，说明当前节点是其祖先，打印当前节点值
    if (found_in_left || found_in_right) {
        printf("%d ", root->val);
        return true;
    }

    // 如果左子树和右子树都没有找到目标节点x，则返回false
    return false;
}

// 创建新的二叉树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 主函数，用于测试
int main() {
    // 构造以下二叉树：
    //       5
    //      / \
    //     3   8
    //    / \ / \
    //   1  4 6  9
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    int x = 4;
    printf("Ancestors of node %d: ", x);
    printAncestors(root, x);
    printf("\n");

    return 0;
}
