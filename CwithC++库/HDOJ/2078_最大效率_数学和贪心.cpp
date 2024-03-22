/**
 * a^2 + b^2 <= (a+b)^2
 * todo 有什么能比(100-min)^2大？
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int counts, n, m;
    int temp;
    cin >> counts;
    while (counts--)
    {
        int min = 100;
        cin >> n >> m;
        while(n--)
        {
            cin >> temp;
            if (temp < min)
            	min = temp;
        }
        cout << (100-min)*(100-min) << endl;
    }
}