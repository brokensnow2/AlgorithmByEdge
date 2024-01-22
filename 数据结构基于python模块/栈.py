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
