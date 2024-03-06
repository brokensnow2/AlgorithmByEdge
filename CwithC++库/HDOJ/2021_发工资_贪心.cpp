/**
解法：
人民币张数最少：贪心：找最接近但不大于与该工资的的面额，
减去面额后的工资继续这么找
*/
#include <iostream>
#include <vector>
using namespace std;

int min_notes(int n, std::vector<int> salaries) {
    std::vector<int> notes = {100, 50, 10, 5, 2, 1};
    int total_notes = 0;
    for (int salary : salaries) {
        for (int note : notes) {
            if (salary >= note) {
                int count = salary / note;
                salary -= count * note;
                total_notes += count;
            }
        }
    }
    return total_notes;
}

int main() {
    //几个老师
    int n;
    while(cin >> n)
    {
        if (!n)
        {
			break;
        }
    	//他们的工资
    	vector<int> salaries;
    	//临时变量：存老师的工资
    	int temp;
    	for (int i = 0; i < n; i++)
    	{
			cin >> temp;
        	salaries.push_back(temp);
    	}
    	std::cout << min_notes(n, salaries) << std::endl;
    }

    return 0;
}
