/**
count函数或者遍历，再通过大小为5的数组来记录
*/
#include <iostream>
#include <string>
#include <algorithm> // count

using namespace std;

int main() {
    int n;
    std::cin >> n;
    std::string vowels = "aeiou";
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        for (char v : vowels) {
            int count = std::count(str.begin(), str.end(), v);
            std::cout << v << ":" << count << std::endl;
        }
        if (i != n - 1) {
            std::cout << std::endl;
        }
    }
    return 0;
}
