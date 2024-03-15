#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if (a.first < b.first)
    	return true;
    else
    	return false;
}

bool isFactor(int m, int factor)
{
	if (m % factor == 0)
        return true;
    else
    	return false;
}

int main()
{
    int n,m;
	vector<pair<int, int>> ans;
    while (cin >> n >> m && (n || m))
    {
        if (n >= m)
        {
            // find factors
            for (int i = 1; i <= m; i++)
            {
                if (isFactor(m, i))
                {
                    int quotient = m / i;
                    // if quotient is even
                    if (quotient % 2 == 0)
                    {
                        int left_index = i / quotient - (quotient - 1);
                        int right_index = i / quotient + quotient;
                        // illegal judge
						if (left_index > 0)
                            ans.push_back(make_pair(left_index, right_index));
                    }
                    else // if quotient is odd
                    {
						int left_index = i - (quotient / 2);
                        int right_index = i + (quotient /2);
                        if (left_index > 0)
                            ans.push_back(make_pair(left_index, right_index));
                    }
                }
                
            }
            
        }
        sort(ans.begin(), ans.end(), compare);
        for (int i = 0; i < ans.size(); i++)
        {
            printf("[%d,%d]\n", ans[i].first, ans[i].second);
        }
        printf("\n");
        ans.clear();
    }
    
}