/**
 * @file 134. 加油站.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
 * 你从其中的一个加油站出发，开始时油箱为空。
 * 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。
 * 如果存在解，则 保证 它是 唯一 的。
 * @version 0.1
 * @date 2024-11-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total_tank = 0; // 总剩余油量
        int curr_tank = 0;  // 当前油量
        int start = 0;      // 起点

        for (int i = 0; i < gas.size(); i++)
        {
            int fuel_diff = gas[i] - cost[i];
            total_tank += fuel_diff;
            curr_tank += fuel_diff;

            // 如果当前油量不足，说明从 start 到 i 无法完成绕行
            if (curr_tank < 0)
            {
                start = i + 1; // 重置起点为 i + 1
                curr_tank = 0; // 重置当前油量
            }
        }

        return total_tank >= 0 ? start : -1;
    }
};
