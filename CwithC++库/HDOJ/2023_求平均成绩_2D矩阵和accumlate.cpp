/**
Problem Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，
求每个学生的平均成绩和每门课的平均成绩，
并输出各科成绩均大于等于平均成绩的学生数量。
 
Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，
分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。

Output
对于每个测试实例，输出3行数据，第一行包含n个数据，
表示n个学生的平均成绩，结果保留两位小数；
第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；
第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。

Sample Input
2 2
5 10
10 20

Sample Output
7.50 15.00
7.50 15.00
1
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

int main()
{
    //Students, Courses
    int n, m;
    cin >> n >> m;

    int temp;
	// 每门课成绩总分
    vector<int> grades(m);
    // 二维数组，每一个是stu
    vector<vector<int>> stus(n);
	// 读取输入
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            stus[i].push_back(temp);
            grades[j] += temp;
        }
    }

    //输出第一行
    for (int i = 0; i < n; i++)
    {
        float sum = accumulate(stus[i].begin(), stus[i].end(), 0);
        float avg = sum / (float)m;
        if (i != 0)
        {
            printf(" ");
        }
        printf("%.2f", avg);

    }
    printf("\n");

    // Output second line
    vector<float> avg_grade;
    for (int i = 0; i < m; i++)
    {
        float grade_avg = (float)grades[i] / (float)n;
        if (i != 0)
        {
            printf(" ");
        }
        printf("%.2f", grade_avg);
        avg_grade.push_back(grade_avg);
    }
    printf("\n");

    // Output third line
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool all_above_avg = true;
        for (int j = 0; j < m; j++)
        {
            if (stus[i][j] < avg_grade[j])
            {
                all_above_avg = false;
                break;
            }
        }
        if (all_above_avg)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
