/**
 * Problem Description
Given two rectangles and the coordinates of two points on the diagonals of each rectangle,you have to calculate the area of the intersected part of two rectangles. its sides are parallel to OX and OY .

Input
Input The first line of input is 8 positive numbers which indicate the coordinates of four points that must be on each diagonal.The 8 numbers are x1,y1,x2,y2,x3,y3,x4,y4.That means the two points on the first rectangle are(x1,y1),(x2,y2);the other two points on the second rectangle are (x3,y3),(x4,y4).

Output
Output For each case output the area of their intersected part in a single line.accurate up to 2 decimal places.

Sample Input
1.00 1.00 3.00 3.00 2.00 2.00 4.00 4.00
5.00 5.00 13.00 13.00 4.00 4.00 12.50 12.50

Sample Output
1.00
56.25
 * 
 * 
*/


/**
 * 两个矩形面积的重合也是个矩形（或者根本没有重合）
 * 重合矩形的宽为min(max(x1, x2), max(x3, x4)) - max(min(x1, x2), min(x3, x4));
 * 重合矩形的高为min(max(y1, y2), max(y3, y4)) - max(min(y1, y2), min(y3, y4));
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
		double width = min(max(x1, x2), max(x3, x4)) - max(min(x1, x2), min(x3, x4));
        double height = min(max(y1, y2), max(y3, y4)) - max(min(y1, y2), min(y3, y4));
        double S = width * height;
        if (S < 0)
        	printf("0.00\n");
        else
        	cout << fixed << setprecision(2) << S << endl;
    }
}