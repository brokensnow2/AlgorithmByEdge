/**
 * todo 解题思路
 * 两层for循环
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    // number of points
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first; // X
        cin >> points[i].second; // Y
    }
    int min = INT32_MAX;
	for (int i = 0; i < n-1; i++)
    	for (int j = i + 1; j < n; j++)
        {
            int x_len = points[i].first - points[j].first;
            int y_len = points[i].second - points[j].second;
            double current = sqrt(x_len*x_len + y_len*y_len);
            if (current < min)
            	min = current;
        }
    cout << min << endl;
}