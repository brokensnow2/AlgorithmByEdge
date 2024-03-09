// 约数（因数）：若 a | b (b/a = 整数),  则称 b 是 a 的倍数，a 是 b 的约数。
#include <iostream>

using namespace std;

int sum_of_divisors(int n) {
    // 计算n的真约数之和
    int divisors_sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            divisors_sum += i;
        }
    }
    return divisors_sum;
}

bool are_amicable_numbers(int a, int b) {
    return sum_of_divisors(a) == b && sum_of_divisors(b) == a;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int A, B;
        cin >> A >> B;
        if (are_amicable_numbers(A, B)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
