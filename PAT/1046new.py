# 读取输入，N是出口的数量，D是每个出口之间的距离
N, *D = map(int, input().split())
# 在D的开始添加一个0，这样D的下标就可以直接对应出口的编号
D = [0] + D
# 计算从出口1到每个出口的总距离
for i in range(2, N+1):
    D[i] += D[i-1]
# 在D的末尾添加总的环形公路的长度
D.append(D[-1])

# 读取要计算的次数
M = int(input())
# 对于每次计算
for _ in range(M):
    # 读取起点和终点
    origin, to = map(int, input().split())
    # 如果起点大于终点，交换起点和终点
    if origin > to:
        origin, to = to, origin
    # 计算顺时针方向的距离
    sum = D[to-1] - D[origin-1]
    # 打印顺时针方向和逆时针方向距离中的较小值
    # 顺时针方向和逆时针方向距离和是总的环形公路的长度！！
    print(min(sum, D[-1]-sum))

