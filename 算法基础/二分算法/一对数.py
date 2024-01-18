"""
输入n(n<= 100,000)个整数，找出其中的两个数，它们之和等于整数m(假定
肯定有解)。题中所有整数都能用int表示(n个数各不相同)
解法2:
1) 将数组排序，复杂度是0(n * log(n))
2)对数组中的每个元素a[i],在数组中二分查找m-a[i]，看能否找到。复杂度log(n)
查找n次，所以 查找这部分的复杂度也是0(n * log(n))

这种解法总的复杂度是0(n * log(n))的。
"""
M = 100
def findValueIndex(array :list,value :int):
    if not len(array):
        return -1
    else:
        i = 0
        j = len(array)-1
        while i<j:
            mid = int((i + j)/2) # int()
            if array[mid] == value:
                return mid
            elif array[mid] < value:
                i = mid + 1
            else:
                j = mid -1
        return -1
    

str_num = input().split()
array = list(map(int, str_num))
array.sort()
for i in range(len(array)):
    j = M - array[i]
    index = findValueIndex(array,j)
    if index != -1:
        print(f"find it! {array[i]} and {array[index]}")
        break
    else:
        pass
