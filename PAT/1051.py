"""
解决方案的工作原理是模拟栈的操作。对于给定的弹出序列，我们尝试将数字按顺序压入栈中，直到栈顶的数字等于弹出序列的当前数字。
然后我们弹出栈顶的数字，并继续处理弹出序列的下一个数字。
如果在任何时候栈的大小超过了M，或者栈顶的数字不等于弹出序列的当前数字，我们就返回"NO"。
如果我们成功地处理了整个弹出序列，我们就返回"YES"。
"""

def check_pop_sequence(M, N, seq):
    stack = []
    current = 0
    for num in seq:
        # 出栈的元素大于还没进栈的话
        while current < num:
            current += 1
            # 进栈
            stack.append(current)
            # 栈的大小超过了M
            if len(stack) > M:
                return "NO"
        if stack[-1] == num:
            stack.pop()
        else:
            return "NO"
    return "YES" if not stack else "NO"

# M:栈的大小, N:测试序列长度, K: 测试个数
M,N,K = map(int,input().split())
sequences = []
for _ in range(K):
    sequences.append(list(map(int,input().split())))


for seq in sequences:
    print(check_pop_sequence(M, N, seq))