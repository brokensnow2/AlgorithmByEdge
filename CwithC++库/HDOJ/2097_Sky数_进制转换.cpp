#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int sum_decimal = 0;
        int sum_hex = 0;
        int sum_twelve = 0;
        int temp = n;

        // Calculate the sum of digits in decimal, hex, and twelve bases
        while (temp > 0) {
            sum_decimal += temp % 10;
            temp /= 10;
        }

        temp = n;
        while (temp > 0) {
            sum_hex += temp % 16;
            temp /= 16;
        }

        temp = n;
        while (temp > 0) {
            sum_twelve += temp % 12;
            temp /= 12;
        }

        // Check if all sums are equal
        if (sum_decimal == sum_hex && sum_decimal == sum_twelve) {
            cout << n << " is a Sky Number." << endl;
        } else {
            cout << n << " is not a Sky Number." << endl;
        }
    }
    return 0;
}
