extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}

#include <algorithm> // 引入C++的算法库
#include <vector> // 引入C++的向量库

using namespace std; // 使用标准命名空间

struct Member {
    char id[10];
    char signIn[10];
    char signOut[10];
};

/**
 * @brief 这是一个C++的比较函数，用于比较两个Member结构体中的signIn成员（也就是签到时间）。
 * 函数接收两个Member结构体的引用作为参数，然后使用strcmp函数比较它们的signIn成员。
strcmp函数是C语言中的一个标准函数，用于比较两个字符串。如果第一个字符串小于第二个字符串，它会返回一个负数；
如果两个字符串相等，它会返回0；如果第一个字符串大于第二个字符串，它会返回一个正数。
所以，strcmp(a.signIn, b.signIn) < 0这个表达式的意思是，如果a的签到时间早于b的签到时间，那么返回true；
否则返回false。
这个比较函数可以被用在一些需要比较的算法中，比如std::sort、std::min_element、std::max_element等等。
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool compareSignIn(const Member &a, const Member &b) {
    return strcmp(a.signIn, b.signIn) < 0;
}

bool compareSignOut(const Member &a, const Member &b) {
    return strcmp(a.signOut, b.signOut) > 0;
}

int main() {
    int num; // 定义一个整数变量来存储输入的数量
    scanf("%d", &num); // 从标准输入读取数量

    vector<Member> members; // 定义一个向量来存储成员信息
    for (int i = 0; i < num; i++) {
        Member member;
        scanf("%s %s %s", member.id, member.signIn, member.signOut); // 从标准输入读取成员信息
        members.push_back(member); // 将成员信息添加到向量中
    }

    // 找到签到时间最早的成员的ID
    /*
    min_element(members.begin(), members.end(), compareSignIn)是C++标准模板库（STL）中的一个函数，
    它在<algorithm>头文件中定义。这个函数用于找到一个范围内的最小元素。在这里，它被用来找到members向量中签到时间最早的成员。
    members.begin()和members.end()定义了要搜索的范围，即members向量的全部元素。
    compareSignIn是一个比较函数，它接受两个Member结构体的引用，并返回一个布尔值，表示第一个成员的签到时间是否早于第二个成员的签到时间。
    min_element函数返回一个指向范围内最小元素的迭代器。如果有多个最小元素，min_element返回第一个出现的最小元素的迭代器。
    ->id是一个箭头运算符，它用于访问迭代器指向的元素的成员。在这里，它被用来访问最早签到的成员的ID。
    char *signInID = ...;这部分代码将最早签到的成员的ID赋值给signInID变量。
    */
    char *signInID = min_element(members.begin(), members.end(), compareSignIn)->id;

    // 找到签出时间最晚的成员的ID
    char *signOutID = max_element(members.begin(), members.end(), compareSignOut)->id;

    // 打印结果
    printf("%s %s\n", signInID, signOutID);

    return 0;
}