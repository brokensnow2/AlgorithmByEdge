#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char c;
    int n;
    while (cin >> c && c != '@')
    {
        cin >> n;
        int length = 2 * n - 1;
        vector<char> line(length, ' ');
        // 先打印一行
        int mid = length / 2;
        line[mid] = c;
        for (int i = 0; i < line.size(); i++)
            cout << line[i];
        cout << endl;
        line[mid] = ' ';
        // 打印除了最后一行的剩下的行
        for (int i = 1; i < n - 1; i++)
        {
            line[mid - i] = c;
            line[mid + i] = c;
            for (int i = 0; i < line.size(); i++)
                cout << line[i];
            cout << endl;
            line[mid - i] = ' ';  // 将字符恢复为空格
            line[mid + i] = ' ';  // 将字符恢复为空格
        }
        // 打印最后一行
        if (n > 1)
        {
            for (int i = 0; i < length; i++)
                line[i] = c;
            for (int i = 0; i < line.size(); i++)
                cout << line[i];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
