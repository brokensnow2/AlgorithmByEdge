#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    // 每个真实坐标上有几个锚点
    map<long long, int> cnt;

    // 当前所有不同的锚点位置
    set<long long> pos;

    for (auto &x : a) {
        cin >> x;

        cnt[x]++;

        pos.insert(x);
    }

    // 当前所有相邻位置之间的 gap
    multiset<long long> gaps;

    if (pos.size() >= 2) {
        auto prev_it = pos.begin();
        auto it = next(prev_it);

        while (it != pos.end()) {
            gaps.insert(*it - *prev_it);

            prev_it = it;
            ++it;
        }
    }

    auto erase_one_gap = [&](long long g) {
        auto it = gaps.find(g);

        if (it != gaps.end()) {
            // 只删除其中一个 g
            gaps.erase(it);
        }
    };

    auto remove_position = [&](long long x) {
        // 还有其他锚点留在 x
        if (cnt[x] > 1) {
            cnt[x]--;
            return;
        }

        // 找到 x 在有序集合中的位置
        auto it = pos.find(x);

        auto next_it = next(it);

        bool has_left = (it != pos.begin());
        bool has_right = (next_it != pos.end());

        // 保存前驱
        auto prev_it = it;

        if (has_left) {
            --prev_it;
            erase_one_gap(x - *prev_it);
        }

        if (has_right) {
            erase_one_gap(*next_it - x);
        }

        // 删除 x 后，左右邻居直接相邻
        if (has_left && has_right) {
            gaps.insert(*next_it - *prev_it);
        }

        pos.erase(it);
        cnt[x] = 0;
    };

    auto add_position = [&](long long x) {
        // x 本来就存在
        if (cnt[x] > 0) {
            cnt[x]++;
            return;
        }

        // lower_bound 找第一个 >= x 的位置，
        // 因为 x 当前不存在，所以这就是后继。
        auto right_it = pos.lower_bound(x);

        bool has_right = (right_it != pos.end());
        bool has_left = (right_it != pos.begin());

        auto left_it = right_it;

        if (has_left) {
            --left_it;
        }

        // 原来的 left --- right 被拆开
        if (has_left && has_right) {
            erase_one_gap(*right_it - *left_it);
        }

        if (has_left) {
            gaps.insert(x - *left_it);
        }

        if (has_right) {
            gaps.insert(*right_it - x);
        }

        pos.insert(x);
        cnt[x] = 1;
    };

    while (q--) {
        int i;
        long long x;

        cin >> i >> x;

        --i;

        long long old = a[i];

        if (old != x) {
            remove_position(old);
            add_position(x);

            a[i] = x;
        }

        if (gaps.empty()) {
            cout << 0 << '\n';
        } else {
            long long max_gap = *gaps.rbegin();

            cout << max_gap / 2 << '\n';
        }
    }

    return 0;
}