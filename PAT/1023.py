"""
请注意，数字123456789是一个9位数的数字，完全由1到9的数字组成，没有重复。
将其加倍，我们将获得246913578，这恰好是另一个9位数的数字，正好由1到9的数字组成，只是在不同的排列中。如果我们再加倍，请检查一下结果！
现在，假设您检查此属性是否有更多的数字。也就是说，用k个数字将给定的数字加倍，你要判断得到的数字是否只由原始数字中的数字排列组成。
输入规范：
每个输入包含一个测试用例。每个大小写包含一个不超过20位的正整数。
输出规格：
对于每个测试用例，如果加倍输入数字得到的数字仅由原始数字中的数字排列组成，则首先打印一行“是”，否则打印“否”。
然后在下一行中，打印加倍的数字。
"""
from collections import defaultdict

num_str = input()
num2_str = str(int(num_str)*2)
char_count = defaultdict(int)
for char in num_str:
    char_count[char] += 1
char_count2 = defaultdict(int)
for char in num2_str:
    char_count2[char] += 1
if char_count == char_count2:
    print("Yes")
else:
    print("No")
print(num2_str)