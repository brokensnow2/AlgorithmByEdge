#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/*
二叉树
*/
typedef struct btnode { 
      int element; 
      struct btnode* lchild, *rchild;//BTNode* lchild...
}BTNode; 

typedef struct binarytree{ 
	BTNode* root; 
}BinaryTree;


int depth(BTNode *p)
{
int lh, rh;//left_height,right
     if (!p) return 0;
     lh = depth(p->lchild)+1;
     rh = depth(p->rchild)+1;
     if (lh > rh) return lh; 
     else return rh;
}

//求结点个数
int Size(BTNode *p) 
{ 
if (!p) return 0;
else return Size(p->lchild)+Size(p->rchild)+1;
} 

//遍历
void print(BTNode *p)
{
      if (p)
      {
      	printf("%d\n",p->element);
      	print(p->lchild);
            print(p->rchild);
      }
}

bool isFullBinaryTree(BTNode* root) {
    if (root == NULL) {
        return true;
    }

    // 如果有任何一个节点只有一个子节点，那么这个二叉树不是满二叉树
    if (root->lchild == NULL && root->rchild == NULL) {
        return true;
    } else if (root->lchild != NULL && root->rchild != NULL) {
        return isFullBinaryTree(root->lchild) && isFullBinaryTree(root->rchild);
    } else {
        return false;
    }
}

BinaryTree* createDemo()
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
      BTNode *node4 = (BTNode*)malloc(sizeof(BTNode));
      node4->element = 4;
      node3->rchild = node4;
      return r;
}
