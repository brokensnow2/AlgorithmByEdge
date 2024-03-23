#include <cstdio>
#include <cmath>
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <iomanip>
#define PI 3.1415927

using namespace std;

int main()
{
    double r;
	while(scanf("%lf",&r) != EOF)
    {
        double ans = fabs(r);
        cout << fixed << setprecision(2) << ans << endl;; 
    }
}

/**
double my_fabs(double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}


*/