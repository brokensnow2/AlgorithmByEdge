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
非递归求二叉树高度
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结构体
struct BTNode {
    int val;
    struct BTNode* lchild;
    struct BTNode* rchild;
};

int getHeight(struct BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    struct BTNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root; 
    while (front != rear) {
        int size = rear - front;//一层有多少个结点
        while (size--) { //将该层孩子结点入栈
            struct BTNode* node = queue[front++];
            //使下次外层while循环正确，即算对下层结点个数，size=rear－front
            if (node->lchild) {
                queue[rear++] = node->lchild;
            }
            if (node->rchild) {
                queue[rear++] = node->rchild;
            }
        }
        height++; //一层遍历完了，高度加一
    }
    return height;
}

*/

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

//先序和中序确定一棵二叉树
BTNode *PreInCreat(int a[],int b[], int l1,int h1,int l2,int h2)
{
      BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->element = a[l1];
      int i = l2;
      while(b[i] != root->element)
      	i++;
	int llen = i - l2;//左子树长度
      int rlen = h2 - i;//右
	if(llen)
      	root->lchild = PreInCreat(a,b,l1+1,l1+llen,l2,l2+llen-1);
      else
            root->lchild = NULL;
      if(rlen)
            root->rchild = PreInCreat(a,b,h1-rlen+1,h1,h2-rlen+1,h2);
      else
            root->rchild = NULL;
      return root;
}

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


      //test preincreate
      int a[6] = {0,1,2,3,4,5};
      int b[6] = {0,4,2,1,5,3};
      BTNode* root2 = PreInCreat(a,b,1,5,1,5);
      print(root2);
}