/**
 * todo 解题思路
 * 基于C++的ifstream
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义学生结构体
struct Student 
{
    std::string name;
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

// 计算总分和平均分
void calculateScores(vector<Student>& students) 
{
    for (auto& student : students) {
        student.total = student.chinese + student.math + student.english;
    }
}

// 比较函数用于排序
bool compare(const Student& a, const Student& b) 
{
    if (a.total != b.total) {
        return a.total > b.total;
    } else {
        return a.id < b.id;
    }
}

int main() 
{
    ifstream file("../3.txt"); // 创建输入文件流对象
    if (!file.is_open()) 
    {
        std::cerr << "无法打开文件。\n";
        return 1;
    }

    std::vector<Student> students;
    Student student;
    string str;
    // 读取第一行
	getline(file, str);
    // 从文件读取学生信息
    while (file >> student.name >> student.id >> student.chinese >> student.math >> student.english) 
    {
        // 读取每行最后的“|”
        char pipe;
        file >> pipe;
        students.push_back(student);
    }

    file.close();

    // 计算总分和平均分
    calculateScores(students);

    // 按总分排序
    std::sort(students.begin(), students.end(), compare);

    // 打印结果
    std::cout << "姓名\t学号\t总分\t平均分\n";
    for (const auto& s : students) 
    {
        std::cout << s.name << "\t" << s.id << "\t" << s.total << "\t" << static_cast<float>(s.total) / 3 << "\n";
    }

    /**
     * // 打开一个输出文件
    std::ofstream outputFile("student_results.txt");
    if (!outputFile.is_open()) {
        std::cerr << "无法创建输出文件。\n";
        return 1;
    }

    // 将结果写入文件
    outputFile << "姓名\t学号\t总分\t平均分\n";
    for (const auto& s : students) {
        outputFile << s.name << "\t" << s.id << "\t" << s.total << "\t" << static_cast<float>(s.total) / 3 << "\n";
    }

    outputFile.close();

     * 
    */

    return 0;
}
