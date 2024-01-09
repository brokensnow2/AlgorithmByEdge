//南航2014
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree_adt.c"

/**
 * 对一颗家谱树输出它有多少代人，并输出最后一代的人数和名字。
 * 最后一代肯定是叶结点，没有左子树。
 * 
*/

static int total = 0;
static BTNode *smallest_node = NULL;

void total_generation(BTNode *node,int generation)
{
	if(node == NULL)
    {
        return ;
    }
    else if (node->lchild == NULL)
    {
        if(total < generation)
        {
            total = generation;
            smallest_node = node;
        }
    }
    else
    {
        total_generation(node->lchild,generation + 1);
        total_generation(node->rchild,generation);
    }
}

void func(BTNode* node)
{
    int generation = 1;
    total_generation(node,generation);
    printf("%d\n",total);
    BTNode *node1 = smallest_node;
    while (node1 != NULL)
    {
        printf("%d\n",node1->element);
        node1 = node1->rchild;
    }
}