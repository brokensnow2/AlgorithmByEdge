#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
#include <stdlib.h> // 引入标准库，包含atoi函数

// 定义一个数组，将0-9的整数映射到对应的英文单词
char *num_to_word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    char N[100]; // 定义一个字符数组来存储输入的大整数
    fgets(N, 100, stdin); // 从标准输入读取一行
    // N[strcspn(N, "\n")] = 0;这行代码的意思是将N中的换行符替换为字符'\0'
    // 空字符在ASCII表中的值就是0。
    N[strcspn(N, "\n")] = 0; // 去掉换行符

    // 计算N的各位数字之和
    int s = 0;
    for (int i = 0; i < (int)strlen(N); i++) {
        s += N[i] - '0'; // 将字符转换为对应的整数并累加
    }

    // 将和s的每一位数字转换为英文单词，并用空格连接
    char result[100] = ""; // 定义一个字符数组来存储结果
    sprintf(N, "%d", s); // 将整数s转换为字符串
    for (int i = 0; i < (int)strlen(N); i++) {
        strcat(result, num_to_word[N[i] - '0']); // 将数字转换为对应的英文单词并添加到结果中
        if (i != (int)strlen(N) - 1) {
            strcat(result, " "); // 在单词之间添加空格
        }
    }

    // 打印结果
    printf("%s\n", result);

    return 0;
}
