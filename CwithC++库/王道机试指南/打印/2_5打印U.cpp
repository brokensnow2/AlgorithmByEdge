extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}
#include <iostream> //Cpp的标准输入输出库
#include <algorithm> // 引入C++的算法库


using namespace std; // 使用标准命名空间
/**
*@brief : 
	(N + 2) / 3的结果是将字符串长度加2后除以3的整数部分，
    +2是因为左下角和右下角重复计算了
    这样可以确保U形状的两个垂直边和底边的总长度等于字符串长度。
    然后我们再减去1，因为底边至少有一个字符，所以垂直边的长度需要减1。

*/

// 定义print_u_shape函数，参数为字符串s
void print_u_shape(string s) {
    // 计算字符串长度
    int N = s.length();

    // 计算垂直边和底边的长度
    int n1 = (N + 2) / 3 - 1;
    int n3 = n1;
    int n2 = N - n1 - n3;

    // 打印U形状的两个垂直边
    for (int i = 0; i < n1; i++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j++) {
            cout << ' ';
        }
        cout << s[N - i - 1] << endl;
    }

    // 打印U形状的底边
    for (int i = n1; i < N - n1; i++) {
        cout << s[i];
    }
    cout << endl;
}

// 主函数
int main() {
    string input;
    getline(cin, input);
    print_u_shape(input);
    return 0;
}
