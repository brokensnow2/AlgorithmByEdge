#include <iostream>
#include <vector>

using namespace std;

// 定义上、下、左、右四个方向的偏移量
const vector<int> dx = {-1, 1, 0, 0};
const vector<int> dy = {0, 0, -1, 1};

// 深度优先搜索函数
void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, int value) 
{
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
        return;
    }
    if (visited[row][col] || matrix[row][col] != value) {
        return;
    }
    visited[row][col] = true;
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        dfs(matrix, visited, newRow, newCol, value);
    }
}

// 计算连通块数量的函数
int countConnectedBlocks(const vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                count++;
                dfs(matrix, visited, i, j, matrix[i][j]);
            }
        }
    }
    return count;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    int result = countConnectedBlocks(matrix);
    cout << result << endl;
    return 0;
}
