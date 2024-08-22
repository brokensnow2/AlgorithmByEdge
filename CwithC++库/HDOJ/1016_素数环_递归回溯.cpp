#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void backtrack(int n, vector<int> &path, vector<bool> &used, vector<vector<int>> &result)
{
    if (path.size() == n)
    {
        if (is_prime(path.back() + path[0]))
        {
            result.push_back(path);
        }
        return;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (!used[i] && is_prime(path.back() + i))
        {
            used[i] = true;
            path.push_back(i);
            backtrack(n, path, used, result);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int case_number = 1;
    int n;

    while (cin >> n)
    {
        vector<vector<int>> result;
        vector<bool> used(n + 1, false);
        vector<int> path;

        used[1] = true;
        path.push_back(1);

        backtrack(n, path, used, result);

        cout << "Case " << case_number << ":" << endl;
        for (const auto &res : result)
        {
            for (int i = 0; i < res.size(); ++i)
            {
                if (i > 0)
                    cout << " ";
                cout << res[i];
            }
            cout << endl;
        }
        cout << endl;
        case_number++;
    }

    return 0;
}
