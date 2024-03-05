#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if (n == 0)
        {
            break;
        }
		vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
			cin >> array[i];
        }

        int min = array[0];
        int index = 0;

        for (int i = 1; i < array.size(); i++)
        {
            if (array[i] < min)
            {
                min = array[i];
                index = i;
            }
        }

        if (index != 0)
        {
            int temp = array[0];
            array[0] = array[index];
            array[index] = temp;
        }

        for (int i = 0; i < array.size()-1; i++)
        {
            printf("%d ", array[i]);
        }
        printf("%d\n", array[array.size()-1]);
        
    }
}