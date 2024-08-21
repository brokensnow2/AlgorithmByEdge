"""
def process_queries(people, queries):
    results = []  # 用于存储所有查询的结果
    
    for i, (M, Amin, Amax) in enumerate(queries):
        # 过滤出年龄在 [Amin, Amax] 范围内的所有人
        filtered = [p for p in people if Amin <= p['age'] <= Amax]
        
        # 按照净资产（降序），年龄（升序），名字（字母顺序）进行排序
        filtered.sort(key=lambda x: (-x['net_worth'], x['age'], x['name']))
        
        # 准备当前查询的输出
        result = [f"Case #{i + 1}:"]  # 输出的第一行是 "Case #X:"
        if filtered:
            # 如果有满足条件的人，输出最多 M 个
            result.extend([f"{p['name']} {p['age']} {p['net_worth']}" for p in filtered[:M]])
        else:
            # 如果没有满足条件的人，输出 "None"
            result.append("None")
        
        results.append("\n".join(result))  # 将当前查询结果加入到总结果中
    
    return "\n".join(results)  # 返回所有查询结果，查询之间用空行分隔

# 读取输入数据
def read_input():
    N, K = map(int, input().split())  # 读取 N 和 K
    
    people = []  # 存储所有人的信息
    for _ in range(N):
        name, age, net_worth = input().split()  # 读取每个人的姓名、年龄和净资产
        age = int(age)  # 将年龄转为整数
        net_worth = int(net_worth)  # 将净资产转为整数
        people.append({"name": name, "age": age, "net_worth": net_worth})  # 以字典形式存储到 people 列表中
    
    queries = []  # 存储所有查询
    for _ in range(K):
        M, Amin, Amax = map(int, input().split())  # 读取每个查询的 M, Amin, Amax
        queries.append((M, Amin, Amax))  # 将查询添加到 queries 列表中
    
    return people, queries  # 返回所有人信息和查询

# 主函数执行解决方案
def main():
    people, queries = read_input()  # 读取输入
    output = process_queries(people, queries)  # 处理查询
    print(output)  # 输出结果

# 如果当前脚本作为主程序运行，则执行 main 函数
if __name__ == "__main__":
    main()
"""



###还是超时：排序的时间复杂度为 O(N log N)，每个查询的时间复杂度为 O(N)
from bisect import bisect_left, bisect_right

def process_queries(people, queries):
    # 先按照净资产（降序）、年龄（升序）、姓名（字母顺序）排序
    people.sort(key=lambda x: (-x['net_worth'], x['age'], x['name']))
    
    results = []  # 用于存储所有查询的结果
    
    for i, (M, Amin, Amax) in enumerate(queries):
        # 找到符合年龄范围的人的索引范围
        # 因为 people 是按 net_worth 排序的，我们只需要比较年龄
        
        filtered = []
        for person in people:
            if Amin <= person['age'] <= Amax:
                filtered.append(person)
            if len(filtered) == M:
                break
            

        # 准备当前查询的输出
        result = [f"Case #{i + 1}:"]
        if filtered:
            result.extend([f"{p['name']} {p['age']} {p['net_worth']}" for p in filtered])
        else:
            result.append("None")
        
        results.append("\n".join(result))
    
    return "\n".join(results)

# 读取输入数据
def read_input():
    N, K = map(int, input().split())  # 读取 N 和 K
    
    people = []  # 存储所有人的信息
    for _ in range(N):
        name, age, net_worth = input().split()  # 读取每个人的姓名、年龄和净资产
        age = int(age)  # 将年龄转为整数
        net_worth = int(net_worth)  # 将净资产转为整数
        people.append({"name": name, "age": age, "net_worth": net_worth})  # 以字典形式存储到 people 列表中
    
    queries = []  # 存储所有查询
    for _ in range(K):
        M, Amin, Amax = map(int, input().split())  # 读取每个查询的 M, Amin, Amax
        queries.append((M, Amin, Amax))  # 将查询添加到 queries 列表中
    
    return people, queries  # 返回所有人信息和查询

# 主函数执行解决方案
def main():
    people, queries = read_input()  # 读取输入
    output = process_queries(people, queries)  # 处理查询
    print(output)  # 输出结果

# 如果当前脚本作为主程序运行，则执行 main 函数
if __name__ == "__main__":
    main()


