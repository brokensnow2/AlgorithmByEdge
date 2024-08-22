#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int case_num = 1; case_num <= N; ++case_num)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        int count = 0;

        for (int a = 1; a < n; ++a)
        {
            for (int b = a + 1; b < n; ++b)
            {
                if ((a * a + b * b + m) % (a * b) == 0)
                {
                    ++count;
                }
            }
        }

        cout << "Case " << case_num << ": " << count << endl;

        if (case_num != N)
        {
            cout << endl;
        }
    }

    return 0;
}
