#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        int sum = (A % 100 + B % 100) % 100;
        cout << sum << endl;
    }
    return 0;
}
