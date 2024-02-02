"""
伊娃想用她最喜欢的颜色做一串珠子，所以她去一家小店买了一些珠子。有许多五颜六色的珠子串。
然而，这家商店的老板只会出售整串的绳子。因此，伊娃必须检查商店里的绳子是否包含了她需要的所有珠子。
她现在向你寻求帮助：如果答案是肯定的，请告诉她她必须额外购买的珠子数量；或者如果答案是否定的，请告诉她绳子上少了多少珠子。
为了简单起见，让我们使用[0-9]、[a-z]和[A-Z]范围内的字符来表示颜色。
输入规范：
每个输入文件包含一个测试用例。每个测试用例输入分为两行，一串不超过1000颗的珠子分别属于店主和伊娃。
输出规格：
对于每个测试用例，将答案打印在一行中。如果答案是肯定的，那么还输出伊娃必须购买的额外珠子的数量；
或者如果答案是“否”，那么也输出字符串中缺少的珠子的数量。答案和数字之间必须正好有1个空格。
"""
# 店主的字符串
owner = input()
# Eve的字符串
Eve = input()

# 两个标志
lack = 0
flag = 0

from collections import defaultdict
owner_dict = defaultdict(int)
Eve_dict = defaultdict(int)
# 对字符计数
# Eve:
for i in Eve:
    Eve_dict[i] += 1
# owner:
for i in owner:
    owner_dict[i] += 1
count = 0
for i in Eve_dict:
    if Eve_dict[i] <= owner_dict[i]:
        flag += 1
        count += 1
    else:
        lack += Eve_dict[i] - owner_dict[i]
        count += 1
if flag == count:
    print(f"Yes {len(owner)-len(Eve)}")
else:
    print(f"No {lack}")
