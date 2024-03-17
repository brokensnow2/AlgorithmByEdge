#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode 
{
	int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c) : data(c), left(NULL), right(NULL) {}
};

TreeNode *Insert(TreeNode *root, int x, int father)
{
    if (root == NULL)
    {
        root = new TreeNode(x);
        printf("%d\n", father);
    }
    else if (x < root->data)
        root->left = Insert(root->left, x, root->data);
    else
    	root->right = Insert(root->right, x, root->data);
    return root;
}

int main()
{
	int n;
    while (cin >> n)
    {
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            // 逐个插入
            root = Insert(root, x, -1);
        }
        
    }
}