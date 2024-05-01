/**
 * 解法：采用模的数学性质
 * 但会超时，见1005_new
 * 
*/

#include <iostream>

using namespace std;

int func(int A, int B, int N)
{
    if (N == 1 || N == 2)
        return 1;
    
    //  f(n-2)  f(n-1)
    int f1 = 1, f2 = 1, temp;
    for (int i = 2; i < N; i++)
    {
        temp = (A * f2 + B * f1) % 7;
        f1 = f2 % 7;
        f2 = temp;
    }
    return f2;
}


int main()
{
    int A, B, N;
    while (cin >> A >> B >> N)
    {
        if (A && B && N)
        {
            int ans = func(A, B, N);
            cout << ans << endl;
        }
        else
            break;
        
    }
    
}