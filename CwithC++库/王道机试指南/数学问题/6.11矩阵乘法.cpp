#include <vector>  // 引入向量库，用于存储矩阵
#include <iostream>  // 引入输入输出流库

using namespace std;  // 使用标准命名空间

// 定义矩阵类型
typedef vector<vector<int>> Matrix;

struct Mat {
    int row, col;
    Matrix mat;

    // 构造函数，初始化矩阵的行数和列数，并创建一个 row*col 的零矩阵
    //使用 vector 的构造方法来初始化 mat。在 C++ 中，可以在初始化列表中使用这种方式来初始化成员变量
    // vector<int>(c, 0)是匿名对象
    Mat(int r, int c) : row(r), col(c), mat(r, vector<int>(c, 0)) {}
};

// 矩阵乘法函数
Mat multiply(const Mat& A, const Mat& B) {
    // 首先检查矩阵的维度是否允许进行乘法
    if (A.col != B.row) {
        cout << "Error: Matrix dimensions do not allow multiplication." << endl;
        return Mat(0, 0);
    }

    // 初始化结果矩阵，大小为 A.row * B.col，所有元素为 0
    Mat C(A.row, B.col);

    // 进行矩阵乘法
    for (int i = 0; i < A.row; ++i) {
        for (int j = 0; j < B.col; ++j) {
            for (int k = 0; k < A.col; ++k) {
                C.mat[i][j] += A.mat[i][k] * B.mat[k][j];  // 累加乘积
            }
        }
    }

    return C;  // 返回结果矩阵
}

// 主函数
int main() {
    // 定义两个矩阵
    Mat A(2, 3);
    A.mat = {{1, 2, 3}, {4, 5, 6}};
    Mat B(3, 2);
    B.mat = {{1, 4}, {2, 5}, {3, 6}};

    // 计算矩阵乘法
    Mat C = multiply(A, B);

    // 输出结果矩阵
    for (int i = 0; i < C.row; ++i) {
        for (int j = 0; j < C.col; ++j) {
            cout << C.mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

