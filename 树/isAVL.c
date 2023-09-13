// 判断是不是一棵AVL树
//1.先判断他是不是一棵二叉排序树（即中序遍历有序）
//2.再判断它每棵树的平衡因子

//求高度的变种来判断是否平衡
/**
int isAVL(BSTNode *p, int *balance)
{
    if (!p) return 0;

    int lh = isAVL(p->lchild, balance) + 1;
    int rh = isAVL(p->rchild, balance) + 1;

    if (abs(lh - rh) >= 2)
        *balance = 0; // 平衡因子大于等于2，将balance设置为0

    return (lh > rh) ? lh : rh;
}

int isAVLTree(BSTNode *p)
{
    int balance = 1; // 初始化balance
    isAVL(p, &balance);
    return balance;
}
*/
