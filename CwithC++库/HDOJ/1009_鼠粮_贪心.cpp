/**
 * todo解题思路
 * 对房间按J[i]/F[i]从大到小排序
 * 然后依次购买
 * 
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct node
{
    int F;
    int J;
    double rate;
};
node rooms[1000];

bool cmp(node a, node b)
{
    return a.rate > b.rate;
}

int main()
{
    // 猫粮，房间数, javaBean
    double M;
    int N;
    double javaBean;
    while (cin >> M >> N)
    {
        if (M == -1 && N == -1)
            break;
        for (int i = 0; i < N; i++)
        {
            cin >> rooms[i].J >> rooms[i].F;
            rooms[i].rate = rooms[i].J / (double)rooms[i].F;
        }
        sort(rooms, rooms+N, cmp);
        javaBean = 0;
        for (int i = 0; M > 0; i++)
        {
            if (M >= rooms[i].F)
            {
                javaBean += rooms[i].J;
                M -= rooms[i].F;
            }
            else
            {
                double precent = M / rooms[i].F;
                javaBean += rooms[i].J * precent;
                M = 0;
            }
            
        }
        cout << fixed << setprecision(3) << javaBean << endl;
        
    }
    
}