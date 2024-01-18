def merge_sort(lst):
    if len(lst) <= 1:
        return lst

    mid = len(lst) // 2
    left = merge_sort(lst[:mid]) # lst[:mid]这种操作会创建一个新的列表，这个新列表是原列表的一部分的副本。
    right = merge_sort(lst[mid:])

    return merge(left, right)

def merge(left, right):
    merged = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1

    merged.extend(left[left_index:])
    merged.extend(right[right_index:])

    return merged

# 测试
lst = [5, 3, 1, 4, 6, 2, 2, 10]
print(merge_sort(lst))  # 输出：[1, 2, 2, 3, 4, 5, 6, 10]
