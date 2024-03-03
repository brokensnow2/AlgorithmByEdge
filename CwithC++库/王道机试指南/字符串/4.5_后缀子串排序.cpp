// substr函数
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> substr;
    string str;
    cin >> str;
    int length = str.size();
    for (int i = 0; i < length; i++)
    {
        substr.push_back(str.substr(i,length-1));
    }
    substr.push_back(str);
    sort(substr.begin(),substr.end());
    for (auto i : substr)
    {
        cout << i << endl;
    }
}