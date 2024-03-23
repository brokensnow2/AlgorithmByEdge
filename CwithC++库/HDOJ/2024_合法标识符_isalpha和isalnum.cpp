#include <iostream>
#include <cctype>
#include <string>

using namespace std;
/**
原本想通过ASCII判断：A：65 ，a：97， 0~9：48~57
有isalpha函数
*/
bool is_valid_identifier(const string& s) {
    if (!isalpha(s[0]) && s[0] != '_') {
        return false;
    }
    for (char c : s) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin,s);
        cout << (is_valid_identifier(s) ? "yes" : "no") << endl;
    }
    return 0;
}
