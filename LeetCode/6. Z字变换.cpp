/**
 * @file 6. Z字变换.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
    P   A   H   N
    A P L S I I G
    Y   I   R
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);

示例 1：
    输入：s = "PAYPALISHIRING", numRows = 3
    输出："PAHNAPLSIIGYIR"
示例 2：
    输入：s = "PAYPALISHIRING", numRows = 4
    输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：
    输入：s = "A", numRows = 1
    输出："A"

 * 解题思路：数学题
 * 示例3的L下标：
 * 该周期第一个元素的下标 + 周期长度 - 当前行的偏移量
 * cycleLen = 2 * numRows - 2 = 6;
 * 0 + 6 - 1 = 5 (减一是因为要从 0 开始)
 * @version 0.1
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        // 如果只有 1 行，不需要进行 Z 字形变换，直接返回原字符串
        if (numRows == 1) return s;

        string res; // 最终结果字符串
        int n = s.size(); // 原字符串的长度
        int cycleLen = 2 * numRows - 2; // 每个 Z 字形周期的长度

        // 遍历每一行
        for (int i = 0; i < numRows; i++)
        {
            // 遍历每个周期中的字符
            for (int j = i; j < n; j += cycleLen)
            {
                // 添加当前行中的字符（垂直方向的字符）
                res += s[j];

                // 添加 Z 字形对角线的字符（适用于非首行和非末行）
                if (i != 0 && i != numRows - 1 && j + cycleLen - 2 * i < n)
                    res += s[j + cycleLen - 2 * i]; // 该周期的第i行第一个元素下标 加上 周期长度 减去 当前行的偏移量 再减i
                    // 即j + cycleLen - 2 * i
            }
        }
        
        return res; // 返回最终的 Z 字形变换结果字符串
    }
};
