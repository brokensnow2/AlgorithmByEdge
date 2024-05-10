/**
 * todo解法2：分治
 * 题目可以归纳为：给出n个点，求n个点两两之间的最小距离。
 * 对于平面上的任意分布的n个点，随机画一条垂直线（铅垂线）可以将平面分为两个区域
 * 形成最小距离的两点要么在这条线左边，要么在这条线右边，要么跨过这条线
 * 求左边区域和右边区域的最小距离同理可以再画一条铅垂线 --分治，只需要考虑跨过这条线的特殊情况
 * 假设左边和右边的最小距离的较小值为d，跨过铅垂线又是最小距离的点则它的x坐标与铅垂线的水平距离一定不会超过d
 * 以最中间的点的x坐标来作为铅垂线的位置，保证总时间复杂度在O(nlogn) --就像归并排序
 * 同时需要对点的x坐标排序来保证划分后数组左边的点落在左边区域
 * 
 * 
*/

#include <bits/stdc++.h> // 包含所有标准库头文件
using namespace std;     // 使用标准命名空间
#define MAXN 100005      // 定义最大点数
#define INF 1e20         // 定义无穷大的值

// 定义点的结构体
struct node
{
    double x, y;      // 点的坐标
} p[MAXN], tmp[MAXN]; // p数组存储所有点，tmp数组用于临时存储

// 比较函数，用于排序
bool cmp(node a, node b)
{
    if (a.x != b.x) // 如果x坐标不同，则按x坐标排序
        return a.x < b.x;
    return a.y < b.y; // 如果x坐标相同，则按y坐标排序
}

// 计算两点之间的距离
double dis(node a, node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 使用分治法找到最近的两个点
double Closest_Pair(int left, int right)
{
    double d = INF;    // 初始化最小距离为无穷大
    if (left == right) // 如果只有一个点，返回无穷大
        return d;
    if (left + 1 == right) // 如果有两个点，返回这两个点之间的距离
        return dis(p[left], p[right]);
    int mid = (left + right) >> 1;            // 找到中点
    double d1 = Closest_Pair(left, mid);      // 递归找到左半部分的最近的两个点
    double d2 = Closest_Pair(mid + 1, right); // 递归找到右半部分的最近的两个点
    d = min(d1, d2);                          // 找到最小的距离
    int cnt = 0;                              // 初始化临时数组的大小为0
    for (int i = left; i <= right; i++)       // 遍历所有的点
    {
        if (fabs(p[mid].x - p[i].x) <= d) // 如果点i到中点的距离小于d，将点i加入临时数组
            tmp[cnt++] = p[i];
    }
    sort(tmp, tmp + cnt, cmp);    // 对临时数组进行排序
    for (int i = 0; i < cnt; i++) // 遍历临时数组
    {
        for (int j = i + 1; j < cnt; j++) // 遍历临时数组中的其他点
        {
            if(tmp[j].y - tmp[i].y > d)
                break;
            double d3 = dis(tmp[i], tmp[j]); // 计算点i和点j之间的距离
            d = min(d, d3);                  // 更新最小距离
        }
    }
    return d; // 返回最小距离
}

// 主函数
int main()
{
    int n;                       // 点的数量
    while (scanf("%d", &n) && n) // 读取点的数量，如果n不为0，继续执行
    {
        for (int i = 0; i < n; i++) // 读取所有的点
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmp);                          // 对所有的点进行排序
        printf("%.2f\n", Closest_Pair(0, n - 1) / 2.0); // 打印最近的两个点之间的距离的一半，即圆环的半径
    }
    return 0; // 程序结束
}
