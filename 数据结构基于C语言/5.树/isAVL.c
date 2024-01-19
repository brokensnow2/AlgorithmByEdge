// 判断是不是一棵AVL树
//1.先判断他是不是一棵二叉排序树BST（即中序遍历有序）
//isSearchTree.c实现了判断是否是二叉搜索树(二叉排序树)
//2.再判断它每棵树的平衡因子

//求高度的变种来判断是否平衡
/**
int isAVL(BSTNode *p, int *balance)
{
    if (!p) return 0;

    int lh = isAVL(p->lchild, balance);
    int rh = isAVL(p->rchild, balance);

    if (abs(lh - rh) >= 2)
        *balance = 0; // 平衡因子大于等于2，将balance设置为0

    return 1+((lh > rh) ? lh: rh);
}

int isAVLTree(BSTNode *p)
{
    int balance = 1; // 初始化balance
    isAVL(p, &balance);
    return balance;
}
*/
