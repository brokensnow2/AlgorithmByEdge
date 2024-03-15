#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int c2 = count(str.begin(), str.end(), '2');
    int c1 = count(str.begin(), str.end(), '1');
    int c0 = count(str.begin(), str.end(), '0');
    if(c0 < 1 && c2 < 2 && c1 < 1)
    	cout << -1 << endl;
    else
    {
    	// 队列每个元素是pair：first是字符串(state)，second是层数(移位几次)
    	queue<pair<string, int>> q;
    	q.push(make_pair(str, 0));
        while (!q.empty())
        {
            pair<string, int> element = q.front();
            q.pop();
            if (element.first.find("2012") != string::npos)
            {
                cout << element.second << endl;
                break;
            }
            else
            {
				for (int i = 0; i < str.size() - 1; i++)
                {
                    string temp = element.first;
                    char t = temp[i];
                    temp[i] = temp[i+1];
                    temp[i+1] = t;
                    q.push(make_pair(temp, element.second + 1));  
                }
            }
        }
    }

}
