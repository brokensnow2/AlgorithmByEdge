#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double a0, an1;
    while (cin >> n >> a0 >> an1)
    {
        vector<double> c(n+1);
        for (int i = 1; i <= n; i++)
        {
			cin >> c[i];
        }
        double a1 = n *a0 + an1;
		for (int i = 1; i <= n; i++)
        {
            a1 -= 2*i*c[n+1-i];
        }
        a1 /= (n + 1);
        cout << fixed << setprecision(2) << a1 << endl;
    }
}
