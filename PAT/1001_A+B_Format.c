#include <stdio.h>
#include <string.h>
/**
 * 
 * Calculate a+b and output the sum in standard format 
 * -- that is, the digits must be separated into groups of three 
 * by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. 
Each case contains a pair of integers a and b where −10^6
 ≤a,b≤10^6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.
Sample Input:
-1000000 9
Sample Output:
-999,991
 * 
 * 
*/

// 函数用于在字符串的指定位置插入逗号
void insertComma(char *str, int pos) {
    int len = strlen(str);
    // 从后往前移动字符，为逗号腾出空间
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    // 在指定位置插入逗号
    str[pos] = ',';
    // 添加结束符
    str[len + 1] = '\0';
}

// 函数用于将数字格式化为千位分隔形式
void formatSum(int a, int b) {
    // 计算a和b的和
    int result = a + b;
    char formatted_result[20];
    sprintf(formatted_result, "%d", result);
    int len = strlen(formatted_result);
    // 根据字符串的长度，决定插入逗号的次数和位置
    if (len > 3) {
        // 如果是负数，跳过负号
        int start = result < 0 ? 1 : 0;
        // 从右往左每隔三个字符插入一个逗号
        for (int i = len - 3; i > start; i -= 3) {
            insertComma(formatted_result, i);
        }
    }
    // 使用puts函数输出字符串
    puts(formatted_result);
}

int main() {
    // 示例输入
    int a, b;
    scanf("%d %d", &a, &b);

    // 计算并输出结果
    formatSum(a, b);

    return 0;
}

