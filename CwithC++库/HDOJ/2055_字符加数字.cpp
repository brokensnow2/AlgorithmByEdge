/**
 * Problem Description
we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
Give you a letter x and a number y , you should output the result of y+f(x).

Input
On the first line, contains a number T.
then T lines follow, each line is a case.
each case contains a letter and a number.

Output
for each case, you should the result of y+f(x) on a line.

Sample Input
6
R 1
P 2
G 3
r 1
p 2
g 3
 

Sample Output
19
18
10
-17
-14
-4
 * 
 * 
 * 
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int count;
    int num;
    char letter;
    cin >> count;
    while (count--)
    {
		cin >> letter >> num;
        if (letter >= 'a')
        {
            int l = letter - 'a' + 1;
            cout << num - l << endl;
        }
        else 
        {
            int l = letter - 'A' + 1;
            cout << num + l << endl;
        }
    }
}