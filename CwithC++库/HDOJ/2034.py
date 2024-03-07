while True:
    n, m, *lst = map(int, input().split()) # 读取集合A和B的元素个数
    if n == 0 and m == 0: # 如果n和m都为0，则结束输入
        break
    A = set(lst[:n]) # 获取集合A的元素
    B = set(lst[n:]) # 获取集合B的元素
    diff = sorted(list(A - B)) # 计算A-B的差集，并排序
    if diff: # 如果差集非空
        print(' '.join(map(str, diff)))
    else: # 如果差集为空
        print('NULL')
