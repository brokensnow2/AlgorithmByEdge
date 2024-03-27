#include <iostream>
#include <cstdio>

using namespace std;

const int INF = INT32_MAX;
const int MAX = 1000;

int dp[MAX];
int v[MAX];
int w[MAX];

int main()
{
	int caseNum;
    cin >> caseNum;
    while (caseNum--)
    {
        //空罐质量，总质量
        int e, f;
        cin >> e >> f;
        int m = f - e; // 背包容量
        int n; // 物品种类
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> v[i] >> w[i];
        for (int i = 1; i < m; i++)
        	dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        	for (int j = w[i]; j < m; j++)
            	dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        if (dp[m] == INF)
        	cout << "No" << endl;
        else
        	cout << dp[m] << endl;
    }
    
}