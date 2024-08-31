from functools import cmp_to_key

class People(object):
    def __init__(self, id, virtue, talent) -> None:
        self.id = id
        self.virtue = virtue
        self.talent = talent
        self.totalScore = virtue + talent
"""
在Python的排序中，当使用自定义比较函数时：

返回负数：表示第一个参数（p1）应该排在第二个参数（p2）的前面。
返回正数：表示第二个参数（p2）应该排在第一个参数（p1）的前面。
返回零：表示两者在排序中相等，顺序保持不变。
因此，如果比较函数返回负数，意味着p1的优先级较高，它会被排在p2的前面；而返回正数则意味着p2的优先级较高，它会被排在p1的前面。
"""
def compare(p1: People, p2: People):
    # 比较总分（降序）
    if p1.totalScore != p2.totalScore:
        return p2.totalScore - p1.totalScore
    # 总分相同时比较德分（降序）
    elif p1.virtue != p2.virtue:
        return p2.virtue - p1.virtue
    # 德分相同时比较ID（升序）
    else:
        return p1.id - p2.id

sages = []
noblemen = []
foolmen = []
smallmen = []

N, L, H = map(int, input().split())
for _ in range(N):
    ID_Number, Virtue_Grade, Talent_Grade = map(int, input().split())
    if Virtue_Grade < L or Talent_Grade < L:
        continue
    if Virtue_Grade >= H and Talent_Grade >= H:
        sages.append(People(ID_Number, Virtue_Grade, Talent_Grade))
    elif Virtue_Grade >= H and Talent_Grade < H:
        noblemen.append(People(ID_Number, Virtue_Grade, Talent_Grade))
    elif Virtue_Grade >= Talent_Grade:
        foolmen.append(People(ID_Number, Virtue_Grade, Talent_Grade))
    else:
        smallmen.append(People(ID_Number, Virtue_Grade, Talent_Grade))

# 对每个分类列表进行排序
sages.sort(key=cmp_to_key(compare))
noblemen.sort(key=cmp_to_key(compare))
foolmen.sort(key=cmp_to_key(compare))
smallmen.sort(key=cmp_to_key(compare))

# 输出总数
print(len(sages) + len(noblemen) + len(foolmen) + len(smallmen), end='')

# 输出排序后的每个人的信息
for group in [sages, noblemen, foolmen, smallmen]:
    for person in group:
        print(f"\n{person.id} {person.virtue} {person.talent}", end='')