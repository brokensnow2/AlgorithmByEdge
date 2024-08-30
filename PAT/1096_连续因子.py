"""
Among all the factors of a positive integer N, there may exist several consecutive numbers. 
For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. 
Now given any positive N, you are supposed to find the maximum number of consecutive factors, 
and list the smallest sequence of the consecutive factors.

Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2^31).

Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. 
Then in the second line, print the smallest sequence of the consecutive factors in the format 
factor[1]*factor[2]*...*factor[k], where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7

"""
def find_consecutive_factors(N):  # 定义一个函数，输入是一个正整数N
    max_len = 0  # 初始化连续因子的最大数量为0
    start = 0  # 初始化连续因子的起始值为0
    for i in range(2, int(N**0.5)+1):  # 从2开始，到N的平方根结束，尝试所有可能的起始因子
        product = 1  # 初始化连续因子的乘积为1
        j = i  # 设置当前因子为起始因子
        while product * j <= N:  # 当乘积乘以当前因子小于等于N时，继续循环
            product *= j  # 更新乘积
            if N % product == 0 and j - i + 1 > max_len:  # 如果N能被乘积整除，且连续因子的数量大于当前最大数量
                max_len = j - i + 1  # 更新最大连续因子数量
                start = i  # 更新连续因子的起始值
            j += 1  # 尝试下一个因子
    if max_len == 0:  # 如果没有找到连续因子
        return 1, [N]  # 返回1和N本身
    else:  # 如果找到了连续因子
        return max_len, list(range(start, start+max_len))  # 返回最大连续因子数量和连续因子序列

# 测试用例
N = int(input())  # 从用户那里获取输入
max_len, factors = find_consecutive_factors(N)  # 调用函数，获取最大连续因子数量和连续因子序列
print(max_len)  # 打印最大连续因子数量
print('*'.join(map(str, factors)))  # 打印连续因子序列，因子之间用*分隔

