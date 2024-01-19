def Partition(array :list, left :int, right :int):
    pivot = array[left]
    while left < right:
        while pivot <= array[right] and left < right:
            right -= 1
        array[left] = array[right]
        while pivot >= array[left] and left < right:
            left += 1
        array[right] = array[left]
    array[left] = pivot
    return left

def QuickSort(array :list, left :int, right :int):
    if left < right:
        pivotPos = Partition(array,left,right)
        QuickSort(array,left,pivotPos-1)
        QuickSort(array,pivotPos+1,right)


array = list(map(int,input().split()))
QuickSort(array,0,len(array)-1)
print(array)