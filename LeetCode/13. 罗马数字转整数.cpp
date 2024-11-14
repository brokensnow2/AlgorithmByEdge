/**
 * @file 13. 罗马数字转整数.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 
 * 罗马数字包含以下七种字符: I, V, X, L,C,D 和 M。
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 例如， 罗马数字 2 写做 II ,即为两个并列的 1。12 写做 XII ,即为 X + II 。 
 * 27 写做  XXVII, 即为 XX + V + II 。
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
 * 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
    * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。
示例 1:
    输入: s = "III"
    输出: 3

 * 解题思路：遍历字符串，每次取出一个字符，进行判断，然后进行转换
 * 时间复杂度：O(n)
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int length = s.length();
        int ans = 0;
        for (int i = 0; i < length; i++)
        {
            if (s[i] == 'I')
            {
                if (i < length - 1 && s[i+1] == 'V')
                {
                    ans += 4;
                    i++;
                }
                else if (i < length -1 && s[i+1] == 'X')
                {
                    ans += 9;
                    i++;
                }
                else
                {
                    ans += 1;
                }
            }
            else if (s[i] == 'X')
            {
                if (i < length - 1 && s[i+1] == 'L')
                {
                    ans += 40;
                    i++;
                }
                else if (i < length -1 && s[i+1] == 'C')
                {
                    ans += 90;
                    i++;
                }
                else
                {
                    ans += 10;
                }
            }
            else if (s[i] == 'C')
            {
                if (i < length - 1 && s[i+1] == 'D')
                {
                    ans += 400;
                    i++;
                }
                else if (i < length -1 && s[i+1] == 'M')
                {
                    ans += 900;
                    i++;
                }
                else
                {
                    ans += 100;
                }
            }
            else if (s[i] == 'V')
            {
                ans += 5;
            }
            else if (s[i] == 'L')
            {
                ans += 50;
            }
            else if (s[i] == 'D')
            {
                ans += 500;
            }
            else if (s[i] == 'M')
            {
                ans += 1000;
            }
        }
        return ans;
    }
};

/* 
//方法2：
//用 一次遍历 和 哈希表 的方式来优化。
//主要思路是，如果某个字符比下一个字符表示的数值小，那么它是一个特例，需要减去这个值；
//否则直接加上当前字符的数值。
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            // 如果当前字符比下一个字符小，减去当前字符的值
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
            {
                result -= romanMap[s[i]];
            }
            else
            {
                result += romanMap[s[i]];
            }
        }

        return result;
    }
};



*/