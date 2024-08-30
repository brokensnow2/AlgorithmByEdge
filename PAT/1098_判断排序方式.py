"""
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. 
Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, 
and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, 
and it iteratively shrinks the unsorted region by extracting the largest element and 
moving that to the sorted region. 
it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, 
together with a sequence which is a result of several iterations of some sorting method, 
can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, 
the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. 
The last line contains the partially sorted sequence of the N numbers. 
It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" 
to indicate the method used to obtain the partial result. 
Then run this method for one more iteration and output in the second line the resulting sequence. 
It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, 
and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
"""

# 判断是否为插入排序
def is_insertion_sort(array, sorted_array):
    i = 0
    # 检查排序数组的元素是否按升序排列
    while i < len(array) - 1 and sorted_array[i] <= sorted_array[i+1]:
        i += 1
    # 如果原数组的剩余部分与排序数组的剩余部分相同，则为插入排序
    return array[i+1:] == sorted_array[i+1:]

# 执行插入排序的下一步
def next_insertion_sort(array, sorted_array):
    i = 0
    # 找到排序数组中第一个降序的元素
    while i < len(array) - 1 and sorted_array[i] <= sorted_array[i+1]:
        i += 1
    temp = sorted_array[i+1]
    # 将元素插入到正确的位置
    while i >= 0 and sorted_array[i] > temp:
        sorted_array[i+1] = sorted_array[i]
        i -= 1
    sorted_array[i+1] = temp
    # 返回排序后的数组
    return sorted_array

# 执行堆排序的下一步
def next_heap_sort(array, sorted_array):
    i = len(array) - 1
    # 找到堆中最后一个元素
    while i > 0 and sorted_array[i] >= sorted_array[0]:
        i -= 1
    # 将堆顶元素与最后一个元素交换
    sorted_array[0], sorted_array[i] = sorted_array[i], sorted_array[0]
    j, temp = 0, sorted_array[0]
    # 调整堆:0到i-1的堆
    while j*2+1 < i:
        child = j*2+1
        if child != i-1 and sorted_array[child] < sorted_array[child+1]:
            child += 1
        if sorted_array[child] <= temp:
            break
        sorted_array[j] = sorted_array[child]
        j = child
    sorted_array[j] = temp
    # 返回排序后的数组
    return sorted_array


N = int(input())
array = list(map(int, input().split()))
sorted_array = list(map(int, input().split()))
# 判断给定的部分排序序列是插入排序还是堆排序
if is_insertion_sort(array, sorted_array):
    print("Insertion Sort")
    # 如果是插入排序，执行下一步并打印结果
    print(" ".join(map(str, next_insertion_sort(array, sorted_array))))
else:
    print("Heap Sort")
    # 如果是堆排序，执行下一步并打印结果
    print(" ".join(map(str, next_heap_sort(array, sorted_array))))




