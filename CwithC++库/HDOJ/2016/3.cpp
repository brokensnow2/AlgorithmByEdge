/**
 * todo 解题思路
 * 基于C的fopen
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义学生结构体
struct Student 
{
    char name[10];
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

// 计算总分和平均分
void calculateScores(vector<Student>& students) 
{
    for (auto& student : students) 
    {
        student.total = student.chinese + student.math + student.english;
    }
}

// 比较函数用于排序
bool compare(const Student& a, const Student& b) 
{
    if (a.total != b.total) 
    {
        return a.total > b.total;
    } else 
    {
        return a.id < b.id;
    }
}

int main() 
{
    FILE *file = fopen("../3.txt", "r");
    if (file == NULL) 
    {
        printf("无法打开文件。\n");
        return 1;
    }

    std::vector<Student> students(20);
	int numStudents = 0;
    // 从文件读取学生信息
    char buffer[1024]; // 假设一行不超过 1024 个字符
    fgets(buffer, sizeof(buffer), file); // 读取第一行
    while (fscanf(file, "%s %d %d %d %d |", students[numStudents].name, &students[numStudents].id,
                  &students[numStudents].chinese, &students[numStudents].math, &students[numStudents].english) == 5) 
    {
        ++numStudents;
    }

    // 计算总分和平均分
    calculateScores(students);

    // 按总分排序
    std::sort(students.begin(), students.begin()+numStudents, compare);

    // 打印结果
    std::cout << "姓名\t学号\t总分\t平均分\n";
    for (int i = 0; i < numStudents; i++) 
    {
        std::cout << students[i].name << "\t" << students[i].id << "\t" << students[i].total << "\t" << static_cast<float>(students[i].total) / 3 << "\n";
    }

    /**
     * 写文件
     * FILE *file = fopen("new_file.txt", "w");
     * 使用fprintf函数
     * fclose(file);
    */

    return 0;
}

