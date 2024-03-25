#include <iostream>
#include <string>
using namespace std;

__int128_t factorial(int n) 
{ // 计算阶乘
    __int128_t result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

__int128_t derangement(int n) 
{ // 计算错排数
	if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

__int128_t permutation(int n, int m)
{ // 计算排列数
	return factorial(n) / factorial(n - m);
}

__int128_t combination(int n, int m) 
{ // 计算组合数
    return permutation(n, m) / factorial(m);
}

string int128_to_string(__int128_t num) 
{
    std::string str;
    if(num == 0) {
        return "0";
    }
    if(num < 0) {
        str += "-";
        num = -num;
    }
    while(num > 0) {
        str = char(num % 10 + '0') + str;
        num /= 10;
    }
    return str;
}

int main() 
{
    int n;
    while(cin >> n && n != 0) { // 读取输入
        __int128_t ans = 0;

        	for(int i = n; i >= n-n/2; --i) // 向上取整 
            { // 对于至少一半正确的情况
            	ans += combination(n, i) * (derangement(n-i)); // 计算总的数量
        	}
        	cout << int128_to_string(ans) << endl; // 输出结果
        

    }
    return 0;
}
