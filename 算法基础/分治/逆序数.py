"""
例题:求排列的逆序数
考虑1,2,.,n (n <= 100000)的排列i，i2，...，in，如果其中存在j,k，满足
j < k且ij> ik， 那么就称(ij, ik)是这个排列的一个逆序。
一个排列含有逆序的个数称为这个排列的逆序数。例如排列263451 含有8个
逆序(2, 1), (6,3), (6,4), (6,5), (6,1), (3, 1), (4,1), (5, 1)，因此该排列的逆
序数就是8。

输入
第一行是一个整数n，表示该排列有n个数（n <= 100000)。
第二行是n个不同的正整数，之间以空格隔开，表示该排列。
输出
输出该排列的逆序数。
样例输入
6
2 6 3 4 5 1
样例输出
8
"""
def count_inversions(arr):
    # 如果数组只有一个元素，那么逆序数为0
    if len(arr) == 1:
        return arr, 0
    else:
        n = len(arr)
        # 将数组分为左右两部分
        left = arr[:n//2]
        right = arr[n//2:]
        # 递归计算左右两部分的逆序数
        left, inv_left = count_inversions(left)
        right, inv_right = count_inversions(right)
        # 合并两个已排序的部分并计算逆序数
        merged, inv_merge = merge_count(left, right)
        # 返回排序后的数组和逆序数的总和
        return merged, inv_left + inv_right + inv_merge

def merge_count(left, right):
    # 初始化索引和逆序数计数器
    i = j = inv_count = 0
    merged = []
    # 当左右两部分都有元素时
    while i < len(left) and j < len(right):
        # 如果左边的元素小于或等于右边的元素
        if left[i] <= right[j]:
            # 将左边的元素添加到合并的数组中
            merged.append(left[i])
            i += 1
        else:
            # 否则，将右边的元素添加到合并的数组中，并增加逆序数
            merged.append(right[j])
            j += 1
            inv_count += len(left) - i
    # 将剩余的元素添加到合并的数组中
    merged += left[i:]
    merged += right[j:]
    # 返回合并的数组和逆序数
    return merged, inv_count

# 测试样例
n= input()
arr = list(map(int,input().split()))
# 计算逆序数
arr, inversions = count_inversions(arr)
# 打印逆序数
print(inversions)

