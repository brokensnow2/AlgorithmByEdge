#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

struct compare {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
}; //priority_queue 的第三个模板参数应该是一个比较对象（comparator），而不是一个函数。


int Dijsktra(vector<vector<pair<int, int>>> &graph
				, int start
                , unordered_set<int> directions
                , int cost)
{
    // 					end, cost
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    //
    unordered_set<int> visited;
    q.push(make_pair(start, cost));
    while (!q.empty())
    {
        pair<int, int> node = q.top();
        q.pop();
        if (directions.find(node.first) != directions.end())
        {
            return node.second;
            break;
        }
        if (visited.find(node.first) == visited.end())
        {
            visited.insert(node.first);
            for (auto i : graph[node.first])
            {
                if (visited.find(i.first) == visited.end())
					q.push(make_pair(i.first, i.second+node.second));
            }
        }
    }
    return INT32_MAX;
}

int main()
{
    // graph	 		b   time
    vector<vector<pair<int, int>>> graph(1001);
	
    // t :roads, s :start, d : dirction
    int t, s, d;
    while (cin >> t >> s >> d)
    {
		int a, b, time;
        // Init Graph
        while (t--)
        {
			cin >> a >> b >> time;
            graph[a].push_back(make_pair(b, time));
        }
        vector<int> starts(s);
        // init
        for (int i = 0; i < s; i++)
            cin >> starts[i];
		unordered_set<int> directions;
        //init
        int direction;
        for (int i = 0; i < d; i++)
        {
			cin >> direction;
            directions.insert(direction);
        }
        int max = INT32_MAX;
        int cost;
        for (int i : starts)
        {
			cost = Dijsktra(graph, i, directions, 0);
            if (cost < max)
                max = cost;
        }
        cout << max << endl;

    }
    return 0;
}