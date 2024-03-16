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

// 还有一种更精巧的方法，见python数据结构的树.py
// 直接 pre.erase(0, 1)
TreeNode *Build(string pre, string in)
{
    if (pre.empty())
    	return NULL;
	
    TreeNode *root = new TreeNode(pre[0]);
	// 找到分割字符串的下标
	int in_index = in.find(pre[0]);
	// int pre_index = pre.find(in[in_index - 1]); 可以省略
    //
	string left_in, right_in, left_pre, right_pre;
    if (in_index != -1) // 其实不需要，因为一定能找到
    {
    	left_in = in.substr(0, in_index);
    	right_in = in.substr(in_index + 1);
    	left_pre = pre.substr(1,in_index);
    	right_pre = pre.substr(in_index + 1);
    }

	root->left = Build(left_pre, left_in);
    root->right = Build(right_pre, right_in);

	return root;
}

void PostOrder(TreeNode *root)
{
    if (root == NULL)
        return ;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

int main()
{
	string pre, in;
	while (cin >> pre >> in)
    {
        TreeNode *root = Build(pre, in);
        PostOrder(root);
        cout << endl;
    }
}