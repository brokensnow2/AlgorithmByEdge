def print_u_shape(s):
    N = len(s)
    n1 = n3 = (N + 2) // 3 - 1
    n2 = N - n1 - n3
    for i in range(n1):
        print(s[i] + ' ' * (n2 - 2) + s[N - i - 1])
    print(s[n1:N - n1])

# 测试代码
print_u_shape(input())
