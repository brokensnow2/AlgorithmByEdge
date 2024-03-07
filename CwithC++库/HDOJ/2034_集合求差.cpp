#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n || m)) { // 读取集合A和B的元素个数，如果n和m都为0，则结束输入
        set<int> A, B;
        for (int i = 0; i < n; i++) { // 读取集合A的元素
            int x;
            cin >> x;
            A.insert(x);
        }
        for (int i = 0; i < m; i++) { // 读取集合B的元素
            int x;
            cin >> x;
            B.insert(x);
        }
        vector<int> diff;
        // set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(diff)); // 计算A-B的差集
        for (auto i : A)
        {
            if (B.find(i) == B.end())
            {
				diff.push_back(i);
            }
        }
        if (diff.empty()) { // 如果差集为空
            cout << "NULL";
        } else { // 如果差集非空
            for (int x : diff) {
                cout << x << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
