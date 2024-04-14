/**
 * 普通整形无法存储，用字符串来相加
*/
#include <iostream>
#include <algorithm>

using namespace std;

string add(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 < len2) {
        swap(num1, num2);
        swap(len1, len2);
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    for (int i = 0; i < len1; i++) {
        carry += num1[i] - '0';
        if (i < len2) {
            carry += num2[i] - '0';
        }
        num1[i] = carry % 10 + '0';
        carry /= 10;
    }
    if (carry) {
        num1.push_back(carry + '0');
    }
    reverse(num1.begin(), num1.end());
    int index = num1.find_first_not_of('0');
    return num1.substr(index);
}

int main() {
    int n;
    string a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        cout << "Case" << " " << i << ":" << endl;
        cout << a << " + " << b << " = " << add(a, b) << endl;
        if (i != n)
        {
            cout << endl;
        }
        
    }
    return 0;
}