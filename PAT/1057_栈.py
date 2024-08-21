"""
堆栈是最基本的数据结构之一，它基于后进先出（LIFO）原则。
基本操作包括 Push（将元素插入到顶部位置）和 Pop（删除顶部元素）。
现在，您应该通过一个额外的操作实现一个堆栈：PeekMedian -- 返回堆栈中所有元素的中值。

输入规格：
每个输入文件都包含一个测试用例。对于每种情况，第一行都包含一个正整数N (≤10^5).
然后N行，每行都包含以下 3 种格式之一的命令：
Push key
Pop
PeekMedian

输出规格：
对于每个插入到堆栈中的命令，不输出任何内容。
对于其他每个命令，在一行中打印相应的返回值。如果命令无效，请改为打印Invaild。

示例输入：                  示例输出：
17
Pop                         Invaild
PeekMedian                  Invaild
Push 3                       
PeekMedian                  3
Push 2                      
PeekMedian                  2
Push 1
PeekMedian                  2
Pop                         1
Pop                         2
Push 5                      
Push 4                      
PeekMedian                  4
Pop                         4
Pop                         5
Pop                         3
Pop                         Invaild
"""

"""
超时
import bisect  # 导入 bisect 模块，用于维护有序列表的插入和查找操作

class MedianStack:
    def __init__(self):
        # 初始化两个列表，一个用于存储堆栈，一个用于存储有序的元素列表
        self.stack = []
        self.sorted_list = []

    def push(self, x):
        # 将元素 x 推入堆栈
        self.stack.append(x)
        # 使用 bisect.insort 将元素 x 插入到有序列表中以保持有序
        bisect.insort(self.sorted_list, x)

    def pop(self):
        # 如果堆栈为空，返回 "Invalid"
        if not self.stack:
            return "Invalid"
        # 从堆栈顶部弹出元素
        top = self.stack.pop()
        # 使用 bisect.bisect_left 找到该元素在有序列表中的索引位置
        index = bisect.bisect_left(self.sorted_list, top)
        # 从有序列表中移除该元素
        self.sorted_list.pop(index)
        # 返回弹出的元素
        return top

    def peek_median(self):
        # 如果堆栈为空，返回 "Invalid"
        if not self.stack:
            return "Invalid"
        # 计算有序列表的长度
        n = len(self.sorted_list)
        # 计算中值的索引，使用 (n - 1) // 2 确保在堆栈长度为奇数时返回中间值
        median_index = (n - 1) // 2
        # 返回有序列表中的中值元素
        return self.sorted_list[median_index]

# 处理输入和输出
n = int(input())  # 读取命令的数量 N
stack = MedianStack()  # 创建一个 MedianStack 的实例

for _ in range(n):
    # 读取每一行命令并将其拆分为命令和可能的参数
    cmd = input().split()
    if cmd[0] == "Push":
        # 如果命令是 "Push"，将参数转换为整数并执行 push 操作
        stack.push(int(cmd[1]))
    elif cmd[0] == "Pop":
        # 如果命令是 "Pop"，执行 pop 操作并打印结果
        print(stack.pop())
    elif cmd[0] == "PeekMedian":
        # 如果命令是 "PeekMedian"，执行 peek_median 操作并打印结果
        print(stack.peek_median())

"""

import heapq

class MedianStack:
    def __init__(self):
        self.stack = []
        self.min_heap = []  # 最小堆，保存较大的一半
        self.max_heap = []  # 最大堆，保存较小的一半
    
    def push(self, x):
        self.stack.append(x)
        if len(self.max_heap) == 0 or x <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -x)
        else:
            heapq.heappush(self.min_heap, x)
        self._balance_heaps()
    
    def pop(self):
        if not self.stack:
            return "Invalid"
        top = self.stack.pop()
        if top <= -self.max_heap[0]:
            self._remove_from_heap(self.max_heap, -top)
        else:
            self._remove_from_heap(self.min_heap, top)
        self._balance_heaps()
        return top
    
    def peek_median(self):
        if not self.stack:
            return "Invalid"
        return -self.max_heap[0]
    
    def _balance_heaps(self):
        # 保持 max_heap 的大小大于等于 min_heap
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
    
    def _remove_from_heap(self, heap, value):
        index = heap.index(value)  # 找到元素在堆中的位置
        heap[index] = heap[-1]  # 用最后一个元素替换
        heap.pop()  # 删除最后一个元素
        if index < len(heap):
            """
            _siftup（向上调整）：将元素与其父节点比较，如果元素比父节点小（对于最小堆），则交换它们。
            这种操作一直持续到堆顶，确保堆的性质在上升方向上得到维护。

            _siftdown（向下调整）：将元素与其子节点比较，如果元素比子节点大（对于最小堆），则交换它们。
            这种操作一直持续到叶子节点，确保堆的性质在下降方向上得到维护。
            
            """
            heapq._siftup(heap, index)  # type: ignore # 重新调整堆结构
            heapq._siftdown(heap, 0, index) # type: ignore

# 处理输入和输出
n = int(input())
stack = MedianStack()

for _ in range(n):
    cmd = input().split()
    if cmd[0] == "Push":
        stack.push(int(cmd[1]))
    elif cmd[0] == "Pop":
        print(stack.pop())
    elif cmd[0] == "PeekMedian":
        print(stack.peek_median())

