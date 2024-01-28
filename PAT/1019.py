"""
判断在某个进制下是否是回文数：
给定任何一个十进制正整数N和一个以b为底的数，判断N是否是以b为基的回文数。
Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
"""
def ToOthersRadix(num, radix):
    result = ''
    if num == 0:
        return '0' + result
    while num > 0:
        result = str(num % radix) + result
        num = num // radix
    return result

N,B = map(int,input().split())
ans = ToOthersRadix(N,B)
if ans == ans[::-1]:
    print("Yes")
    print(' '.join(ans))
else:
    print("No")
    print(' '.join(ans))