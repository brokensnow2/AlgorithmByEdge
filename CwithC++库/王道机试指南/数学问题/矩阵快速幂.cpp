#include <vector>  // 引入向量库，用于存储矩阵
#include <iostream>

using namespace std;  // 使用标准命名空间

// 定义矩阵类型
typedef vector<vector<int>> Matrix;

struct Mat {
    int row, col;
    Matrix mat;

    // 构造函数，初始化矩阵的行数和列数，并创建一个 row*col 的零矩阵
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

// 矩阵快速幂函数
Mat quickPower(Mat A, int n) {
    // 创建一个单位矩阵(初始值)
    Mat result(A.row, A.col);
    for (int i = 0; i < A.row; ++i) {
        result.mat[i][i] = 1;
    }

    // 快速幂算法
    while (n > 0) {
        if (n & 1) {
            result = multiply(result, A);  // 累乘
        }
        A = multiply(A, A);  // 自乘
        n >>= 1;  // 右移一位
    }

    return result;  // 返回结果矩阵
}

// 主函数
int main() {
    // 定义一个矩阵
    Mat A(2, 2);
    A.mat = {{1, 2}, {3, 4}};

    // 计算矩阵的快速幂
    Mat B = quickPower(A, 3);

    // 输出结果矩阵
    for (int i = 0; i < B.row; ++i) {
        for (int j = 0; j < B.col; ++j) {
            cout << B.mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
