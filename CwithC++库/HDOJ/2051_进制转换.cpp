#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> ConvertTo2(int n)
{
    vector<int> result;
	while (n != 0)
    {
		result.push_back(n % 2);
        n /= 2;
    }
    return result;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> res = ConvertTo2(n);
        for (int i = res.size() - 1; i >= 0; i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    }
}