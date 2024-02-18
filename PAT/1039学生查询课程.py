"""
浙江大学有40000名学生，提供2500门课程。现在，给定所有课程的学生姓名列表，您应该为每个前来查询的学生输出注册的课程列表。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含2个正整数：N（≤40000），查找课程列表的学生人数，K（≤2500），课程总数。
然后，课程（编号从1到K）的学生名单按以下格式给出：对于每门课程i，首先是课程索引i和注册学生人数Ni（≤200）在一行中给出。
然后在下一行中，给出了学生的名字。学生姓名由3个英文大写字母加一个数字组成。最后，最后一行包含前来查询的学生的N个姓名。
一行中的所有名称和数字都用空格分隔。
输出规格：
对于每个测试用例，将结果打印成N行。每一行对应一名学生，格式如下：首先打印学生的姓名，然后打印该学生的注册课程总数，最后按升序打印课程索引。
查询结果必须按与输入相同的顺序打印。一行中的所有数据都必须用空格分隔，行的末尾不能有多余的空格。
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
"""

"""
思路：如何正确的处理输入
    数据使用字典存储
"""
# 查询人数，课程数
N,C = map(int,input().split())
# query
query = []
# 字典
from collections import defaultdict
stuCourses = defaultdict(list)

# 最多输入：课程数*2+1行
for i in range(2*C):
    # 是连续两行的前一行
    if i%2 == 0:
        # 如果输入数据是课程索引i和注册学生人数Ni
        temp = input().split()
        if temp[0].isdigit():
            pass
        # 是最后一行查询数据，因为有课程没输入
        else:
            query = temp
            break
    # 是连续两行的后一行：课程的人员
    else:
        stus = input().split()
        for i in stus:
            stuCourses[i].append(temp[0])
# 如果for循环执行完了，说明执行了课程数*2次
# 这次是最后一行查询数据
else:
    query = input().split()

# 输出
for i in query:
    course  = sorted(stuCourses[i])
    length = len(course)
    if length != 0:
        print(f"{i} {length} {' '.join(course)}")
    else:
        print(f"{i} 0")
