"""

"""
class Student:
    def __init__(self, id, score, loc_num):
        self.id = id  # 学生的注册号
        self.score = score  # 学生的总分
        self.final_rank = 0  # 学生的最终排名
        self.loc_num = loc_num  # 学生的测试位置编号
        self.loc_rank = 0  # 学生的本地排名

def cmp(student):
    return (-student.score, student.id)  # 按照分数降序和注册号升序排序

N = int(input())  # 读取测试位置的数量
students = []  # 初始化学生列表
loc_start = [0] * (N + 1)  # 初始化每个测试位置的起始索引
for i in range(N):  # 对于每个测试位置
    n = int(input())  # 读取测试对象的数量
    loc_start[i+1] = loc_start[i] + n  # 更新下一个测试位置的起始索引
    for _ in range(n):  # 对于每个测试对象
        id, score = map(int, input().split())  # 读取注册号和总分
        students.append(Student(id, score, i+1))  # 将学生添加到列表中
students.sort(key=cmp)  # 对所有学生进行排序
students[0].final_rank = 1  # 第一个学生的最终排名为1
for i in range(1, len(students)):  # 对于剩下的学生
    if students[i].score == students[i-1].score:  # 如果分数相同
        students[i].final_rank = students[i-1].final_rank  # 则最终排名也相同
    else:  # 否则
        students[i].final_rank = i + 1  # 最终排名为索引加1
for i in range(N):  # 对于每个测试位置
    stus_loc = [j for j in students if j.loc_num == i+1]
    stus_loc.sort(key=cmp)  # 对本地的学生进行排序
    stus_loc[0].loc_rank = 1  # 第一个学生的本地排名为1
    for j in range(1,len(stus_loc)):  # 对于剩下的学生
        if stus_loc[j].score == stus_loc[j-1].score:  # 如果分数相同
            stus_loc[j].loc_rank = stus_loc[j-1].loc_rank  # 则本地排名也相同
        else:  # 否则
            stus_loc[j].loc_rank = j+1  # 本地排名为该学生的编号+1，即人数
print(len(students))  # 打印学生的总数
for student in students:  # 对于每个学生
    print(student.id, student.final_rank, student.loc_num, student.loc_rank)  # 打印学生的信息

