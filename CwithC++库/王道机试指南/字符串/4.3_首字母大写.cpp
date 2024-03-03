// C的话调用库函数Upper
// C++ 如下

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        //利用ASCII
        if (str[0] <= 122 && str[0] >=97)
        {
            str[0] -= 32;
        }
        cout << str << endl;
    }
}

