"""
这一次，你被要求说出所有男生的最低成绩和所有女生的最高成绩之间的区别。
输入规范：
每个输入文件包含一个测试用例。每个案例都包含一个正整数N，后面跟着N行学生信息。
每行包含一个学生的姓名、性别、ID和成绩，用空格分隔，其中姓名和ID是不超过10个字符的字符串不包含空格，
性别是F（女性）或M（男性），成绩是0到100之间的整数。保证所有成绩都是不同的。
输出规格：
对于每个测试用例，在3行中输出。第一行给出成绩最高的女生的姓名和身份证，第二行给出成绩最低的男生的姓名和证件。第三行给出了分数差距
如果缺少一个这样的学生，则在相应的行中输出Absent，而在第三行中输出NA。
Sample Input 1:
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
"""

"""
思路：男女分成两组，分别排序
"""
# 获取输入
N = int(input())
# 初始化
males = []
females = []
for _ in range(N):
    name,sex,ID,grade = input().split()
    if sex == 'M':
        males.append([name,ID,grade])
    else:
        females.append([name,ID,grade])
# 排序
males.sort(key=lambda x:int(x[2]))
females.sort(key=lambda x:-int(x[2]))
# 输出
if len(males) >= 1 and len(females) >= 1:
    print(f"{females[0][0]} {females[0][1]}")
    print(f"{males[0][0]} {males[0][1]}")
    print(f"{int(females[0][2]) - int(males[0][2])}")
elif males == [] and females == []:
    print("Absent")
    print("Absent")
    print("NA")
elif males == []:
    print(f"{females[0][0]} {females[0][1]}")
    print("Absent")
    print("NA")
elif females == []:
    print("Absent")
    print(f"{males[0][0]} {males[0][1]}")
    print("NA")