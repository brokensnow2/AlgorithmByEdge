#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// 定义一个函数，将字符串表示的大数除以2，并返回结果
string Divide (string str, int x)
{
    int remainder = 0; // 初始化余数
    for (int i = 0; i < str.size(); i++) // 遍历字符串中的每一位
    {
        int current = remainder * 10 + (str[i] - '0'); // 计算当前的数
        str[i] = current / x + '0'; // 更新字符串中的当前位
        remainder = current % x; // 更新余数
    }
    int pos = 0; // 初始化位置
    while (str[pos] == '0') // 找到第一个非零的位置
    	pos++;
    return str.substr((pos)); // 返回从第一个非零位置开始的子字符串
}

int main(){
    string str; // 定义一个字符串变量存储输入的十进制数
    while (cin >> str){ // 读取输入
        vector<int> bin; // 定义一个向量存储二进制数
        while (str.size() != 0){ // 当字符串的长度不为0时，继续循环
            int last = str[str.size()-1] - '0'; // 计算字符串的最后一位
            bin.push_back(last % 2); // 将最后一位除以2的余数添加到向量中
            str = Divide(str, 2); // 更新字符串，将其除以2
        }
        for (int i = bin.size()-1; i >= 0; --i){ // 从后向前遍历向量
            cout << bin[i]; // 输出向量中的每一位
        }
        cout << endl; // 输出换行符
    }
    return 0;
}
