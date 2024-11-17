/**
 * @file 14. 最长公共前缀.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
示例 1:
    输入：strs = ["flower","flow","flight"]
    输出："fl"

 * 解题思路：见代码
 * 时间复杂度：O(m * n) m为字符串个数，n为字符串最大长度
 * 空间复杂度：O(1)
 * @version 0.1
 * @date 2024-11-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string>
#include <vector>
using namespace std;

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                ++j;
            }
            prefix = prefix.substr(0, j); // 更新前缀
            if (prefix.empty())
                return ""; // 无公共前缀，直接返回
        }
        return prefix;
    }
};
/*
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(res) != 0)
                res = res.substr(0, res.size() - 1);
        }
        return res;
    }
};
*/