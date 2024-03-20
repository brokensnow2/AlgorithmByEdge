#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string name;
    double num, price, sum = 0.0;
    while (cin >> name >> num >> price)
    {
		sum += num * price;
    }
    cout << fixed << setprecision(1) << sum << endl;
}