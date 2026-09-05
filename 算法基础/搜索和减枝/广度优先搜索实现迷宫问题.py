"""
迷宫问题(P0J3984)
定义一个矩阵:
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路,
只能横着走或竖着走，不能斜着走，要求编程序找出从
左上角到右下角的最短路线。

本质：BFS实现非带权图的最短路径。最左上节点到最右下节点
"""

from collections import deque

maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 1, 0],
]

ROWS, COLS = len(maze), len(maze[0])
DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def bfs(start, end):
    # 队列元素: (行, 列, 到达该点的路径)
    queue = deque([(start[0], start[1], [start])])
    visited = {start}

    while queue:
        r, c, path = queue.popleft()
        if (r, c) == end:
            return path
        for dr, dc in DIRECTIONS:
            nr, nc = r + dr, c + dc
            if (
                0 <= nr < ROWS
                and 0 <= nc < COLS
                and maze[nr][nc] == 0
                and (nr, nc) not in visited
            ):
                visited.add((nr, nc))
                queue.append((nr, nc, path + [(nr, nc)]))

    return None  # 无解


if __name__ == "__main__":
    path = bfs((0, 0), (ROWS - 1, COLS - 1))
    if path:
        print("最短路径长度:", len(path) - 1)
        print("路径坐标:", path)
        path_set = set(path)
        for r in range(ROWS):
            row_str = []
            for c in range(COLS):
                if (r, c) in path_set:
                    row_str.append("*")
                elif maze[r][c] == 1:
                    row_str.append("#")
                else:
                    row_str.append(".")
            print(" ".join(row_str))
    else:
        print("无解")
