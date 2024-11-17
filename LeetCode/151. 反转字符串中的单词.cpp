/**
 * @file 151. 反转字符串中的单词.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
示例 1：
    输入：s = "the sky is blue"
    输出："blue is sky the"
 * 解题思路：见代码
 * 时间复杂度：O(n)
 * @version 0.1
 * @date 2024-11-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size(); // 获取字符串 s 的长度
        int i, j = 0;     // i 和 j 用于遍历和定位单词
        string res = "";  // 初始化结果字符串 res

        for (i = 0; i < n;) // 遍历整个字符串 s
        {
            while (i < n && s[i] == ' ') // 跳过空格，找到单词的起始位置
                i++;

            if (i >= n)
                break; // 如果遍历到末尾，退出循环,避免最前方出现空格

            j = i;                       // 将 j 设为当前单词的起始位置
            while (j < n && s[j] != ' ') // 找到单词的结束位置
                j++;

            // 提取单词并插入到 res 的最前面，用空格隔开
            res = s.substr(i, j - i) + " " + res;

            i = j; // 更新 i 到下一个单词的起始位置
        }

        // 删除最后一个多余的空格，返回结果字符串
        return res.substr(0, res.size() - 1);
    }
};

/*
方法2：
// 改进思路
// 移除多余空格：可以先移除多余空格，包括前导、尾随空格以及单词之间的多余空格。
// 反转整个字符串：将整个字符串反转，这样每个单词的顺序就被颠倒了。
// 反转每个单词：在已经反转的字符串上，再逐个反转单词的字符，从而将每个单词调整回正向
// 避免拼接字符串带来的性能损耗
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string reverseWords(string s) 
    {
        // 1. 移除多余空格
        removeExtraSpaces(s);

        // 2. 反转整个字符串
        reverse(s.begin(), s.end());

        // 3. 逐个反转每个单词
        int start = 0, end = 0, n = s.size();
        while (start < n) 
        {
            // 定位到单词结尾
            while (end < n && s[end] != ' ') 
                end++;
            // 反转单词
            reverse(s.begin() + start, s.begin() + end);
            // 更新 start 和 end，指向下一个单词
            start = end + 1;
            end = start;
        }

        return s;
    }

private:
    void removeExtraSpaces(string& s) 
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) 
        {
            if (s[fast] != ' ' || (slow > 0 && s[slow - 1] != ' ')) 
            {
                s[slow++] = s[fast];
            }
        }
        s.resize(slow > 0 && s[slow - 1] == ' ' ? slow - 1 : slow); // 去掉结尾多余空格
    }
};



*/