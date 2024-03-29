#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum,count = 0; // 和，计数器
    for (int i = 0; i < str.size(); i++) // 开始遍历
    {
        if (isdigit(str[i]))
        {
            int j = i+1;
            for ( ; j < str.size(); )  // 找到结尾
                if (isdigit(str[j]))
                	++j;
                else
                {
                	break;
                }
			sum += stoi(str.substr(i, j-i));
            count++;
            i = j - 1; // j可能是负号
        }
        else if (str[i] == '-')
        {
            int j = i+1;
            for ( ; j < str.size(); )  // 找到结尾
                if (isdigit(str[j]))
                	++j;
                else
                	break;
            if (j != i + 1)
			{	sum -= stoi(str.substr(i+1, j-i-1));
            	count++;
            	i = j - 1; // j可能是负号
            }
        }
    }
    cout << count << " " << sum << endl;
}