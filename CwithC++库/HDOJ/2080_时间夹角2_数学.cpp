/**
 * 先判断点在哪个象限，在计算夹角sin的值来得到夹角和x轴正方向的夹角
 * 两个点的夹角相减并判断是否小于180度，不然360－他们的夹角
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265358979323846;
using namespace std;

// 计算点(x, y)与x轴正方向的夹角
double calcAngle(double x, double y) {
    double angle = atan2(y, x) * 180.0 / PI;
    if (angle < 0) angle += 360.0;  // 转换到[0, 360)
    return angle;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double angle1 = calcAngle(x1, y1);
        double angle2 = calcAngle(x2, y2);
        double diff = fabs(angle1 - angle2);  // 计算两个角度的差
        if (diff > 180) diff = 360 - diff;  // 如果差大于180度，则用360度减去差
        cout << fixed << setprecision(2) << diff << endl;  // 输出结果，保留两位小数
    }
    return 0;
}
