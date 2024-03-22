#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string phone;
    while (n--)
    {
		cin >> phone;
        cout << "6" + phone.substr(6) << endl;
    }
}