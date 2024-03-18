#include <iostream>
using namespace std;

long long catalan[40];

void init() {
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= 35; ++i) {
        catalan[i] = 0;
        for(int j = 0; j < i; ++j)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
}

int main() {
    init();
    int n;
    while(cin >> n && n != -1) {
        cout << n << " " << 2*n << " " << catalan[n] << endl;
    }
    return 0;
}

