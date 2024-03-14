#include <iostream> // 引入iostream库以进行输入/输出操作
#include <vector>   // 引入vector库以使用向量数据结构
#include <algorithm> // 引入algorithm库以使用sort函数

using namespace std; // 使用标准命名空间

vector<int> subset; // 声明一个向量来存储子集序列

// 函数生成An的所有子集序列，按字典顺序排列
void generateSubsets(int n, int m, int idx = 1) {
    if (m == 0) { // 如果m变为0
        for (int i = 0; i < subset.size(); i++) { // 遍历子集
            cout << subset[i] << " "; // 打印子集的元素
        }
        cout << endl; // 打印换行符
        return; // 从函数返回
    }

    for (int i = idx; i <= n; i++) { // 从idx到n循环
        subset.push_back(i); // 将i添加到子集
        generateSubsets(n, m - 1, i + 1); // 递归调用函数以获取下一个元素
        subset.pop_back(); // 从子集中删除最后一个元素
    }
}

int main() { // 主函数开始
    int t; // 声明一个整数t来存储测试用例的数量
    cin >> t; // 输入测试用例的数量

    while (t--) { // 遍历每个测试用例
        int n, m; // 声明整数n和m，分别存储元素总数和第m个子集序列
        cin >> n >> m; // 输入元素总数和第m个子集序列

        generateSubsets(n, m); // 调用函数生成An的所有子集序列，按字典顺序排列
    }

    return 0; // 主函数结束
}
