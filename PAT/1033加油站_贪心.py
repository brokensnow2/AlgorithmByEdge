"""
有了高速公路，开车从杭州到任何其他城市都很容易。但由于汽车的油箱容量有限，我们不得不不时在路上找到加油站。不同的加油站可能会给出不同的价格。你被要求仔细设计最便宜的路线。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含4个正数:C（≤100），储罐的最大容量:D（≤30000），杭州到目的地城市的距离；
Davg（≤20），汽车每单位汽油可行驶的平均距离；以及N（≤500），即加油站的总数。
接下来是N行，每行包含一对非负数：Pi，单位天然气价格，
和Di（≤D），此站与杭州之间的距离，
当i=1，…，N时。一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，在一行中打印最便宜的价格，精确到小数点后2位。假设储罐一开始是空的。
如果无法到达目的地，请打印最大行驶距离=X，其中X是汽车可能行驶的最大距离，精确到小数点后2位。
Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
"""

"""
贪心算法:
首先，我们需要将所有的加油站按照距离离杭州由近到远进行排序。
然后，我们从起点（加油站到杭州距离为0）开始，判断下一个加油站(能到达的)是否是比当前的加油站更便宜，
如果是就加当前位置到下一个加油站相差路径的那么多油减去油箱还剩的油，
不然如果下一个加油站(能到达的)比当前的加油站更贵，判断下下个加油站(能到达的)是否是比当前的加油站更便宜，
是就加当前位置到下下一个加油站相差路径的那么多油减去油箱还剩的油，
如果找不到比当前更便宜的，就找能到达的加油站（PS：能到达的距离是指当前距离加上C*Davg）相对便宜的，开到那;但是注意：这时候要把油箱加满
开到每次都选择在当前油量可以到达的加油站中价格最低的那个加油站进行加油。

如果无法找到任何能到达的加油站，那么就无法到达，那么我们就输出最大行驶距离。
"""
def cheapest_route(C, D, Davg, N, stations):
    stations.append((0, D))  # 将目的地作为一个加油站添加到列表中
    stations.sort(key=lambda x: x[1])  # 按照距离对加油站进行排序
    max_distance = C * Davg  # 计算汽车满油状态下可以行驶的最大距离
    total_price, current_gas = 0, 0  # 初始化总价格和当前油量
    current_station = 0  # 初始化当前加油站的位置(下标)
    # 如果在起点根本没有加油站
    if stations[current_station][1] != 0:
        return f"The maximum travel distance = {0:.2f}"
    while current_station < N:  # 没到终点，继续循环
        max_reachable_station = -1  # 初始化可以到达的最远加油站的位置
        min_price = float('inf')  # 初始化最小价格
        for i in range(current_station + 1, N + 1):  # 遍历所有可以到达的加油站
            if stations[i][1] - stations[current_station][1] > max_distance:  # 如果加油站超出了最大行驶距离，就跳出循环
                break
            # 如果加油站的价格低于当前最小价格，就更新最小价格和最远加油站的位置 -> 如果找不到比当前更便宜的，就找能到达的加油站相对便宜的；但是注意：这时候要把油箱加满
            if stations[i][0] < min_price:  
                min_price = stations[i][0]
                max_reachable_station = i
            # 如果找到了一个价格更低的加油站，就跳出循环 ->判断下一个加油站(能到达的)是否是比当前的加油站更便宜，如果是就加当前位置到下一个加油站
            if min_price < stations[current_station][0]:  
                break
        if max_reachable_station == -1:  # 如果没有找到可以到达的加油站，就跳出循环
            break
        # 如果找到可到达且更便宜的加油站
        if min_price < stations[current_station][0]:
            needed_gas = (stations[max_reachable_station][1] - stations[current_station][1]) / Davg  # 计算需要的油量
        # 找不到的话先加满油箱再去相对更便宜的加油站
        else:
            needed_gas = C 
        if needed_gas > current_gas:  # 如果需要的油量大于当前油量，就加油
            total_price += (needed_gas - current_gas) * stations[current_station][0]
            current_gas = needed_gas
        current_gas -= (stations[max_reachable_station][1] - stations[current_station][1]) / Davg  # 更新当前油量
        current_station = max_reachable_station  # 更新当前加油站的位置
    if current_station == N:  # 如果已经访问了所有的加油站，就返回总价格
        return f"{total_price:.2f}"
    else:  # 如果还有加油站没有访问，就返回最大行驶距离
        return f"The maximum travel distance = {stations[current_station][1] + max_distance:.2f}"

# 读取输入
C, D, Davg, N = map(float, input().split())  # 读取汽车的最大油量、目的地的距离、平均行驶距离和加油站的数量
N = int(N)
stations = []
for _ in range(N):  # 读取每个加油站的价格和距离
    P, Di = map(float, input().split())
    stations.append((P, Di))

# 找到最便宜的路线并输出
print(cheapest_route(C, D, Davg, N, stations))  # 调用函数并打印结果

