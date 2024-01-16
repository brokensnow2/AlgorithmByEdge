"""
exp函数使用input().split()读取一行输入并将其分割成一个字符串列表。
然后，exp函数定义了一个名为helper的内部函数，该函数接受一个迭代器作为参数。
helper函数从迭代器中获取下一个元素，并根据该元素是运算符还是数字来决定下一步的操作。
如果元素是运算符，helper函数会递归地调用自身两次来获取操作数，并执行相应的运算。
如果元素是数字，helper函数会将其转换为浮点数并返回。最后，exp函数调用helper函数并打印出返回的结果。
"""
def exp():
    s = input().split()
    def helper(it):
        token = next(it)
        if token in '+-*/':
            op1, op2 = helper(it), helper(it)
            if token == '+': return op1 + op2
            if token == '-': return op1 - op2
            if token == '*': return op1 * op2
            if token == '/': return op1 / op2
        else:
            return float(token)
    return helper(iter(s))

print(exp())
"""
流程：exp() -->  s = input().split() --> return helper(iter(s)) -->  token = next(it) --> if token in '+-*/': --> ...
"""
