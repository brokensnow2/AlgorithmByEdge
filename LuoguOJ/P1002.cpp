#include <bits/stdc++.h>
using namespace std;

long long dp[25][25];
bool blocked[25][25];

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    // 标记马控制点
    blocked[hx][hy] = true;
    for (int k = 0; k < 8; k++) {
        int nx = hx + dx[k];
        int ny = hy + dy[k];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            blocked[nx][ny] = true;
    }

    dp[0][0] = blocked[0][0] ? 0 : 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (blocked[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) continue;

            long long from_up = (i > 0 ? dp[i-1][j] : 0);
            long long from_left = (j > 0 ? dp[i][j-1] : 0);

            dp[i][j] = from_up + from_left;
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}