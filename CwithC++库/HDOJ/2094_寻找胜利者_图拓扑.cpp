/**
 * todo 找到入度为0的结点，如果只有一个可以判断产生了冠军
 * todo 不然如果没有或者有多个，就没有胜利者
 * 
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    string winner, loser;
    unordered_map<string, int> map;
    while (cin >> n && n)
    {
        while(n--)
        {
			cin >> winner >> loser;
			map[loser] += 1;
            if (map.find(winner) == map.end())
            	map[winner] = 0;
        }
        int count = 0;
        for (auto i : map)
        {
            if (i.second == 0)
            	count++;
        }
        if (count != 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        map.clear();
    }
}