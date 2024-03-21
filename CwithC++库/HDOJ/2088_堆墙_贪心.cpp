#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, height, total_height = 0;
    // store every stack's height
    vector<int> stacks;
    while (cin >> n && n)
    {
        int ans = 0;
        while (n--)
        {
			cin >> height;
            stacks.push_back(height);
            total_height += height;
        }
        int avg_height = total_height / n;
        for (int i = 0; i < stacks.size(); i++)
        {
            if (stacks[i] > avg_height)
				ans += stacks[i] - avg_height;
        }
        cout << ans << endl;
    }
}