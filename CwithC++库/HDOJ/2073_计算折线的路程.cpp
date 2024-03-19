/**
 * todo 可以把线段分成两部分
 * todo 一部分是sqrt(2)，一部分是sqrt(i^2 + (i-1)^2) // i=x+y
 * sqrt(2)有 x + x+y-1 + x+y-2 + ... + 1个
 * 
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculate(double x, double y)
{
    int i = x + y;
    double sum = 0.0;
    double sqrt2 = sqrt(2);
	sum += (i-1)*i/2 * sqrt2 + x * sqrt2;
	for (; i > 0; i--)
    {
        sum += sqrt(i*i + (i-1)*(i-1));
    }
    return sum;
}

int main()
{
    int cases;
    double x1, y1, x2, y2, ans;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        double distance1 = calculate(x1, y1);
        double distance2 = calculate(x2, y2);
        if (distance1 < distance2)
        	ans = distance2 - distance1;
        else
        	ans = distance1 - distance2;
        cout << fixed << setprecision(3) << ans << endl;
    }
    
}