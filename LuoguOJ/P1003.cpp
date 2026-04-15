/**
题目描述
为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。
一共有 n 张地毯，编号从 1 到 n。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后
铺的地毯覆盖在前面已经铺好的地毯之上。

地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。
注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。

输入格式
输入共 n+2 行。

第一行，一个整数 n，表示总共有 n 张地毯。

接下来的 n 行中，第 i+1 行表示编号 i 的地毯的信息，
包含四个整数 a,b,g,k，每两个整数之间用一个空格隔开，分别表示铺设地毯的左下角的坐标 (a,b) 
以及地毯在 x 轴和 y 轴方向的长度。

第 n+2 行包含两个整数 x 和 y，表示所求的地面的点的坐标 (x,y)。

输出格式
输出共 1 行，一个整数，表示所求的地毯的编号；
若此处没有被地毯覆盖则输出 -1。

输入输出样例:
输入
3
1 0 2 3
0 2 3 3
2 1 3 3
2 2
输出
3
---

输入 
3
1 0 2 3
0 2 3 3
2 1 3 3
4 5
输出
-1
---

【数据范围】

对于 30% 的数据，有 n≤2。
对于 50% 的数据，0≤a,b,g,k≤100。
对于 100% 的数据，有 0≤n≤10^4, 0≤a,b,g,k≤10^5
 。

*/
#include <bits/stdc++.h>
using namespace std;

struct Carpet {
    int a, b, g, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Carpet> carpets(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> carpets[i].a >> carpets[i].b 
            >> carpets[i].g >> carpets[i].k;
    }

    int x, y;
    cin >> x >> y;

    // 从后往前找
    for (int i = n; i >= 1; i--) {
        int a = carpets[i].a;
        int b = carpets[i].b;
        int g = carpets[i].g;
        int k = carpets[i].k;

        if (x >= a && x <= a + g &&
            y >= b && y <= b + k) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}