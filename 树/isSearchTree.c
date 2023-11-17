//QUEST 21 [2022]
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree_adt.c"
#define MAX_SIZE 20

typedef struct{
    int SqBTNode[MAX_SIZE];
    int ElemNum;
}SQT;

static int preValue = -32768;
int judgeBST(BTNode *node)
{
    int b1,b2;
    if(node == NULL)
    {
        return 1;
    }
    else
    {
        //left
        b1 = judgeBST(node->lchild);
        //root
        if(b1 == 0 || preValue > node->element)
        {
            return 0;
        }
        preValue = node->element;
        //right
        b2 = judgeBST (node->rchild);
        return b2;
    }

}

//中序遍历改
/**
 * 
bool judgeIsSearchTree(SQT *node,int k,int val)
{

    if(node->ElemNum < k && node->SqBTNode[k] != -1)
    {
        //left
        if(!judgeIsSearchTree(node,2*k+1,node->SqBTNode[k]))
        	return false;

		//root
		if(node->SqBTNode[k] >= val)
        	return false;
        //right
        if (judgeIsSearchTree(node,2*k+2,node->SqBTNode[k];))
        	return false;
        
    }
    return true;
}

 * 
*/

bool judgeIsSearchRoute(int route[])
{
	int min = -32768;
    int max = 32767;
    if(length(route) <= 2)
    	return true;
    for(int i = 1;i < length(route);i++)
    {
        //向右走,说明route[i-1]小了，应该作为下界
        if(route[i] > route[i-1])
        {
            //判断route[i]是否满足范围
            if(route[i] > min && route[i] <max)
            {
               min = route[i-1]; 
            }
			else
            	return false;
        }
        //向左走，说明route[i-1]大了，应该作为上界
        if(route[i] < route [i-1])
        {
			if(route[i] > min && route[i] < max)
            {
               max = route[i-1]; 
            }
			else
            	return false;
        }
    }
    return true;
}