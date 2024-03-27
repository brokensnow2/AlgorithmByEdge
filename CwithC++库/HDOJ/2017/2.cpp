/**
 * todo 解题思路
 * 库函数 
*/
#include <cstdio>
#include <iostream>
#include <algorithm> // sort
#include <string>
#include <vector>
using namespace std;

struct staff
{
    string ID;
    string on_duty[3];
    string off_duty[3];
    staff(string id, string on_duty, string off_duty)
    {
		this->ID = id;
        for (int i = 0; i < 3; i++)
        {
            this->on_duty[i] = on_duty.substr(3*i,2);
        }
        for (int i = 0; i < 3; i++)
        {
            this->off_duty[i] = off_duty.substr(3*i,2);
        }

    }
};

bool cmp1(staff &a, staff &b)
{
    if (a.on_duty[0] == b.on_duty[0])
    	if (a.on_duty[1] == b.on_duty[1])
        	return a.on_duty[2] < b.on_duty[2];
        else
        	return a.on_duty[1] < b.on_duty[2];
    else
    	return a.on_duty[0] < b.on_duty[0];
}

bool cmp2()
{

}

bool cmp3()
{
    
}

int main()
{
	int n;
    string id, on, off;
    cin >> n;
    vector<staff> s;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> on >> off;
		s.push_back(staff(id, on, off));
    }
    sort(s.begin(), s.end(), cmp1);
    cout << s[0].ID << ' ';
    cout << s[0].on_duty[0] << ':' << s[0].on_duty[1] << ':' << s[0].on_duty[2] << endl;

}