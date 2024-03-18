#include <iostream>

using namespace std;

long long factorial(int n) 
{ // 计算阶乘
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long derangement(int n) 
{ // 计算错排数
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

long long permutation(int n, int m)
{ // 计算排列数
	return factorial(n) / factorial(n - m);
}

long long combination(int n, int m) 
{ // 计算组合数
    return factorial(n) / (factorial(m) * factorial(n - m));
}

int main() 
{
    int n;
    while(cin >> n && n != 0) { // 读取输入
        long long ans = 0;
        if (n <= 3)
        {
            cout << 1 << endl;
        }
        else
        {
        	for(int i = (n+1)/2; i <= n-2; ++i) 
            { // 对于至少一半正确的情况
            	ans += combination(n, i) * (permutation(n-i, 1)); // 计算总的数量
        	}
        	cout << ans+1 << endl; // 输出结果
        }

    }
    return 0;
}
