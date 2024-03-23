/**
 * 问题描述
给你两个数字A和B，如果A等于B，你应该打印“YES”，或者打印“NO”。

输入
每个测试用例包含两个数字A和B。

输出
对于每种情况，如果A等于B，则应打印“YES”或打印“NO”。

样例输入
1 2
2 2
3 3
4 3

样例输出
NO
YES
YES
NO
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string strip(string s) //模仿Python的strip函数
{
    // 去除前导零
    s.erase(0, s.find_first_not_of('0'));
    // 如果字符串中包含'.', 则去除末尾无效的零
    if (s.find('.') != std::string::npos) {
        while (s.back() == '0') s.pop_back(); // 当末尾字符为'0'时，删除该字符
        if (s.back() == '.') s.pop_back();    // 如果末尾字符为'.', 删除该字符
    }
    return s;
}

int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        if (strip(num1) == strip(num2))
			printf("YES\n");
        else
        	printf("NO\n");
    }
}
