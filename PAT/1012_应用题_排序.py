from statistics import mean

# 找到最好学科的下标
def findBestSubjectIndex(array):
    bestRank = min(array)
    index = array.index(bestRank)
    return bestRank,index

# 计算平均成绩
def avgGrage(lst):
    # s = sum(lst)/len(lst)
    s = mean(lst)
    return s


def rank_students(students :list, check_ids :list):
    # 为了优先级
    subjects = ['A', 'C', 'M', 'E']
    # {123456:[0,0,0,0],234567:[0,0,0,0]}
    ranks = {id[0]: [0]*4 for id in students} 
     # {123456： [best_rank, best_subject_index]}
    bests = {id[0]: [101, 0] for id in students} 
    """
    students.sort(key=lambda x: x[1], reverse=True)是在Python中对students列表进行降序排序。
    这里使用了Python的sort()函数，它可以对列表中的元素进行排序。
    key=lambda x: x[1]是sort()函数的一个参数，它决定了排序的规则。
    lambda是Python中创建匿名函数的关键字，x是这个匿名函数的参数，代表students列表中的一个元素（在这个例子中，x是一个包含学生信息的列表）。
    x[1]是列表x的第二个元素，这个元素被用作排序的键。也就是说，students列表会按照每个子列表的第二个元素进行排序。
    reverse=True是sort()函数的另一个参数，它决定了排序的顺序。如果reverse的值为True，那么sort()函数会按照降序（从大到小）进行排序。
    总的来说，students.sort(key=lambda x: x[1], reverse=True)的意思是：对students列表进行排序，排序的规则是按照每个子列表的第二个元素进行降序排序
    """

    """
    如果使用sorted函数：
    sorted(students,key=lambda x: x[1],reverse=True)
    但它不会改变原来列表，所以不用
    """
    # 对C排序
    rank = 1
    last_score = None
    students.sort(key=lambda x: x[1], reverse=True)
    for i in students:
        # 如果当前学生的成绩与前一个学生的成绩相同，那么他们的排名也应该相同
        if last_score is not None and i[1] == last_score:
            # C Grade's rank is ranks[i[0]][1]
            ranks[i[0]][1] = ranks[last_id][1]
        else:
            ranks[i[0]][1] = rank
            rank += 1
        last_score = i[1]
        last_id = i[0]


    # 对M排序
    rank = 1
    last_score = None
    students.sort(key=lambda x: x[2], reverse=True)
    for i in students:
        # 如果当前学生的成绩与前一个学生的成绩相同，那么他们的排名也应该相同
        if last_score is not None and i[2] == last_score:
            ranks[i[0]][2] = ranks[last_id][2]
        else:
            ranks[i[0]][2] = rank
            rank += 1
        last_score = i[2]
        last_id = i[0]

    # 对E排序
    rank = 1
    last_score = None
    students.sort(key=lambda x: x[3], reverse=True)
    for i in students:
        # 如果当前学生的成绩与前一个学生的成绩相同，那么他们的排名也应该相同
        if last_score is not None and i[3] == last_score:
            ranks[i[0]][3] = ranks[last_id][3]
        else:
            ranks[i[0]][3] = rank
            rank += 1
        last_score = i[3]
        last_id = i[0]

    # 对A排序
    rank = 1
    last_score = None
    students.sort(key=lambda x: x[4], reverse=True)
    for i in students:
        # 如果当前学生的成绩与前一个学生的成绩相同，那么他们的排名也应该相同
        if last_score is not None and i[4] == last_score:
            ranks[i[0]][0] = ranks[last_id][0]
        else:
            ranks[i[0]][0] = rank
            rank += 1
        last_score = i[4]
        last_id = i[0]
    
    # 找到最好排名
    for i in ranks:
        bests[i][0], bests[i][1]= findBestSubjectIndex(ranks[i])
    
    # 打印
    for id in check_ids:
        if id in bests:
            print(f"{bests[id][0]} {subjects[bests[id][1]]}")
        else:
            print("N/A")



n_and_m = input().split()
n_and_m = list(map(int,n_and_m))
students = []
checkID = []
for i in range(n_and_m[0]):
    # students = [ [123456,88,88,88],[123321,99,99,99] ...]
    students.append(list(map(int,input().split())))
for i in range(n_and_m[1]):
    # checkID = [123456,123321,...]
    checkID.append(int(input()))
for i in students:
    # students = [ [123456,88,88,88,88],[123321,99,99,99,99] ...]
    i.append(avgGrage(i[1:]))
rank_students(students,checkID)
