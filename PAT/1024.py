"""
向前或向后书写时相同的数字称为回文数。例如，1234231是一个回文数字。所有的个位数都是回文数。
非回文数可以通过一系列运算与回文数配对。首先，将非回文数反转，并将结果添加到原始数上。
如果结果不是回文数，则重复此操作，直到它给出回文数为止。
例如，如果我们从67开始，我们可以分两步得到一个回文数：67+76=143，143+341=484。
给定任何正整数N，你应该找到它的配对回文数和找到它的步骤数。
输入规范：
每个输入文件包含一个测试用例。每种情况由两个正数N和K组成，其中N（≤10^10)是初始数字，K（≤100）是最大步数。这些数字用空格隔开。
输出规格：
对于每个测试用例，输出两个数字，每行一个。第一个数字是N的成对回文数，第二个数字是找到回文数所需的步骤数。
如果在K步之后没有找到回文数，只需输出在第K步获得的数字和K。

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
"""
def isPalindromic(num :int) -> bool:
    string = f"{num}"
    """
    反转的各种方式：
    string[-1:-len(string)-1:-1)
    reversed_s = ''.join(reversed(s))
    """
    if string == string[::-1]:
        return True
    else:
        return False
def add(num :int):
    string = f"{num}"
    N_reversed = int(string[::-1])
    return num+N_reversed

N,K = map(int,input().split())
for i in range(K):
    if isPalindromic(N):
        print(f"{N}")
        print(f"{i}")
        break
    else:
        N = add(N)
else:
    print(N)
    print(K)