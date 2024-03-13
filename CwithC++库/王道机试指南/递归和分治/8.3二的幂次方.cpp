#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string power_of_two(int num)
{
	if (num == 1)
    	return "2(0)";
    else if (num == 2)
    	return "2";
    else if (num == 3)
    	return "2+2(0)";
    int power = 0;
    int temp = 1;
    while (temp <= num)
    {
		temp *= 2;
        ++power;
    }
    power--;
    int remainder = num - (int)pow(2, power);
    if (remainder == 0)
        return "2(" + power_of_two(power) + ")";
    else
        return "2(" + power_of_two(power) + ")+" + power_of_two(remainder);
}

int main()
{
    int num;
    cin >> num;
	cout << power_of_two(num) << endl;
}