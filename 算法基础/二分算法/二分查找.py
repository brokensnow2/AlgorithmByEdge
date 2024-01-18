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
    

array = [1,2,3,4,5,6,7,8]
print(f"Index is {findValueIndex(array=array,value=5)}")
# print(11/2) # 5.5自动转浮点
# print(int(11/2)) # 5