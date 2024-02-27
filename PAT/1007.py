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

"""
这个解法的思想基于一个被称为**最大子序列和**的问题，也被称为**最大子数组和**或**最大子段和**。
这是一个在数组中寻找一个连续的子序列，使得这个子序列的和最大。

这个问题的一个经典解法是**卡迪兰（Kadane）算法**。这个算法的基本思想是，对于数组中的每一个元素，我们都试图找出以该元素结尾的最大子序列和。
我们可以通过一个累加的方式来实现这个目标。我们从头开始遍历数组，对于每一个元素，我们都将其加到当前的累加和中。
如果在某一步骤中，累加和变成了负数，那么我们就抛弃之前的所有元素，从当前元素重新开始累加。
这是因为，一个负的累加和再加上任何一个数，其结果都不会比这个数本身更大。

在这个过程中，我们还需要跟踪最大的累加和，以及产生最大累加和的子序列的起始和结束位置。
我们可以通过在每一步骤中检查当前的累加和是否大于最大累加和来实现这个目标。
如果当前的累加和更大，那么我们就更新最大累加和，以及起始和结束位置。

这个算法的时间复杂度是O(n)，其中n是数组的长度。这是因为我们只需要遍历数组一次。
这个算法的空间复杂度是O(1)，因为我们只需要存储几个变量，包括当前的累加和、最大累加和、以及起始和结束位置。

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
