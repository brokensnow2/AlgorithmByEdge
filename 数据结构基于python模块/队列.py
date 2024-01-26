"""
使用Python的内置数据类型list实现队列。
我们可以使用append()方法添加元素，使用pop(0)方法移除元素：
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

