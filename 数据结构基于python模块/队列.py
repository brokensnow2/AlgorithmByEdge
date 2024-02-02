"""
使用Python的内置数据类型list实现队列。
我们可以使用append()方法添加元素，使用pop(0)方法(时间复杂度O(n))移除元素：
"""
queue = []  # 创建一个空队列
queue.append('a')  # 添加元素'a'
queue.append('b')  # 添加元素'b'
queue.append('c')  # 添加元素'c'
print(queue)  # 输出队列：['a', 'b', 'c']
queue.pop(0)  # 移除队首元素
print(queue)  # 输出队列：['b', 'c']

"""
使用Python的内置模块queue。
queue模块提供了Queue类，可以创建一个先进先出的队列。
我们可以使用put()方法添加元素，使用get()方法移除元素
"""
import queue
q = queue.Queue()  # 创建一个空队列
q.put('a')  # 添加元素'a'
q.put('b')  # 添加元素'b'
q.put('c')  # 添加元素'c'
print(q.queue)  # 输出队列：queue(['a', 'b', 'c'])
q.get()  # 移除队首元素
print(q.queue)  # 输出队列：queue(['b', 'c'])
# 查看队列的第一个元素
first_element = q.queue[0]
print("第一个元素:", first_element)
# 判断队列是否为空
if q.empty():
    print("队列是空的")
else:
    print("队列不为空")

"""
deque 是 Python 标准库中的一个双向队列（double-ended queue）实现。
它允许在队列两端高效地执行添加（append）和弹出（pop）操作，相比于列表（list）来说，在两端进行操作的时间复杂度是 O(1)。
"""
from collections import deque

# 创建一个空的双向队列
my_deque = deque()

# 在队列的右侧添加元素
my_deque.append(1)
my_deque.append(2)
my_deque.append(3)

# 在队列的左侧添加元素
my_deque.appendleft(0)

# 弹出右侧的元素
right_element = my_deque.pop()

# 弹出左侧的元素
left_element = my_deque.popleft()

print(my_deque)  # deque([1, 2])
print(right_element)  # 3
print(left_element)  # 0

"""
旋转（rotate）：
rotate 方法用于将队列中的元素向右循环移动指定数量的步数。如果步数为正数，则向右旋转，如果为负数，则向左旋转。
"""
my_deque = deque([1, 2, 3, 4, 5])
my_deque.rotate(2)

print(my_deque)  # deque([4, 5, 1, 2, 3])