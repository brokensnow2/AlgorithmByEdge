#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && (a || b)) {
        int flag = 0;
        for (int i = 0; i <= 99; i++) {
            if ((a * 100 + i) % b == 0) {
                if (flag) cout << " ";
                flag = 1;
                if (i < 10) cout << "0" << i;
                else cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
