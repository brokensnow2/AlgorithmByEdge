#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        // max_element返回指向第一个最大的元素的迭代器
        char max_char = *max_element(str.begin(), str.end());
        for (int i = 0; i < str.size(); ++i) {
            cout << str[i];
            if (str[i] == max_char) {
                cout << "(max)";
            }
        }
        cout << endl;
    }
    return 0;
}
