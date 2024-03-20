#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // 不加负号右对齐，不然左对齐
    cout << setw(-10) << "Hello" << endl;

	int num = 42;
    cout << setw(5) << setfill('0') << num << endl;
    cout << hex << num << endl;
    
    double pi = 3.14159;
	cout << setw(7) << setfill('0') << fixed << setprecision(3) << pi << endl;

}