#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
/*
8 20
Smith	  -1	-16	8	0	0	120	39	0
John	  116	-2	11	0	0	82	55(1)	0
Josephus  72(3)	126	10	-3	0	47	21(2)	-2
Bush	  0	-1	-8	0	0	0	0	0
Alice	  -2	67(2)	13	-1	0	133	79(1)	-1
Bob	  0	0	57(5)	0	0	168	-7	0
 



*/
using namespace std;

struct Student {
    string name;
    int problem, time;
};

bool compare(const Student &a, const Student &b) {
    if (a.problem != b.problem)
        return a.problem > b.problem; // 优先级越小越在前面；返回true的优先级越小
    if (a.time != b.time)
        return a.time < b.time;
    return a.name < b.name;
}

int main() {
    int n, m;
    cin >> n >> m;
    getchar();
    //cin.ignore();  // 添加这行来读取换行符
    vector<Student> students;
    string line;
    while (getline(cin, line)) {
        Student student;
        student.problem = 0;
        student.time = 0;
        int pos = line.find(' ');
        student.name = line.substr(0, pos);
        line = line.substr(pos + 1);
        for (int i = 0; i < n; i++) {
            pos = line.find_first_not_of(' ');  // 从非空格字符开始查找
            line = line.substr(pos);
            pos = line.find(' ');
            string record = line.substr(0, pos);
            line = line.substr(pos + 1);
            if (record[0] != '-') {
                pos = record.find('(');
                if (pos != string::npos) {
                    int time = stoi(record.substr(0, pos));  // 只转换括号前的部分
                    record.pop_back(); // 弹出右括号
                    int penalty = stoi(record.substr(pos + 1));
                    student.problem++;
                    student.time += time + penalty * m;
                } else {
                    int time = stoi(record);
                    student.problem++;
                    student.time += time;
                }
            }
        }
        students.push_back(student);
    }
    sort(students.begin(), students.end(), compare);
    for (const Student &student : students)
        cout << left << setw(10) << student.name << " " << right << setw(2) << student.problem << " " << setw(4) << student.time << "\n";
    return 0;
}
