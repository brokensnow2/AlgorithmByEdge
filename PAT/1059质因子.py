"""
Given any positive integer N, you are supposed to find all of its prime factors, 
and write them in the format N = p1^k1 × p2^k2 × ... × pm^km

Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:
Factor N in the format N = N = p1^k1 × p2^k2 × ... × pm^km, 
where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi
-- hence when there is only one pi, ki is 1 and must NOT be printed out.

Note: in case N has no prime factor, simply print the only factor it has. 
(Thanks to 王忠文 for pointing out this special case.)

Sample Input:
97532468

Sample Output:
97532468=2^2*11*17*101*1291
"""
def is_prime(num):
    """判断一个数是否是素数"""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

# 定义一个函数来找出一个数的所有质因数
def prime_factors(n):
    i = 2  # 从2开始检查
    factors = []  # 初始化一个空列表来存储质因数
    while i * i <= n:  # 只需要检查到根号n
        if n % i or not is_prime(i):  # 如果n不能被i整除或者i不是质数
            i += 1  # 检查下一个数
        else:  # 如果n能被i整除
            n = n // i  # 用n除以i
            factors.append(i)  # 将i添加到质因数列表中
    if n > 1 and is_prime(n):  # 如果n是一个质因数
        factors.append(n)  # 将n添加到质因数列表中
    return factors  # 返回质因数列表

# 定义一个函数来格式化质因数和它们的个数
def format_factors(n):
    factors = prime_factors(n)  # 获取n的所有质因数
    # 使用字典推导式来计算每个质因数的个数
    factor_count = {p: factors.count(p) for p in set(factors)}
    return n, factor_count  # 返回n和质因数的个数

# 定义主函数
def main():
    n = int(input())  # 读取输入
    n, factor_count = format_factors(n)  # 获取n的质因数和它们的个数
    output = []  # 初始化一个空列表来存储输出
    # 遍历所有的质因数
    for factor in sorted(factor_count.keys()):
        count = factor_count[factor]  # 获取质因数的个数
        if count == 1:  # 如果质因数的个数为1
            output.append(str(factor))  # 直接添加质因数
        else:  # 如果质因数的个数大于1
            output.append(f"{factor}^{count}")  # 添加质因数和它的个数
    # 打印结果
    if output != []:
        print(f"{n}=" + "*".join(output))
    else:
        print(f"{n}={n}") # 那个特殊的例子

# 如果这个脚本是直接运行的，而不是被导入的，那么就运行主函数
if __name__ == "__main__":
    main()
