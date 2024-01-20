# 读取学生数量N和课程数量K
N, K = map(int, input().split())

# 创建一个列表courses，其中每个元素都是一个空列表
# 这些空列表用于存储注册了相应课程的学生的名字
courses = [[] for _ in range(K+1)]

# 对于每个学生
for _ in range(N):
    # 读取学生的数据，包括他们的名字和他们注册的课程编号
    data = input().split()
    name, course_numbers = data[0], data[2:]
    
    # 对于每个学生注册的课程
    for course in course_numbers:
        # 将学生的名字添加到该课程的列表中
        courses[int(course)].append(name)

# 对于每个课程
for i in range(1, K+1):
    # 打印课程编号和注册学生数量
    print(f"{i} {len(courses[i])}")
    
    # 打印按字母顺序排序的学生名字列表
    for name in sorted(courses[i]):
        print(name)
