#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int count = 0;
        for (char c : str) {
            if (isdigit(c)) {
                ++count;
            }
        }
        cout << count << endl;
    }
    return 0;
}
