#include<stdlib.h>
#include<stdio.h>

/*
二叉树
*/
typedef struct btnode { 

      int element; 
      struct btnode* lchild, *rchild;

}BTNode; 

typedef struct binarytree{ 

BTNode* root; 

}BinaryTree;

/*
递归求高度
*/
int depth(BTNode *p)
{
int lh, rh;//left_height,right
     if (!p) return 0;
     lh = depth(p->lchild)+1;
     rh = depth(p->rchild)+1;
     if (lh > rh) return lh; 
     else return rh;
}

/*
求结点个数
*/

int Size(BTNode *p) 
{ 
if (!p) return 0;
else return Size(p->lchild)+Size(p->rchild)+1;
} 

/*
遍历
*/

void print(BTNode *p)
{
      if (p)
      {
      	printf("%d\n",p->element);
      	print(p->lchild);
            print(p->rchild);
      }
}

int main()
{
	BinaryTree *r = (BinaryTree*)malloc(sizeof(BinaryTree));
	BTNode *node1 = (BTNode*)malloc(sizeof(BTNode));
      node1->element = 1;
	r->root = node1;
	BTNode *node2 = (BTNode*)malloc(sizeof(BTNode));
      node2->element = 2;
	node1->lchild = node2;
      BTNode *node3 = (BTNode*)malloc(sizeof(BTNode));
      node3->element = 3;
      node1->rchild = node3;
	printf("depth is %d\n",depth(r->root));
      printf("nodes are %d\n",Size(r->root));
      print(r->root);
}