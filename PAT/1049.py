"""
The task is simple: given any positive integer N, 
you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. 
For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:
Each input file contains one test case which gives the positive N (≤2^30).

Output Specification:
For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
"""

def count_ones(n):  # 定义一个函数count_ones，参数为n
    count = 0  # 初始化计数器为0
    i = 1  # 初始化i为1，表示当前计算的位数（个位、十位、百位...）
    while i <= n:  # 当i小于等于n时，继续循环
        divider = i * 10  # 计算分隔数，用于分割n的当前位和更高的位
        # (n // divider) * i：   更高位：不包括当前位对当前位1出现次数的贡献     
        # min(max(n % divider - i + 1, 0), i)： 当前位和低位对当前位1出现次数的贡献
        count += (n // divider) * i + min(max(n % divider - i + 1, 0), i)  # 计算当前位上1的数量，并累加到计数器
        i *= 10  # i乘以10，准备计算下一位
    return count  # 返回计数器的值，即1的总数

N = int(input())  # 从用户输入获取N
print(count_ones(N))  # 调用函数count_ones计算1的总数，并打印结果
