#include <iostream>
#include <cstdio>

using namespace std;

int nextTable[1000]; // next表
int pattern[1000]; // 模式串
int text[1000];

void getNextTable(int m)
{
    int j = 0;
    nextTable[j] = -1;
    int i = nextTable[j];
    while (j < m)
    {
        if (i == -1 || pattern[j] == pattern[i])
        {
            i++;
            j++;
            nextTable[j] = i;
        }
        else
        {
            i = nextTable[j];
        }
        
    }
    
}

int KMP(int n, int m)
{
	getNextTable(m);
    int i, j;
    i = j = 0;
    while (i < n && j < m)
    {
		if (j == -1 || text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
        	j = nextTable[j];
        }
        if (j == m)
        {
            return i - j - 1;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{

}