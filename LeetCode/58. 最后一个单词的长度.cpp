/**
 * @file 58. 最后一个单词的长度.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 
 * 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个单词的长度。
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串

示例 1：
    输入：s = "Hello World"
    输出：5
    解释：最后一个单词是“World”，长度为 5。

 * 解题思路：从后往前找空格，计算单词长度，最后返回长度
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            res++;
            i--;
        }
        return res;
    }
};