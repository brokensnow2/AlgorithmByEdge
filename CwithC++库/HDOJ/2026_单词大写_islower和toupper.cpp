#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        bool newWord = true;
        for (auto &c : str) {
            if (newWord && islower(c)) {
                c = toupper(c);
                newWord = false;
            } else if (c == ' ') {
                newWord = true;
            }
        }
        cout << str << endl;
    }
    return 0;
}
