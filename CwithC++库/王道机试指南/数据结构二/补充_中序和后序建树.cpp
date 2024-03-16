#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode 
{
	char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c) : data(c), left(NULL), right(NULL) {}
};

TreeNode *Build(string in, string post)
{
    if (in.empty())
    	return NULL;
	
    char c = post[post.size() - 1];
    TreeNode *root = new TreeNode(c);
	// 找到分割字符串的下标
	int in_index = in.find(c);
    //
	string left_in, right_in, left_post, right_post;
    if (in_index != -1) // 其实不需要，因为一定能找到
    {
    	left_in = in.substr(0, in_index);
    	right_in = in.substr(in_index + 1);
        left_post = post.substr(0,in_index);
        post.pop_back(); //
        right_post = post.substr(in_index); //
    }

	root->left = Build(left_in, left_post);
    root->right = Build(right_in, right_post);

	return root;
}

void PreOrder(TreeNode *root)
{
    if (root == NULL)
        return ;
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
	string in, post;
	while (cin >> in >> post)
    {
        TreeNode *root = Build(in, post);
        PreOrder(root);
        printf("\n");
    }
}