"""
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2
 , your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit(感觉像是每一个数) is less than its radix and is chosen from the set { 0-9, a-z } 
where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. 
The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.
Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. 
If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
"""

"""
分析：
利用按权展开法
当选的进制（从小到大）得到的数大于已知进制的数：不可能，跳出循环
当选的进制（从小到大）得到的数等于已知进制的数：找到
"""

def char_to_int(c):
    if '0' <= c <= '9':
        return ord(c) - ord('0')
    else:
        return ord(c) - ord('a') + 10

def calcValue(s, radix):
    expCount = 0
    sum = 0
    for i in reversed(s):
        sum += char_to_int(i)*radix**expCount
        expCount += 1
    return sum

def solve():
    data = input().split()
    tag = int(data[2])
    radix = int(data[3])
    if tag == 1:
        value = calcValue(data[0], radix)
        num = data[1]
    else:
        value = calcValue(data[1], radix)
        num = data[0]
    # A digit(感觉像是每一个数) is less than its radix 
    left = max([char_to_int(c) for c in num]) + 1
    # 右界value + 1是因为只要num有一个数字不是0就不可能等于value
    right = max(left, value + 1)
    # 注意二分查找代码
    while left <= right:
        mid = (left + right) // 2
        if calcValue(num, mid) > value:
            right = mid - 1
        elif calcValue(num, mid) < value:
            left = mid + 1
        else:
            print(mid)
            break
    # 最后没找到肯定是left > right
    if left > right:
        print("Impossible")
    

solve()
