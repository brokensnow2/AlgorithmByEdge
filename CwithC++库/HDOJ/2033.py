n = int(input())  # 读取测试实例的个数
for _ in range(n):
    AH, AM, AS, BH, BM, BS = map(int, input().split())  # 读取时间A和B的时、分、秒

    # 计算秒数，并处理进位
    AS += BS
    AM += AS // 60
    AS %= 60

    # 计算分钟，并处理进位
    AM += BM
    AH += AM // 60
    AM %= 60

    # 计算小时
    AH += BH

    # 输出结果
    print(AH, AM, AS)
