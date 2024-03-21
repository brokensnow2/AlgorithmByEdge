#include <iostream>

using namespace std;

int main()
{
    int n;
    long long old_h, old_l;
    while (cin >> n && n != -1)
    {
        long long high = 1, low = 0;
		while (n--)
        {
            old_h = high;
            old_l = low;
            high = 3*old_h + 2*old_l;
            low = old_h + old_l;
        }
        cout << high << "," << low << endl;
    }
}