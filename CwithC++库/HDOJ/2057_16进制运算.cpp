#include <iostream> // 引入输入输出流库
#include <string>   // 引入字符串库
#include <sstream>  // 引入字符串流库，用于字符串和其他数据类型之间的转换
#include <iomanip>  // 引入输入输出操作符库，用于控制输出格式

using namespace std;

int main() {
    string A, B; // 定义两个字符串变量，用于存储输入的十六进制数

    // 使用while循环读取输入，直到文件结束
    while (cin >> A >> B) {
        long long numA, numB; // 定义两个长整型变量，用于存储转换后的十进制数

        // 使用字符串流将十六进制字符串转换为十进制数
        stringstream ssA(A), ssB(B);
        ssA >> hex >> numA;
        ssB >> hex >> numB;

        long long sum = numA + numB; // 计算两个数的和

        // 如果和为负数，输出负号并取绝对值
        if (sum < 0) {
            cout << "-";
            sum = -sum;
        }

        // 输出和，以十六进制格式，字母部分大写
        cout << uppercase << hex << sum << endl;
    }

    return 0;
}
