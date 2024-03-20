#include <iostream>
#include <string>

using namespace std;

bool isUnlucky(int num) {
    string str = to_string(num);
    if (str.find('4') != string::npos || str.find("62") != string::npos) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        int count = 0;
        for (int i = n; i <= m; ++i) {
            if (!isUnlucky(i)) {
                ++count;
            }
        }
        cout << count << endl;
    }
    return 0;
}
