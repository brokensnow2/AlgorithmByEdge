/**
 * 普通整形无法存储，用字符串来相加
*/
#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}
