#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 获取输入
void getInput(vector<vector<string>> &strFloat)
{
	string line;
	for (int i = 0; i <= 1; i++)
    {
    	getline(cin, line);  // 读取一整行的输入

    	istringstream iss(line);
    	string str1, str2;

    	getline(iss, str1, '.');  // 读取'.'之前的部分
    	getline(iss, str2);       // 读取'.'之后的部分

		vector<string> floatStr = {str1,str2};
        strFloat.push_back(floatStr);
    }
}

//两浮点数相加
string add(vector<string> &f1, vector<string> &f2)
{
    // 将两个浮点数的整数部分和小数部分对齐
    int maxP_size = max(f1[0].size(), f2[0].size());
    int maxQ_size = max(f1[1].size(), f2[1].size());

    f1[0].insert(0, maxP_size - f1[0].size(), '0');
    f2[0].insert(0, maxP_size - f2[0].size(), '0');

    f1[1].append(maxQ_size - f1[1].size(), '0');
    f2[1].append(maxQ_size - f2[1].size(), '0');

    // 对齐后的两个浮点数
    string num1 = f1[0] + f1[1];
    string num2 = f2[0] + f2[1];

    // 相加
	string sum; // 创建一个空字符串用于存储结果

	int carry = 0; // 初始化进位为0

	for (int i = num1.size() - 1; i >= 0; --i) 
    { // 从两个数字的最后一位（即最低位）开始，向前遍历每一位
    	int tmp = (num1[i] - '0') + (num2[i] - '0') + carry; // 计算当前位的和，包括进位
    	sum.insert(sum.begin(), tmp % 10 + '0'); // 计算当前位的值（和对10的余数），并将其插入到结果字符串的开头
    	carry = tmp / 10; // 更新进位（和除以10的商）
	}

	if (carry > 0) 
    { // 如果最后还有进位
    	sum.insert(sum.begin(), carry + '0'); // 将进位插入到结果字符串的开头
	}

    // 插入小数点
    sum.insert(sum.begin() + maxP_size, '.');

    return sum;
}

int main() 
{
    vector<vector<string>> strFloat;
    getInput(strFloat);
    string result = add(strFloat[0],strFloat[1]);
    cout << "The sum is: " << result << endl;
    return 0;
}
