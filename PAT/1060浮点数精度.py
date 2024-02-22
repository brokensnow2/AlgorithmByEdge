"""
如果一台机器只能保存3个有效数字，则浮点数字12300和12358.9被视为相等，因为它们都保存为0.123×10^5.
现在，给定一台机器上的有效位数和两个浮点数，你应该知道它们在该机器中是否被同等对待。
输入规范：
每个输入文件包含一个测试用例，给出三个数字N、A和B，其中N（<100）是有效位数，A和B是要比较的两个浮点数。
每个浮点数为非负数，不大于10^100，并且其总位数小于100。
输出规格：
对于每个测试用例，如果两个数字相等，则打印一行YES，然后以标准形式0.d[1]...d[N]*10^k（d[1]>0，除非数字为0）打印数字；
如果它们不相等，则为NO，然后是标准形式的两个数字。
所有项都必须用空格隔开，在行的末尾没有多余的空格。
注：假设简单的切分不需要四舍五入。

Sample Input 1:
3 12300 12358.9

Sample Output 1:
YES 0.123*10^5

Sample Input 2:
3 120 128

Sample Output 2:
NO 0.120*10^3 0.128*10^3

"""

def standard_form(num, N):
    k = 0
    while num >= 1:
        num /= 10
        k += 1
    return str(num)[0:N+2], k

def compare(num1, num2, N):
    num1, k1 = standard_form(num1, N)
    num2, k2 = standard_form(num2, N)
    if float(num1) == float(num2) and k1 == k2:
        return "YES", num1, k1
    else:
        return "NO", num1, k1, num2, k2

def main():
    N, num1, num2 = map(float, input().split())
    N = int(N)
    result = compare(num1, num2, N)
    if result[0] == "YES":
        print(f"YES {result[1] :0{N+2}}*10^{result[2]}")
    else:
        print(f"NO {result[1] :0{N+2}}*10^{result[2]} {result[3] :0{N+2}}*10^{result[4]}")

if __name__ == "__main__":
    main()