"""
任何数字系统中的可逆素数都是其在该数字系统中“逆”也是素数的素数。例如，在十进制中，73是可逆素数，因为它的逆37也是素数。
现在给定任意两个正整数N（＜10
5.
)和D（1<D≤10），你应该判断N是否是以D为基数的可逆素数。
输入规范：
输入文件由几个测试用例组成。每种情况都占用一行，其中包含两个整数N和D。输入以负N结束。
输出规格：
对于每个测试用例，如果N是以D为基数的可逆素数，则打印一行“是”；如果不是，则打印“否”。
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No

解题思路：
先判断原数是否是素数
再判断原数在其他进制下的逆的十进制数是否可逆
"""


def is_prime(n):
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def ToOthersRadix(num, radix):
    result = ''
    while num > 0:
        result = str(num % radix) + result
        num = num // radix
    return result

def ToDecRadix(num :str, radix :int) -> int:
    j = 0
    result = 0
    for i in range(len(num)-1,-1,-1):
        result += int(num[i]) * (D ** j)
        j += 1
    return result

ans = []
data = input().split()
while int(data[0]) >= 0:
    N = data[0]
    N_int = int(data[0])
    D = int(data[1])
    if is_prime(N_int):
        str1 = ToOthersRadix(N_int,D)
        """
        字符串在Python中是不可变的，不能在原地反转字符串。你只能创建一个反向的副本
        """
        Reversed_N = str1[::-1]
        if is_prime(ToDecRadix(Reversed_N,D)):
            ans.append("Yes")
        else:
            ans.append("No")
    else:
        ans.append("No")
    data = input().split()
for i in ans:
    print(i)