/**
Sample Input:
3 //N只小白鼠
15 red //weight color
20 blue
7 green

Sample Output:
blue red green

*/

extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}

#include <sstream> // 引入字符串流库
#include <algorithm> // 引入C++的算法库
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

//黄金法则
bool Compare(tuple<int,string> rat1, tuple<int,string> rat2)
{
    if (get<0>(rat1) >= get<0>(rat2))
    {
        return true;
    }
    else
    	return false;
}


int main()
{
    //rats个数
    int N;
    cin >> N;

    //小鼠用[(15,red),(20,blue)..]表示
    vector<tuple<int,string>> rats;
    int weight;
    string hat;

    string line;
    string word;
    for (int i = 0; i < N; i++)
    {
        cin >> weight >> hat;
        rats.push_back(make_tuple(weight,hat));
    }
    sort(rats.begin(),rats.end(),Compare);

    for (tuple<int,string> rat : rats)
    {
        cout << get<1>(rat) << ' ';
    }

}
