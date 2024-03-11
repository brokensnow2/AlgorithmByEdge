#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;
    vector<long long> S(10001);
    S[1] = 2;
    for (int i = 2; i <= 10000; ++i) {
        S[i] = S[i-1] + i + 1;
    }
    while (C--) {
        int n;
        cin >> n;
        cout << S[n] << endl;
    }
    return 0;
}
