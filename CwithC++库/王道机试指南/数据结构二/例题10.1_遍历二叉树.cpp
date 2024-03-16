#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct TreeNode 
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c)
    {
        this->data = c;
        left = NULL;
        right = NULL;
    }
};

TreeNode* Build(int &position, string str)
{
	char c = str[position++];
    if (c == '#')
    	return NULL;
    TreeNode *root = new TreeNode(c);
    root->left = Build(position, str);
    root->right = Build(position, str);
    return root;
}

void InOrder(TreeNode *root)
{
	if (root == NULL)
    	return ;
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
    return ;
}

int main()
{
	string str;
    int position = 0;
    while (cin >> str)
    {
        TreeNode *root = Build(position, str);
        InOrder(root);
        cout << endl;
    }
	
}