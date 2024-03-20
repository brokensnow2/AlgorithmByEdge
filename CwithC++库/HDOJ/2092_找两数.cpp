/**
 * 可以通过解二次方程来找到这两个整数。给定两个数n和m，它们分别表示这两个整数的和和积，
 * 我们可以设这两个整数为x和y，那么我们就有以下两个方程：
 * x+y=n
 * x*y=m
 * 可以变为：
 * y^2 + n * y + m = 0;
 * 
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        int delta = n * n - 4 * m;
        if (delta < 0) {
            cout << "No" << endl;
            continue;
        }
        int sqrt_delta = sqrt(delta);
        if (sqrt_delta * sqrt_delta == delta && (n - sqrt_delta) % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
