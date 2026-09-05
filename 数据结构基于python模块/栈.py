"""
在Python中，可以使用内置的列表类型来实现栈。
列表提供了添加和删除元素的方法，这些方法可以用来实现栈的"push"和"pop"操作。以下是一个简单的栈实现：
"""
# 创建一个空栈
stack = []

# 添加元素到栈顶（push操作）
stack.append('a')
stack.append('b')
stack.append('c')

print("Initial stack: ", stack)

# 从栈顶移除元素（pop操作）
print("Elements popped from stack:")
print(stack.pop())
print(stack.pop())

print("Stack after elements are popped: ", stack)

def nextSmallerElement(nums):
    """
    找出数组中每个元素的下一个更小值
    
    算法思路：使用单调递增栈
    - 栈中存储的是数组的下标
    - 栈从底到顶对应的值是单调递增的
    - 当遇到比栈顶值更小的元素时，就可以确定栈顶元素的答案
    
    时间复杂度：O(n)，每个元素最多入栈出栈一次
    空间复杂度：O(n)，栈最多存储n个元素
    """
    n = len(nums)
    ans = [-1] * n        # 初始化答案数组，默认值为-1表示找不到下一个更小值
    stack = []            # 单调递增栈，存储下标，栈内从底到顶值递增
    
    for i in range(n):
        # 当栈不为空，且当前值小于栈顶下标对应的值时
        while stack and nums[i] < nums[stack[-1]]:
            j = stack.pop()              # 弹出栈顶下标
            ans[j] = nums[i]             # 当前值就是j的下一个更小值
        stack.append(i)                 # 将当前下标压入栈
    
    return ans  # 返回答案数组

nums = list(map(int, input().split()))
print(nextSmallerElement(nums))


def dailyTemperatures(temperatures):
    """
    每日温度问题：对于每一天，找出需要等待多少天才能遇到更高的温度
    
    算法思路：使用单调递减栈
    - 栈中存储的是温度数组的下标
    - 栈从底到顶对应的温度值是单调递减的
    - 当遇到比栈顶温度更高的温度时，就可以确定栈顶元素的答案
    
    时间复杂度：O(n)，每个元素最多入栈出栈一次
    空间复杂度：O(n)，栈最多存储n个元素
    """
    n = len(temperatures)
    ans = [0] * n  # 初始化答案数组，默认值为0表示没有更高温度
    stack = []     # 单调递减栈，存储下标
    
    for i in range(n):
        # 当栈不为空，且当前温度大于栈顶下标对应的温度时
        while stack and temperatures[i] > temperatures[stack[-1]]:
            j = stack.pop()           # 弹出栈顶下标
            ans[j] = i - j            # 计算等待天数：当前下标减去栈顶下标
        stack.append(i)               # 将当前下标压入栈
    
    return ans  # 返回答案数组

nums = list(map(int, input().split()))
print(dailyTemperatures(nums))
