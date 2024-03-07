#include <map>
#include <iostream>
#include <string>

using namespace std;

map<int, char> convert = {
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, 'E'},
    {15, 'F'}
};

char convert2[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string Convert(int N, int R)
{
    string ans;
    while(N >= R)
    {
		ans.push_back(convert2[ N % R ]);
        N /= R;
    }
    ans.push_back(convert2[N]);
    return ans;
}

int main()
{
    int N,R;
    while(cin >> N >> R)
    {
		string ans = Convert(N, R);
        for (int i = ans.size()-1; i >= 0; i--)
        {
            cout << ans[i];
        }
        cout << endl;
    }
}