/**
 * todo解题思路:
 * 找到距离最近的两个玩具的距离，就是环的直径
 * 但不能直接暴力的两层for循环，因为N：N (2 <= N <= 100,000),时间复杂度为N^2，会超时
 * 
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    double min;
    while (cin >> N && N)
    {
        min = 1e20;
        //            x       y
        vector<pair<double, double>> toys(N);
        for (int i = 0; i < N; i++)
        {
            cin >> toys[i].first >> toys[i].second;
        }
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                double temp = pow((toys[i].first - toys[j].first), 2) + 
                    pow((toys[i].second - toys[j].second), 2);
                double diameter = sqrt(temp);
                if (min > diameter)
                {
                    min = diameter;                    
                }
            }
        }
        
        cout << fixed << setprecision(2) << min/2 << endl;
    }
    
}