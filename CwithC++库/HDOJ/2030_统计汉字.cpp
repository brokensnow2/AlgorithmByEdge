#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countChinese(const string &str) {
    int count = 0;
    for (char c : str) {
        if (c < 0) { // 汉字在UTF-8编码中为负数
            count++;
        }
    }
    return count / 3; // UTF-8编码的汉字占3个字节
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        cout << countChinese(str) << endl;
    }
    return 0;
}
