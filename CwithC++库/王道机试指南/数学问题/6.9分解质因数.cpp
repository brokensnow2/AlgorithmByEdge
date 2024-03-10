#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool is_prime(long long num) {
    if (num < 2) {
        return false;
    }
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find all prime factors of a number
map<long long, int> prime_factors(long long n) {
    map<long long, int> factors;
    long long i = 2;
    while (i * i <= n) {
        if (n % i != 0 || !is_prime(i)) {
            i++;
        } else {
            n /= i;
            factors[i]++;
        }
    }
    if (n > 1 && is_prime(n)) {
        factors[n]++;
    }
    return factors;
}

int main() {
    long long n;
    cin >> n;
    map<long long, int> factor_count = prime_factors(n);
    cout << n << "=";
    for (auto it = factor_count.begin(); it != factor_count.end(); ++it) {
        cout << it->first;
        if (it->second > 1) {
            cout << "^" << it->second;
        }
        if (next(it) != factor_count.end()) {
            cout << "*";
        }
    }
    if (factor_count.empty()) {
        cout << n;
    }
    return 0;
}
