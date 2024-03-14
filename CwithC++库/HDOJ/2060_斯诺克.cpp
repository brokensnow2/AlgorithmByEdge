#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    // test's number
    int n;
	int ball,score,otherScore;
    cin >> n;
    while (n--)
    {
		cin >> ball >> score >> otherScore;
        if (ball >= 6)
            score += (ball - 6) * 1 + (ball -6) * 7 + 27;
        else
        	score += ball * ((7 - ball + 1) + 7) / 2;
        if (score >= otherScore)
        	printf("Yes\n");
        else
			printf("No\n");
    }
}