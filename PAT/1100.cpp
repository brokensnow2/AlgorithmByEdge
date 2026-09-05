#include <bits/stdc++.h>
using namespace std;

vector<string> low = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun",
    "jly", "aug", "sep", "oct", "nov", "dec"};

vector<string> high = {
    "", "tam", "hel", "maa", "huh", "tou", "kes",
    "hei", "elo", "syy", "lok", "mer", "jou"};

// 反向映射
unordered_map<string, int> mp;

// 地球 → 火星
string earth_to_mars(int num)
{
    int h = num / 13;
    int l = num % 13;

    if (h && l)
        return high[h] + " " + low[l];
    if (h)
        return high[h];
    return low[l];
}

// 火星 → 地球
int mars_to_earth(string s)
{
    stringstream ss(s);
    string a, b;
    ss >> a;

    if (ss >> b)
    {
        // 两个词
        return mp[a] * 13 + mp[b];
    }
    else
    {
        // 一个词
        if (mp.count(a) && mp[a] >= 13)
            return mp[a];
        else
            return mp[a];
    }
}

int main()
{
    // 建立映射
    for (int i = 0; i < 13; i++)
    {
        mp[low[i]] = i;
        if (i > 0)
            mp[high[i]] = i * 13;
    }

    int N;
    cin >> N;
    cin.ignore(); // 处理换行

    while (N--)
    {
        string s;
        getline(cin, s);

        if (isdigit(s[0]))
        {
            // Earth → Mars
            int num = stoi(s);
            cout << earth_to_mars(num) << "\n";
        }
        else
        {
            // Mars → Earth
            cout << mars_to_earth(s) << "\n";
        }
    }
}