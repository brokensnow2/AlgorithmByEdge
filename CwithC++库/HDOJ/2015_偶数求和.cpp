#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> sequence(n);
        vector<double> ans;
        for (int i = 0; i < n; ++i) {
            sequence[i] = 2 * (i + 1);
        }

        for (int i = 0; i < n; i += m) {
            int count = min(m, n - i);
            double sum = accumulate(sequence.begin() + i, sequence.begin() + i + count, 0);
            double avg = sum / (double)count;
            ans.push_back(avg);
        }

        for (int i = 0; i < ans.size()-1; i++)
        {
			cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1] << endl;
    }
    return 0;
}
