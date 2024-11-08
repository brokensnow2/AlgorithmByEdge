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
}; //priority_queue 的第三个模板参数应该是一个比较对象（comparator），而不是一个普通函数。
//比较对象：
/*
template <class T,
          class Container = std::vector<T>,
          class Compare = std::less<T>>
class priority_queue;

第三个模板参数 Compare：
这个参数用于定义优先队列的排序规则，决定如何比较元素的优先级。
它必须是一个可调用对象（如函数对象、结构体或类），而不能是一个普通函数指针。
为什么不能是普通函数：

普通函数无法直接作为模板参数传递，因为它们不是可调用对象的类型。可调用对象可以是类或结构体，并且可以重载 operator()，使其可以像函数一样使用。
例如，下面的 compare 结构体可以用作比较对象，因为它重载了 operator()，可以在比较时被调用。

*/

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