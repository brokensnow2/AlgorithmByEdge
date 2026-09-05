"""
input:
3 # test count
3 # n
0 2 2 # a
1 # n
2 # a
4 # n
1 1 3 3 # a

output:
YES
NO
YES

题目：问是否存在一个b数组，使得mex[] == a[], mex_i是mex(b1, b2, ..., bi)——即不在集合中的最小非负整数。

解法：
"""

test_cases = int(input())
for _ in range(test_cases):
    n = int(input())
    a = list(map(int, input().split()))
    # 不可能
    if max(a) > n:
        print("NO")
        continue

    # a[0] 只能是 0 或 1
    if a[0] > 1:
        print("NO")
        continue

    # 单调非递减
    ok = True
    for i in range(1, n):
        if a[i] < a[i-1]:
            ok = False
            break
    if not ok:
        print("NO")
        continue

    # 自由选择数 free
    free = 1 if a[0] == 0 else 0
    previous = a[0]
    ok = True

    for current in a[1:]:
        if current == previous:
            free += 1
        else:
            need = current - previous - 1
            if need > free:
                ok = False
                break
            free -= need
            previous = current

    print("YES" if ok else "NO")
