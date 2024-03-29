/**
 * 定义一个矩阵:
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路,
只能横着走或竖着走，不能斜着走，要求编程序找出从
左上角到右下角的最短路线。
 * 本质：BFS实现非带权图的最短路径。最左上节点到最右下节点
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#define WALL 1
#define PATH 0

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int maze[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> parent[MAX][MAX];

bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(visited[x][y] || maze[x][y] == WALL) return false;
    return true;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if(isValid(newX, newY)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                parent[newX][newY] = {curX, curY};

                if(newX == n-1 && newY == m-1) return;
            }
        }
    }
}

void printPath(int x, int y) {
    if(x == 0 && y == 0) {
        cout << "(" << x << ", " << y << ") ";
        return;
    }
    printPath(parent[x][y].first, parent[x][y].second);
    cout << "-> (" << x << ", " << y << ") ";
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> maze[i][j];

    memset(visited, false, sizeof(visited));

    bfs(0, 0);

    if(visited[n-1][m-1]) {
        cout << "The shortest path is: ";
        printPath(n-1, m-1);
    } else {
        cout << "No path exists!";
    }

    return 0;
}