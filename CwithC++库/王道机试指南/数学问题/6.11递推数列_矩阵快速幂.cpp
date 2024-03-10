#include <iostream>  // 引入输入输出流库
#include <vector>  // 引入向量库，用于存储动态规划的结果

using namespace std;  // 使用标准命名空间
/*
int main() {
    int a0, a1, p, q, k;
    cin >> a0 >> a1 >> p >> q >> k;  // 读取输入

    vector<int> dp(k + 1);  // 初始化动态规划数组
    dp[0] = a0 % 10000;  // 计算 a0 对 10000 的模
    dp[1] = a1 % 10000;  // 计算 a1 对 10000 的模

    for (int i = 2; i <= k; ++i) {
        // 使用递推公式计算 a_i 对 10000 的模
        // 因为(a*b)%c=(a%c * b%c)%c
        dp[i] = (p * dp[i - 1] + q * dp[i - 2]) % 10000;
    }

    cout << dp[k];  // 输出结果

    return 0;
}
*/

//解法2：矩阵快速幂
typedef vector<vector<int>> Matrix;

struct Mat {
    int row, col;
    Matrix mat;
    Mat(int r, int c) : row(r), col(c), mat(r, vector<int>(c,0)) {}
};

Mat Mutiply(Mat &A, Mat &B){
	// 生成结果数组
    Mat ans(A.row, B.col);
    // 运算
    for (int i = 0; i < A.row; i++){
        for (int j = 0; j < B.col; j++){
            for (int k = 0; k < A.col; k++){
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    return ans;
}

Mat FastPow(Mat &A, int n){
    // 创造一个单位阵
    Mat result(A.row, A.col);
    for (int i = 0; i < A.row; ++i) {
        result.mat[i][i] = 1;
    }
    // 快速幂算法
    while (n > 0) {
        if (n & 1) {
            result = Mutiply(result, A);  // 累乘
        }
        A = Mutiply(A, A);  // 自乘
        n >>= 1;  // 右移一位
    }

    return result;  // 返回结果矩阵
}

int main(){
	int a0, a1, p, q, k;
    cin >> a0 >> a1 >> p >> q >> k;  // 读取输入

    // 定义转移矩阵
    Mat A(2,2);
    A.mat = {{p,q}, {1,0}};

    // 计算矩阵的快速幂
    Mat B = FastPow(A, k - 1);

    // 计算 a_k 对 10000 的模
    int ak = (B.mat[0][0] * a1 + B.mat[0][1] * a0) % 10000;

    cout << ak;  // 输出结果

    return 0;
}




