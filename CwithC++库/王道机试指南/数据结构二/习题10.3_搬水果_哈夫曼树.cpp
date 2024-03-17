/**
 * 本质上求WPL；同例题10.6
 * 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    while (cin >> n && n != 0)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
			cin >> temp;
        	q.push(temp);            
        }
    	int ans = 0;
    	while (q.size() > 1)
    	{
        	int a = q.top();
        	q.pop();
        	int b = q.top();
        	q.pop();
        	ans += a + b;
        	q.push(a + b);
    	}
    	cout << ans << endl;
    }
}