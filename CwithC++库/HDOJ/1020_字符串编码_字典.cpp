/*
Problem Description
Given a string containing only 'A' - 'Z', we could encode it using the following method:

1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.

2. If the length of the sub-string is 1, '1' should be ignored.
 

Input
The first line contains an integer N (1 <= N <= 100) which indicates the number of test cases. The next N lines contain N strings. Each string consists of only 'A' - 'Z' and the length is less than 10000.
 

Output
For each test case, output the encoded string in a line.
 

Sample Input
2
ABC
ABBCCC
 

Sample Output
ABC
A2B3C
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            int count = 1;
            // 计算连续的相同字符数量
            while (i < len - 1 && str[i] == str[i + 1]) {
                count++;
                i++;
            }
            // 如果 count > 1, 输出次数
            if (count > 1) {
                cout << count;
            }
            // 输出当前字符
            cout << str[i];
        }
        cout << endl;
    }
    
    return 0;
}


/* 
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string str;
    map<char, int> count;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for(char i : str)
        {
            count[i]++;
        }
        for (auto i : count)
        {
            if (i.second == 1)
            {
                cout << i.first;
            }
            else
            {
                cout << i.second << i.first;
            }
            
        }
        cout << endl;
        count.clear();
    }
    
    return 0;
} 
*/
