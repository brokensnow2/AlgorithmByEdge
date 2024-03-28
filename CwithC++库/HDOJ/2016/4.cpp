#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, M, n, m;
    cin >> N >> M;

    vector<vector<int>> bigMatrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> bigMatrix[i][j];
        }
    }

    cin >> n >> m;
	vector<vector<int>> smallMatrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < m; ++j) {
            cin >> smallMatrix[i][j];
        }
    }
    int minAbsDiffSum = INT32_MAX;
    vector<pair<int, int>> topLefts; // 记录最小绝对值之差的和对应的大矩阵位置,可能不止一个

    // 遍历大矩阵的每个位置作为小矩阵的左上角位置
    for (int i = 0; i <= N - n; ++i) {
        for (int j = 0; j <= M - m; ++j) {
            int absDiffSum = 0;

            // 计算小矩阵和大矩阵对应位置的数字绝对值之差
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    absDiffSum += abs(bigMatrix[i + x][j + y] - smallMatrix[x][y]);
                }
            }

            // 更新最小绝对值之差的和和对应的大矩阵位置
            if (absDiffSum < minAbsDiffSum) {
                minAbsDiffSum = absDiffSum;
                topLefts.clear();
                topLefts.push_back({i, j});
            }
            else if (absDiffSum == minAbsDiffSum)
            	topLefts.push_back({i, j});
        }
    }

    cout << "最小绝对值之差的和：" << minAbsDiffSum << endl;
    cout << "对应的大矩阵位置：";
    for (int i = 0; i < topLefts.size(); i++)
    	cout << topLefts[i].first << " " << topLefts[i].second << endl;

    return 0;
}
