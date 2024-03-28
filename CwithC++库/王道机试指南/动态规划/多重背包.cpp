// 二进制拆分法：任何整数可以由二进制表示
// 1, 2, 4, 8...可以组合成0到物品数量的任意一个数
// eg：假如3件最优，可以变为1+2
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10000;

int dp[MAX];
int v[MAX]; // 物品价值
int w[MAX]; // 物品质量
int k[MAX]; // 物品数目

int value[MAX]; // 分解后的物品价值
int weight[MAX]; // 分解后的物品质量

int main()
{
    int caseNum;
    cin >> caseNum;
    while (caseNum--)
    {
        int n, m; //背包容量， 物品种类
        int num = 0; // 分解后物品的数量
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> w[i] >> v[i] >> k[i];
            for (int j = 1; j <= k[i]; j *= 2) // 开始分解
            {
				value[num] = j * v[i];
                weight[num] = j * w[i];
                ++num;
                k[i] -= j;
            }
            if (k[i] > 0)
        	{
            	value[num] = k[i] * v[i];
            	weight[num] = k[i] * w[i];
        	}
        }
        // 对value开始dp
        // 初始化
        for (int i = 0; i <= m; i++)
        	dp[i] = 0;
        //01背包
		for (int i = 0; i < num; i++) //就相当于num件物品
        // 从后往前
        	for (int j = m; j >= weight[i]; j--)// 容量还是m，即数组是1行m列
            {
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }

        cout << dp[m] << endl;
    }
}