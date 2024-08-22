#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // 先除后乘，防止溢出
}

int main() {
    int number_problem;
    cin >> number_problem;
    for (int i = 0; i < number_problem; i++) {
        int number_integer;
        cin >> number_integer;
        
        int result;
        cin >> result;
        
        for (int j = 1; j < number_integer; j++) {
            int num;
            cin >> num;
            result = lcm(result, num);
        }
        
        cout << result << endl;
    }
    return 0;
}
