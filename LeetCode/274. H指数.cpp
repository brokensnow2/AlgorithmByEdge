/**
 * @file 274. H指数.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
 * 根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。
 * 如果 h 有多种可能的值，h 指数 是其中最大的那个。
 * 示例 1：
    输入：citations = [3,0,6,1,5]
    输出：3
    解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
        由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。

 * 解题思路: 排序，找到最大的h指数，满足至少 i + 1 篇论文被引用至少 i + 1 次，即 h = i + 1
 * 时间复杂度：O(nlogn)， 空间复杂度：O(1) --不考虑排序的额外空间
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // 首先对引用次数数组降序排序
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;

        // 遍历排序后的数组，找出最大的 H 指数
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= i + 1)
            { // 检查是否满足至少 i + 1 篇论文被引用至少 i + 1 次
                h = i + 1;
            }
            else
            {
                break; // 如果不满足条件，停止搜索
            }
        }
        return h;
    }
};

