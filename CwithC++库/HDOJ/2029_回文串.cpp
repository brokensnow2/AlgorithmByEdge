#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string &str) {
    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str; // cin不读取空格字符，哪怕是字符串变量
        // std::cout << str;
        std::cout << (isPalindrome(str) ? "yes" : "no") << std::endl;
    }
    return 0;
}


/**
#include <iostream>
#include <string>

bool isPalindrome(const std::string &str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        std::string str;
        std::cin >> str;
        std::cout << (isPalindrome(str) ? "yes" : "no") << std::endl;
    }
    return 0;
}



*/
