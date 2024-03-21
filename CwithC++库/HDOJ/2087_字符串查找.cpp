#include <iostream>
#include <string>

using namespace std;

int main()
{
    string main_str, sub_str;
    while (cin >> main_str && main_str != "#")
    {
        cin >> sub_str;
		int count = 0;
        while (main_str.find(sub_str) != string::npos)
        {
            int pos = main_str.find(sub_str);
            ++count;
            main_str = main_str.substr(pos + sub_str.size());
        }
        cout << count << endl;
    }
}