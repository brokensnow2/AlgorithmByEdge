#include <iostream>
#include <iomanip>

using namespace std;

// 0到9的阶乘
int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
// e's approximation
double ans = 0;

int main()
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
        ans = ans + 1.0 / factorial[i];
        cout << left << setw(12) << setprecision(9) << ans;
        cout << endl;
    }
    
}