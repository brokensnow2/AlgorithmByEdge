"""
这次，你要找出 A×B，其中 A 和 B 是两个多项式。

输入规格：
每个输入文件包含一个测试用例。 每个案例占 2 行，每行包含一个多项式的信息：
K N1 aN1 N2 aN2 N3 aN3 ... Nk aNk
K是多项式中非零项的个数，
Ni aNi 是指数和系数
1≤K≤10, 0≤NK<⋯<N2<N1z≤1000.  
输出规格：
对于每个测试用例，应在一行中输出 A 和 B 的乘积，格式与输入相同。  
请注意，每行末尾不得有多余的空格。  请精确到小数点后 1 位。

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6

"""
from collections import defaultdict

# 读取多项式1
k1, *ploy1 = map(float, input().split())
index1 = int(k1) * 2

# 读取多项式2
k2, *ploy2 = map(float, input().split())
index2 = int(k2) * 2

# 结果多项式，用字典存储
ans = defaultdict(float)

# 计算乘积
for i in range(0, index1, 2):
    for j in range(0, index2, 2):
        exponent = int(ploy1[i] + ploy2[j])
        coefficient = ploy1[i + 1] * ploy2[j + 1]
        ans[exponent] += coefficient

# 删除系数为0的项
ans = {k: v for k, v in ans.items() if v != 0}

# 按指数从大到小排序
sorted_ans = sorted(ans.items(), key=lambda x: -x[0])
"""
在 Python 中，虽然字典本身是无序的，但你可以对字典的 `items()` 进行排序。`items()` 方法返回一个包含字典键值对的视图对象，形式为 `(key, value)` 的元组列表。你可以使用 `sorted()` 函数对这个列表进行排序。

具体来说，`sorted(ans.items(), key=lambda x: -x[0])` 是在对字典 `ans` 的键值对进行排序：

1. **`ans.items()`**：返回字典 `ans` 中所有键值对的视图，结果是一个包含 `(key, value)` 形式的元组列表。例如，如果 `ans` 是 `{3: 3.6, 2: 6.0, 1: 1.6}`，则 `ans.items()` 返回 `[(3, 3.6), (2, 6.0), (1, 1.6)]`。

2. **`sorted(ans.items(), key=lambda x: -x[0])`**：
   - `key=lambda x: -x[0]`：这是一个匿名函数，用于指定排序的关键字。`x` 是元组 `(key, value)`，`x[0]` 是键。因此，`-x[0]` 表示按照键的负值进行排序，这意味着排序是按照键从大到小进行的。
   - `sorted()` 函数按照指定的关键字对列表进行排序，并返回一个新的列表。对于 `ans.items()` 返回的列表来说，`sorted()` 会生成一个按键从大到小排序的新列表。

3. **排序后的结果**：`sorted()` 返回的是一个排序后的元组列表。你可以根据需要将其转换为其他数据结构（如字典），或者直接遍历和输出。

### 示例代码
```python
ans = {3: 3.6, 2: 6.0, 1: 1.6}
sorted_ans = sorted(ans.items(), key=lambda x: -x[0])
print(sorted_ans)
```

### 输出结果
```python
[(3, 3.6), (2, 6.0), (1, 1.6)]
```

这个列表是按键从大到小排序的。通过这种方法，你可以对字典进行排序并保持排序结果以满足你的需要。
"""



# 输出结果
print(len(sorted_ans), end='')
for exponent, coefficient in sorted_ans:
    print(f" {exponent} {coefficient:.1f}", end='')
print()  # 确保换行
