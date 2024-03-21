#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M;
    cin >> M; // 读取测试实例的数量
    while (M--) {
        int N;
        cin >> N; // 读取朋友的数量
        vector<int> coords(N);
        for (int i = 0; i < N; ++i) {
            cin >> coords[i]; // 读取每个朋友的坐标
        }
        sort(coords.begin(), coords.end()); // 对坐标进行排序
        int mid = coords[N / 2]; // 找到中位数
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += abs(coords[i] - mid); // 计算所有朋友家到中位数的距离之和
        }
        cout << sum << endl; // 输出最小的时间
    }
    return 0;
}
