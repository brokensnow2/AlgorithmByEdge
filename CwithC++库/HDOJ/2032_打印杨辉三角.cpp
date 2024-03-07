/**
生成杨辉三角的方法是通过动态规划来实现的。
每一行的数字可以通过上一行的数字来计算得到。具体来说，
每一行的第一个和最后一个数字都是1，其他的数字则是上一行的相邻两个数字之和。
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/
#include <iostream>
#include <vector>

using namespace std;

// 定义一个函数来生成杨辉三角
void generatePascalTriangle(int numRows) {
    vector<int> row(numRows, 1); // 创建一个大小为numRows的向量，所有元素初始化为1
    for (int i = 0; i < numRows; i++) { // 对于杨辉三角的每一行
		// 从第三行开始，反正1，2行都是1
        // 从倒数第2个元素开始，向前遍历到第二个元素
        for (int j = i-1; j > 0; j--) {
            // 当前元素等于当前元素与前一个元素之和
            row[j] += row[j - 1];
        }
        // 输出当前行的所有元素
        for (int j = 0; j <= i; j++) {
            cout << row[j] << ' ';
        }
        cout << '\n'; // 换行
    }
}

int main() {
    int n;
    while(cin >> n) // 读取用户输入的行数
    {
        generatePascalTriangle(n); // 生成并打印杨辉三角
        cout << endl; // 换行
    }
    
    return 0;
}

