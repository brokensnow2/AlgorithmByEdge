#include<stdio.h>
#include<stdlib.h>

// 定义二叉树结构体
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    int ltag, rtag;
    struct TreeNode* right;
}BTree;

void InthreadByNLR(BTree *p,BTree *pre)
{
    if(p != NULL)
    {
        if (p->left == NULL)
        {
            p->left = pre;
            p->ltag = 1;
            /* code */
        }
        if(pre->right ==NULL && pre != NULL)
        {
            pre->right = p;
            pre->rtag = 1;

        }
        pre = p;
        InthreadByNLR(p->left,pre);
        InthreadByNLR(p->right,pre);
        
    }
}

//By ChatGPT
// 在先序遍历的过程中进行线索化
/**
 * 函数参数类型： 在函数中修改 pre 指针，传递的是 BTree* pre，
 * 这会导致无法在递归调用中保持正确的前驱节点。
 * 可以将 pre 改为 BTree** pre，以便正确更新前驱节点
 * 
 * 
*/
void ThreadByPreorder(BTree *p, BTree **pre) {
    if (p != NULL) {
        if (p->left == NULL) {
            p->left = *pre;
            p->ltag = 1;
        }

        if (*pre != NULL && (*pre)->right == NULL) {
            (*pre)->right = p;
            (*pre)->rtag = 1;
        }

        *pre = p;

        // 递归处理左子树和右子树
        ThreadByPreorder(p->left, pre);
        ThreadByPreorder(p->right, pre);
    }
}

// 主函数，用于测试
int main() {
    // 创建二叉树并初始化
    BTree node1 = {1, NULL, 0, 0, NULL};
    BTree node2 = {2, NULL, 0, 0, NULL};
    BTree node3 = {3, NULL, 0, 0, NULL};

    node1.left = &node2;
    node1.right = &node3;

    // 指向前驱节点的指针
    BTree* pre = NULL;

    // 线索化二叉树
    ThreadByPreorder(&node1, &pre);

    // 在这里可以遍历线索化后的二叉树
    // ...

    return 0;
}
