#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree_adt.c"

//QUEST5
//非递归
int getHeight(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    BTNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root; 
    while (front != rear) {
        int size = rear - front;//一层有多少个结点
        while (size--) { //将该层孩子结点入队列(数组)
            BTNode* node = queue[front++];
            //使下次外层while循环正确，即算对下层结点个数，
            //size=rear－front
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

//QUEST6
//先序和中序确定一棵二叉树
BTNode* preInCreat(int a[],int b[], int l1,int h1,int l2,int h2)
{     
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->element = a[l1];
    int i = l2;
    while(b[i] != root->element)
    	i++;
	int llen = i - l2;//左子树长度
    int rlen = h2 - i;//右
	if(llen)
    	root->lchild = preInCreat(a,b,l1+1,l1+llen,l2,l2+llen-1);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = preInCreat(a,b,h1-rlen+1,h1,h2-rlen+1,h2);
    else
        root->rchild = NULL;

    return root;
}

//QUEST9
void swap(BTNode* r)
{
      if(r)
      {
            swap(r->lchild);
            swap(r->rchild);
            BTNode* temp = r->lchild;
            r->lchild = r->rchild;
            r->rchild = temp;
      }
}

//QUEST10
/**
int getKthNode(BTNode* r,int k)
{
    int count = 0;
	SqStack* s = init();
    InitStack(s);
    while(r || !isEmpty(s))
    {
        Push(s,r);
        count++;
        if(count == k)
        {
            BTNode *ans = Pop(s);
            return ans->element;
        }
        r = r->lchild;
        else
      	{
            r = Pop(s);
            r = r->rchild;
      	}      
    }
    return -1;
}
*/

static int wpl = 0;
//QUEST19
int getTreeWPL(BTNode* root,int deep)
{
	if(root == NULL)
    {
        return false;
    }
    if(root->lchild == NULL && root->rchild == NULL)
    {
        wpl += deep * root->element;
    }
    if(root->lchild != NULL )
    {
        getTreeWPL(root->lchild,deep+1);
    }
    if(root->rchild != NULL)
    {
        getTreeWPL(root->rchild,deep+1);
    }
    return wpl;
}

//QUEST20
//数一定是叶子结点
//操作符一定是非叶结点
void tree2Express(BTNode* root,int deep)
{
    if(root == NULL)
    	return;
    if(root->lchild == NULL && root->rchild == NULL)
    	print(root); //数
    else
    {
        if(deep > 1)
        	printf("(");
        tree2Express(root->lchild,deep+1);
        printf("%s",root->element); //操作符
        tree2Express(root->rchild,deep+1);
        printf(")");
    }
}

//附：如何将中缀表达式变成二叉树
void exp2Tree(char* exp)
{

}


int main()
{
    BinaryTree *r = createDemo();
	printf("depth is %d\n",depth(r->root));
    printf("nodes are %d\n",Size(r->root));
    print(r->root);

	printf("depth is %d\n",getHeight(r->root));

    //test preincreate
    int a[6] = {0,1,2,3,4,5};
    int b[6] = {0,4,2,1,5,3};
    BTNode* root2 = preInCreat(a,b,1,5,1,5);
    print(root2);
}