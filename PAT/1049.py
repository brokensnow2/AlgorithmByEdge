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

def count_ones(n):
    count = 0
    i = 1
    while i <= n:
        divider = i * 10
        count += (n // divider) * i + min(max(n % divider - i + 1, 0), i)
        i *= 10
    return count

N = int(input())
print(count_ones(N))