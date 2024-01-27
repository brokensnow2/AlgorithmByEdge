"""
输入
程序从标准输入设备读入数据。
第一行是两个整数，分别是南北向、东西向的方块数
在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数
字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南
墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两
次，方块(1,1)的 南墙同时也是方块(2,1)的北墙。
输入的数据保证城堡至少有两个房间。
输出
城堡的房间数、 城堡中最大房间所包括的方块数。
结果显示在标准输出设备上。
样例输入
4 7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
样例输出
5
9

"""
def dfs(cell :int, i_index :int, j_index :int) -> None:
    global roomArea
    """
    param cell: 房间
    param i_index: 行下标
    param j_index: 列下标
    """
    if (i_index,j_index) in visited:
        return
    visited.add((i_index,j_index))
    roomArea += 1
    # 西边没墙，向西走
    if cell & 1 == 0:
        dfs(castle[i_index][j_index-1],i_index,j_index-1)
    # 向北
    if cell & 2 == 0:
        dfs(castle[i_index-1][j_index],i_index-1,j_index)
    # 向东
    if cell & 4 == 0:
        dfs(castle[i_index][j_index+1],i_index,j_index+1)
    # 向南
    if cell & 8 == 0:
        dfs(castle[i_index+1][j_index],i_index+1,j_index)


# 行列
row,column = map(int,input().split())
# 城堡
castle = [[] for _ in range(row)]
for i in range(row):
    castle[i] = list(map(int,input().split()))
# 访问数组
visited = set()
# 最大房间
maxArea = 0
# 房间数
num = 0
# 临时房间大小：全局变量
global roomArea
for i in range(row):
    for j in range(column):
        # 该点坐标未访问过
        if (i,j) not in visited:
            # 房间数+1
            num += 1
            # 房间大小
            roomArea = 0
            dfs(castle[i][j],i,j)
            maxArea = max(maxArea,roomArea)
print(f"房间数:{num} 最大大小:{maxArea}")