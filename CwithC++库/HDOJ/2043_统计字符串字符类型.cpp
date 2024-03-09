#include <iostream>
#include <cctype> // For isupper, islower, isdigit

bool is_secure_password(const std::string& password) {
    // Check password length
    if (password.length() < 8 || password.length() > 16) {
        return false;
    }

    // Initialize flags for different character types
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    // Check each character in the password
    for (char c : password) {
        if (std::isupper(c)) {
            has_upper = true;
        } else if (std::islower(c)) {
            has_lower = true;
        } else if (std::isdigit(c)) {
            has_digit = true;
        } else if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^') {
            has_special = true;
        }
    }

    // Check if at least three character types are present
    int char_types = has_upper + has_lower + has_digit + has_special;
    return char_types >= 3;
}

int main() {
    int M;
    std::cin >> M;
    while (M--) {
        std::string password;
        std::cin >> password;
        if (is_secure_password(password)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
