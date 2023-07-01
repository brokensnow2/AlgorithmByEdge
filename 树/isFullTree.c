#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

// 定义二叉树结构体
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isFullBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    // 如果有任何一个节点只有一个子节点，那么这个二叉树不是满二叉树
    if (root->left == NULL && root->right == NULL) {
        return true;
    } else if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    } else {
        return false;
    }
}

int main()
{
    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree->val = 5;
}
