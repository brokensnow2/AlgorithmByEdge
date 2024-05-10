/**
 * 同PAT1008
 * 
*/
#include <iostream>

using namespace std;

int main()
{
    int n, currentFloor, floor, time;
    while (cin >> n && n)
    {
        // 初始化变量
        currentFloor = 0;
        time = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> floor;
            if (floor > currentFloor)
                time += (floor - currentFloor) * 6;
            else
                time += (currentFloor - floor) * 4;
            currentFloor = floor;
        }
        cout << time + n * 5 << endl;
    }
    
}