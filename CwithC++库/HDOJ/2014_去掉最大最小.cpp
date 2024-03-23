/**
 * 先排序，去掉第1个和最后一个
 * 再求平均分
 * 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        vector<float> grades;
        float temp;
    	for (int i = 0; i < n; i++)
        {
        	scanf("%f", &temp);
            grades.push_back(temp);
        }
        sort(grades.begin(), grades.end());
        //
        grades.pop_back();
        grades.erase(grades.begin());

        //
        float sum = 0;
        for (float i : grades)
        {
			sum += i;
        }
        float avg = sum / (float)grades.size(); // 不加（float）就不对
        printf("%.2f\n", avg);
    }
}