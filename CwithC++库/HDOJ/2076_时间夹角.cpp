#include<iostream>
#include<cmath>
/**
 * 首先，我们需要将小时、分钟和秒转换为度数。因为一小时有60分钟，一分钟有60秒，所以我们可以将时间转换为度数。
 * 具体来说，每小时代表30度（360度/12小时），每分钟代表0.5度（30度/60分钟），每秒代表约0.00833度（0.5度/60秒）。
 * 然后，我们可以计算时针和分针的位置。
 * 时针的位置等于小时数乘以每小时的度数，加上分钟数乘以每分钟的度数，再加上秒数乘以每秒的度数。
 * 分针的位置等于分钟数乘以每分钟的度数，再加上秒数乘以每秒的度数。
 * 最后，我们可以计算时针和分针的夹角。夹角等于时针的位置减去分针的位置的绝对值。如果夹角大于180度，我们需要从360度中减去这个夹角，以确保夹角在0到180度之间。
 * 
*/
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int h, m, s;
        cin >> h >> m >> s;
        double hour_angle = h * 30 + m * 0.5 + s * 0.00833;
        double minute_angle = m * 6 + s * 0.1;
        double angle = abs(hour_angle - minute_angle);
        if(angle > 180)
            angle = 360 - angle;
        cout << (int)angle << endl;
    }
    return 0;
}
