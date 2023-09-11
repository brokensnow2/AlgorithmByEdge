//2022
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree_adt.c"
#define MAX_SIZE 20

typedef struct{
    int SqBTNode[MAX_SIZE];
    int ElemNum;
}SQT;

bool judgeIsSearchTree(SQT *node,int k,int val)
{

    if(node->ElemNum < k && node->SqBTNode[k] != -1)
    {
        //left
        if(!judgeIsSearchTree(node,2*k+1,val))
        	return false;

		//root
		if(node->SqBTNode[k] <= val)
        	return false;
        val = node->SqBTNode[k];
        //right
        if (judgeIsSearchTree(node,2*k+2,val))
        	return false;
        
    }
    return true;
}