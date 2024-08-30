"""
1072 Gas Station

A gas station has to be built at such a location that the minimum distance 
between the station and any of the residential housing is as far away as possible. 
However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, 
you are supposed to give the best recommendation. 
If there are more than one solution, 
output the one with the smallest average distance to all the houses. 
If such a solution is still not unique, output the one with the smallest index number.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains 4 positive integers: N (≤10^3), the total number of houses; 
M (≤10), the total number of the candidate locations for the gas stations; 
K (≤10^4), the number of roads connecting the houses and the gas stations; 
and Ds, the maximum service range of the gas station. 

It is hence assumed that all the houses are numbered from 1 to N, 
and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, 
and Dist is the integer length of the road.

Output Specification:
For each test case, print in the first line the index number of the best location. 
In the next line, print the minimum and the average distances between the solution and all the houses. 
The numbers in a line must be separated by a space and be accurate up to 1 decimal place. 
If the solution does not exist, simply output No Solution.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3

Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution

解题思路：
对每个加油站进行单源最短路径，判断加油站到所有home的最短距离。
如果有一个home到该加油站大于了Ds。则该加油站不行，换下一个加油站继续判断且记录它的总路径长度。
最后将所有记录可以的加油站列表进行排序，找到最小路径最大，平均路径最小而且序号最小的输出。
"""

import heapq
from decimal import Decimal, ROUND_HALF_UP

def dijkstra(graph, start, n, m):
    distances = {node: float('inf') for node in range(1, n + m + 1)}
    distances[start] = 0
    priority_queue = [(0, start)]
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            
            if  distance < distances[neighbor] :
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances

def find_best_gas_station(n, m, k, ds, roads):
    graph = {i: [] for i in range(1, n + m + 1)}
    
    for p1, p2, dist in roads:
        if isinstance(p1, str):
            p1 = n + int(p1[1:])
        if isinstance(p2, str):
            p2 = n + int(p2[1:])
        graph[p1].append((p2, dist))
        graph[p2].append((p1, dist))
    
    best_station = None
    best_min_distance = -float('inf')
    best_avg_distance = float('inf')
    
    for station in range(n + 1, n + m + 1):
        distances = dijkstra(graph, station, n, m)
        min_distance = float('inf')
        total_distance = 0
        valid = True
        
        for house in range(1, n + 1):
            if distances[house] > ds:
                valid = False
                break
            min_distance = min(min_distance, distances[house])
            total_distance += distances[house]
        
        if valid:
            avg_distance = total_distance / n
            if (min_distance > best_min_distance or
                (min_distance == best_min_distance and avg_distance < best_avg_distance) or
                (min_distance == best_min_distance and avg_distance == best_avg_distance and station < best_station)): # type: ignore
                best_station = station
                best_min_distance = min_distance
                best_avg_distance = avg_distance
    
    if best_station is None:
        return "No Solution"
    else:
        best_avg_distance = Decimal(best_avg_distance)
        # 不能用round来四舍五入，见round缺陷
        return f"G{best_station - n}\n{best_min_distance:.1f} {str(best_avg_distance.quantize(Decimal('0.1'), rounding=ROUND_HALF_UP))}"

# 示例输入
# 示例输入
def process_input():
    # 读取第一行，获取N, M, K, Ds
    n, m , k, ds = map(int, input().split())
    
    # 读取接下来的K行，获取每条道路的信息
    roads = []
    for _ in range(k):
        P1, P2, Dist = input().split()
        Dist = int(Dist)
        # 如果P1和P2是加油站，需要处理它们的编号
        if P1.startswith('G'):
            pass
        else:
            P1 = int(P1)
        if P2.startswith('G'):
            pass
        else:
            P2 = int(P2)
        roads.append((P1, P2, Dist))
    
    # 处理找到最优的加油站
    print(find_best_gas_station(n, m , k, ds, roads), end='') # 结尾不要换行

# 示例用法：接收标准输入并处理
if __name__ == "__main__":
    process_input()
