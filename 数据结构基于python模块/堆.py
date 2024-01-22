"""
堆的实现：堆是用普通的列表实现的。尽管堆是完全二叉树，但是我们可以用列表来表示它，
因为堆的结构使得我们可以通过索引来找到任何节点的父节点或子节点。
例如，如果一个元素在列表中的索引是i，那么它的左子节点的索引就是2*i+1，右子节点的索引就是2*i+2，父节点的索引就是(i-1)//2。

优先队列是一种抽象数据类型，它类似于队列，每个元素都有一定的优先级。
优先队列中的元素按优先级进行排序，优先级最高的元素最先出队。
优先队列通常可以用堆来实现，因为堆是一种能够高效地插入元素和删除最小（或最大）元素的数据结构。

在Python中，heapq模块提供了堆的实现，它使用了一种特殊的树形数据结构，这种结构可以用列表来表示。
heapq模块中的函数可以在列表上操作，使其具有堆的性质，例如heapq.heappush()可以将元素添加到堆中，
heapq.heappop()可以从堆中弹出最小的元素。

所以，可以使用Python的heapq模块和列表来实现优先队列。
"""

# heapify(list)：此函数将列表转换为堆，以便我们可以在其上执行堆操作。


import heapq
nums = [3, 1, 4, 1, 5, 9, 2, 6]
heapq.heapify(nums)
print(nums)  # 输出：[1, 1, 2, 3, 5, 9, 4, 6]

# heappush(heap, item)：此函数将元素添加到堆中，同时保持堆的属性。
heapq.heappush(nums, 0)
print(nums)  # 输出：[0, 1, 1, 3, 2, 9, 4, 6, 5]

# heappop(heap)：此函数从堆中删除并返回最小的元素。
print(heapq.heappop(nums))  # 输出：0
print(nums)  # 输出：[1, 2, 1, 3, 5, 9, 4, 6]

# heappushpop(heap, item)：此函数将元素推入堆中，然后弹出并返回堆中的最小元素。
print(heapq.heappushpop(nums, 0))  # 输出：0
print(nums)  # 输出：[1, 2, 1, 3, 5, 9, 4, 6]

# heapreplace(heap, item)：此函数首先弹出并返回堆中的最小元素，然后将新元素推入堆中。
print(heapq.heapreplace(nums, 0))  # 输出：1
print(nums)  # 输出：[0, 2, 1, 3, 5, 9, 4, 6]

# nlargest(n, iterable[, key]) 和 nsmallest(n, iterable[, key])：这两个函数分别返回可迭代对象中的n个最大和最小元素。
print(heapq.nlargest(3, nums))  # 输出：[9, 6, 5]
print(heapq.nsmallest(3, nums))  # 输出：[0, 1, 1]


