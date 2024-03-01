#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        bool flag = false;
        for (int i = m; i <= n; i++) {
            int a = i / 100;
            int b = i / 10 % 10;
            int c = i % 10;
            if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i) {
                if (flag) {
                    cout << " ";
                }
                cout << i;
                flag = true;
            }
        }
        if (!flag) {
            cout << "no";
        }
        cout << endl;
    }
    return 0;
}
