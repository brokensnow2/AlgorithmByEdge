#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    unordered_map<string, int> balloon;
    string balloon_color;
    while (cin >> n && n)
    {
        // 开始统计
        for (int i = 0; i < n; i++)
        {
            cin >> balloon_color;
            balloon[balloon_color]++;
        }
        // 找到最多的颜色
        string max_color;
        int max_color_num = 0;
        for (auto i : balloon)
        {
            if (i.second > max_color_num)
            {
                max_color_num = i.second;
                max_color = i.first;
            }
            
        }
        cout << max_color << endl;
        // 清除所有元素
        balloon.clear();
        
    }
    
}