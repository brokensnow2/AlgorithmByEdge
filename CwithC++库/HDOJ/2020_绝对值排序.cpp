#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 自定义排序函数，按照绝对值从大到小排序
bool compare(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end(), compare);
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << nums[i];
        }
        cout << endl;
    }
    return 0;
}
