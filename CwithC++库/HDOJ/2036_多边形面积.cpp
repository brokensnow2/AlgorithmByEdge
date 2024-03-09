#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

float getTriangleArea(int b_x, int b_y, int c_x, int c_y)
{
	return (float)(b_x*c_y - c_x*b_y) / 2.0;
}

int main()
{
    int n;
    while(cin >> n)
    {
    	vector<int> coordinate(2*n);
    	for (int i = 0; i < 2*n; i++)
    	{
        	cin >> coordinate[i];
    	}

        float sum = 0.0;
        for (int i = 1; i < n-1; i++)
        {
			sum += getTriangleArea(coordinate[i*2]-coordinate[0]
            				, coordinate[2*i+1]-coordinate[1]
                            , coordinate[2*i+2]-coordinate[0]
                            , coordinate[2*i+3]-coordinate[1]
                            );
        }
        printf("%.1f\n", sum);
    }


}