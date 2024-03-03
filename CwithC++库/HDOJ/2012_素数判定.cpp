extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
#include <math.h>
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <string> // 引入C++的string类

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    int sqrtNum = std::sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{

    int x,y;
    cin >> x >> y;
    while (!(x == 0 && y == 0))
    {
        bool flag = true;

        for (; x<=y; x++)
        {
            if(!isPrime(x*x+x+41))
            {
                flag = false;
                break;
            }    
        }

        if (flag)
            cout << "OK\n";
        else
            cout << "Sorry\n";
        
        cin >> x >> y;
    }
}