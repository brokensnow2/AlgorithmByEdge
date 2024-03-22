#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, t, x;  // 定义循环变量和临时变量
    int n[2][51];  // 定义动态规划数组

    scanf("%d", &t);  // 读入测试用例的数量
    while (t--)  // 对于每个测试用例
    {
        memset(n[0], 0, sizeof(n[0]));  // 初始化动态规划数组
        n[0][0] = 1;  // 设置初始状态
        for (i = 1; i < 27; i++)  // 对于每一个字母
        {
            scanf("%d", &x);  // 读入这个字母的数量
            if (!x)  // 如果这个字母的数量为0
            {
                for (j = 0; j < 51; j++)  // 将上一个状态复制到当前状态
                    n[i % 2][j] = n[!(i%2)][j];
                continue;  // 跳过这个字母
            }
            memset(n[i % 2], 0, sizeof(n[0]));  // 初始化当前状态
            for (j = 0; j < 51 && j <= x * i; j += i)  // 对于每一个可能的价值
            {
                for (k = 0; k + j < 51 ; k++)  // 对于每一个可能的总价值
                {
                    if (n[!(i%2)][k])  // 如果上一个状态存在
                        n[i % 2][k + j] += n[!(i%2)][k];  // 更新当前状态
                }
            }
        }
        for (x = 0, i = 1; i < 51; i++)  // 计算总价值小于等于50的单词的数量
            x += n[0][i];
        printf("%d\n", x);  // 输出结果
    }

    return 0;
}
