/**
 * 描述
判断两序列是否为同一二叉搜索树序列
输入描述：
开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。 
接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，
根据这个序列可以构造出一颗二叉搜索树。 
接下去的n行有n个序列，每个序列格式跟第一个序列一样，
请判断这两个序列是否能组成同一颗二叉搜索树。
输出描述：
如果序列相同则输出YES，否则输出NO
示例1
输入：
2
567432
543267
576342
0
复制
输出：
YES
NO

*/

/*
思想：先根据序列构建二叉排序树，比较树的前序和中序序列是否相等。

*/
#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode 
{
	char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c) : data(c), left(NULL), right(NULL) {}
};

TreeNode *Insert(TreeNode *root, char x)
{
    if (root == NULL)
    {
        root = new TreeNode(x);
        //printf("%d\n", father);
    }
    else if (x < root->data)
        root->left = Insert(root->left, x);
    else
    	root->right = Insert(root->right, x);
    return root;
}

void PreOrder(TreeNode *root, string &str)
{
    if (root == NULL)
    	return ;
    str.push_back(root->data);
    PreOrder(root->left, str);
    PreOrder(root->right, str);
}

void InOrder(TreeNode *root, string str)
{
    if (root == NULL)
    	return ;
	InOrder(root->left, str);
    str.push_back(root->data);
    InOrder(root->right, str);
}

int main()
{
    int n;
    string str;
    while (cin >> n && n != 0)
    {
        cin >> str;
        TreeNode *root = NULL;
        for (int i = 0; i < str.size(); i++)
			root = Insert(root, str[i]);
        string pre_str, in_str;
        PreOrder(root, pre_str);
        InOrder(root, in_str);
        for (int i = 0; i < n; i++)
        {
            TreeNode *root2 = NULL;
            cin >> str;
            for (int i = 0; i <str.size(); i++)
				root2 = Insert(root2, str[i]);
            string pre_str2, in_str2;
        	PreOrder(root2, pre_str2);
        	InOrder(root2, in_str2);
            if (pre_str == pre_str2 && in_str == in_str2)
            	cout << "YES" << endl;
            else
            	cout << "NO" << endl;
        }
    }
}