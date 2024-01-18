"""
给定序列K整数 {N1 ,N2 , ...,Nk }.连续子序列定义为 {Ni,Ni+1, ...,Nj} 
其中1 ≤ i ≤ j≤ K.最大子序列是具有最大元素总和的连续子序列。例如，给定序列 { -2， 11， -4， 13， -5， -2 }，
其最大子序列为 { 11， -4， 13 }，最大和为 20。
现在你应该找到最大的总和，以及最大子序列的第一个和最后一个数字。

Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, 
together with the first and the last numbers of the maximum subsequence. 
The numbers must be separated by one space, but there must be no extra space at the end of a line. 
In case that the maximum subsequence is not unique, output the one with the smallest indices i and j 
(as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
"""

def max_subsequence(seq):
    max_sum = -1
    temp_sum = 0
    start = 0
    end = 0
    temp_index = 0

    for i in range(len(seq)):
        temp_sum += seq[i]
        if temp_sum < 0:
            temp_sum = 0
            temp_index = i + 1
        elif temp_sum > max_sum:
            max_sum = temp_sum
            start = temp_index
            end = i

    return max_sum, seq[start], seq[end]


num = int(input())
count = 0
array = input().split()
seq = list(map(int, array))
for i in seq:
    if i < 0:
        count += 1
if count != num:
    max_sum, first_num, last_num = max_subsequence(seq)
    print(f"{max_sum} {first_num} {last_num}")
else:
    print(f"0 {seq[0]} {seq[-1]}")
