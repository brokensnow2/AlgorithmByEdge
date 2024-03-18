#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    // n cases
    int n;
    cin >> n;
    // array to store students
	vector<double> stus;
    for (int i = 0; i < n; i++)
    {
        int stu_number;
        double stu;
        cin >> stu_number;
        for (int i = 0; i < stu_number; i++)
        {
            cin >> stu;
            stus.push_back(stu);
        }
        double ans = *max_element(stus.begin(), stus.end());
		cout << fixed << setprecision(2) << ans << endl;
        stus.clear();
    }
    	
}