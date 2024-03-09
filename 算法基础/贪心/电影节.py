"""
大学生电影节在北大举办!这天,在北大各地放了多部电影
,给定每部电影的放映时间区间,区间重叠的电影不可能同时
看(端点可以重合) , 问李雷最多可以看多少部电影。
Sample Input
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

Sample Output
5

"""

"""
贪心解法:
将所有电影按结束时间从小到大排序,第一步选结束.
时间最早的那部电影。
然后,每步都选和上一部选中的
电影不冲突且结束时间最早的电影。

"""

def max_movies(movies):
    # 按结束时间从小到大排序
    movies.sort(key=lambda x: x[1])
    
    count = 0
    end_time = -1
    
    for movie in movies:
        start, end = movie
        if start >= end_time:
            # 选择不冲突的电影
            count += 1
            end_time = end
    
    return count

if __name__ == "__main__":
    n = int(input())
    movies = []
    for _ in range(n):
        start, end = map(int, input().split())
        movies.append((start, end))
    
    print(max_movies(movies))
