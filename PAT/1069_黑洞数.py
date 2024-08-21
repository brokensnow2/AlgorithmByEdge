"""
对于任何 4 位整数，除了所有数字都相同的整数，
如果我们先按非递增顺序对数字进行排序，然后按非递减顺序对数字进行排序，
则可以通过从第一个数字减去第二个数字来获得一个新数字。
以这种方式重复，我们很快就会得到这个数字6174——4位数字的黑洞。

给定任何4位数字，您都应该说明它进入黑洞的方式。

输入规格：
每个输入文件都包含一个测试用例，该测试用例给出一个正整数N在范围内(0,10^4).

输出规格：
如果所有4位数字是一样的，把方程式写在一行里。否则，将计算的每一步打印成一行，直到得出差值。
所有数字必须打印为 4 位数字。N - N = 0000

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
"""

number  = input().zfill(4)

def toInt(l :list):
    num = 0
    for i in range(len(l)):
        num *= 10
        num += int(l[i])
    return num

def isSame(l :str):
    for i in range(len(l)-1):
        if l[i] == l[i+1]:
            pass
        else:
            return False
    return True

if isSame(number):
    print(f"{number:04} - {number:04} = 0000")
else:
    while number != '6174':
        num1 = sorted(number)
        num2 = sorted(number, reverse=True)
        num2_int = toInt(num2)
        num1_int = toInt(num1)
        next_number = num2_int - num1_int
        print(f"{num2_int:04} - {num1_int:04} = {next_number:04}")
        number = str(f"{next_number:04}") # case:2221

