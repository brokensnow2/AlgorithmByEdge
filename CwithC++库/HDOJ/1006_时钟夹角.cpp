/**
 * https://www.cnblogs.com/xueda120/p/3575399.html
 *
 *
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int T = 360 * 120, NMS = 708, NHM = 11, NHS = 719; // 相遇次数
const double F = 0.0466631;                              // F为调节系数，使得各区间段为准确值
const double hmlen = T * F / NHM, mslen = T * F / NMS, hslen = T * F / NHS;
struct interval
{
    double low, high;
};
interval andset(interval S1, interval S2)
{
    interval zone;
    zone.low = S1.low > S2.low ? S1.low : S2.low;
    zone.high = S1.high < S2.high ? S1.high : S2.high;
    if (zone.low >= zone.high)
        zone.low = zone.high = 0.0;
    return zone;
}
int main()
{
    int D = 0;
    while (cin >> D && D != -1)
    {
        double len = 0.0;
        interval ms, hs, hm;

        hm.low = hmlen * D / 360 - hmlen;
        hm.high = -hm.low - hmlen;

        ms.low = mslen * D / 360 - mslen;
        ms.high = -ms.low - mslen;

        hs.low = hslen * D / 360 - hslen;
        hs.high = -hs.low - hslen;

        for (int i = 0, j = 0, k = 0; i < NHM; i++)
        {
            hm.low += hmlen;
            hm.high += hmlen;

            for (; j < NMS; j++)
            {
                ms.low += mslen;
                ms.high += mslen;

                interval temp1 = andset(hm, ms);
                if (temp1.low != 0 || temp1.high != 0)
                {
                    for (; k < NHS; k++)
                    {
                        hs.low += hslen;
                        hs.high += hslen;

                        interval temp2 = andset(temp1, hs);
                        len += temp2.high - temp2.low;
                        if (hs.high >= temp1.high)
                        {
                            hs.low -= hslen;
                            hs.high -= hslen;
                            break;
                        }
                    }
                }
                if (ms.high >= hm.high)
                {
                    ms.low -= mslen;
                    ms.high -= mslen;
                    break;
                }
            }
        }
        cout << setprecision(3) << fixed << len / (432 * F) << endl;
    }
    return 0;
}