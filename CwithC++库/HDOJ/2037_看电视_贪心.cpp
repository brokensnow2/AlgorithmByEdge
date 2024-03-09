#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int max_movies(vector<pair<int, int>>& movies) {
    // 按结束时间从小到大排序
    sort(movies.begin(), movies.end(), compare);
    
    int count = 0;
    int end_time = -1;
    
    for (auto& movie : movies) {
        int start = movie.first;
        int end = movie.second;
        if (start >= end_time) {
            // 选择不冲突的电影
            count++;
            end_time = end;
        }
    }
    
    return count;
}

int main() {
    int n;
    while (cin >> n)
    {	if (n == 0)
    	{
            break;
        }
        vector<pair<int, int>> movies(n);
        for (int i = 0; i < n; i++) 
        {
        	cin >> movies[i].first >> movies[i].second;
    	}
        cout << max_movies(movies) << endl;
    
    }
    return 0;
}
