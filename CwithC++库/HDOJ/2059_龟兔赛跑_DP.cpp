#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int L; // 总距离
    int N, C, T; // 充电桩数量， 最大行驶距离， 充电时间
    int vr, vt, vt2; // 兔子速度，乌龟开电动车的速度，乌龟脚蹬电动车的速度
    while (cin >> L)
    {
        cin >> N >> C >> T;
		vector<int> distance(N+2); // 各个充电站离跑道起点的距离
        cin >> vr >> vt >> vt2;
        for (int i = 1; i < N+1; i++)
            cin >> distance[i];
        distance[N+1] = L; // 终点到起点的距离
        vector<double> dp(N+2, 0); // dp[0] = 0; dp[1]:到第一个充电桩的最优时间
        //? 当然，dp[n+1]就是终点
        // 求dp[i]
        for (int i = 1; i < N+2; i++)
        {
            double min = 1e9;
            // 计算从dp[0]到dp[i-1]到i的最优解
            for (int j = 0; j < i; j++)
            {
				int len = distance[i] - distance[j];
                // 在j处充电的情况下是否更优
				int e = len > C ? 1.0 * C / vt + (len - C + 0.0) / vt2 : 1.0 * len / vt;
				e += dp[j];
				if (j) // 非起点
                	e += T;
				if (min > e) // 不然在j处不充电，在之前充电更优
                	min = e;
            }
            dp[i] = min;
        }
		cout << (1.0 * L / vr > dp[N+1] ? "What a pity rabbit!" : "Good job,rabbit!") << endl;
    }
}