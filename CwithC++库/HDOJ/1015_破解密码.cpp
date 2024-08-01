/**
 * @file 1015_破解密码.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-01
 * 
 * @copyright Copyright (c) 2024
 * Question:
 * A=1, B=2, ..., Z=26;
 * v - w^2 + x^3 - y^4 + z^5 = target （v, w, x, y, z是变量）
 * 从句子（字母集）找到5个字母满足上面等式。
 * 如果存在多个解决方案，那么该组合就是字典序上最大的一个
 * 输入：
 * Target, 句子（字母集）
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 将字母转换为对应的序数值（A=1, B=2, ..., Z=26）
int letter_to_number(char letter) {
    return letter - 'A' + 1;
}

// 计算给定五个字母值的方程结果
int calculate_value(int v, int w, int x, int y, int z) {
    return v - pow(w, 2) + pow(x, 3) - pow(y, 4) + pow(z, 5);
}

// 查找满足方程的最佳组合
string find_combination(int target, const string& letters) {
    string best_combination = "no solution"; // 初始化最佳组合为 "no solution"
    vector<int> indices(letters.size()); // 创建一个索引数组
    for (int i = 0; i < letters.size(); ++i) {
        indices[i] = i; // 将索引数组初始化为 0, 1, 2, ..., letters.size() - 1
    }

    vector<int> combination(5); // 创建一个大小为5的组合数组
    do {
        for (int i = 0; i < 5; ++i) {
            combination[i] = indices[i]; // 选择前5个索引
        }
        sort(combination.begin(), combination.end(), greater<int>()); // 按逆序排序组合
        
        // 将字母转换为对应的序数值
        int v = letter_to_number(letters[combination[0]]);
        int w = letter_to_number(letters[combination[1]]);
        int x = letter_to_number(letters[combination[2]]);
        int y = letter_to_number(letters[combination[3]]);
        int z = letter_to_number(letters[combination[4]]);
        
        // 如果方程结果等于目标值
        if (calculate_value(v, w, x, y, z) == target) {
            string current_combination;
            for (int i : combination) {
                current_combination += letters[i]; // 将组合转换为字符串
            }
            // 更新最佳组合
            if (best_combination == "no solution" || current_combination > best_combination) {
                best_combination = current_combination;
            }
        }
    } while (next_permutation(indices.begin(), indices.end())); // 生成下一个排列

    return best_combination; // 返回最佳组合
}

int main() {
    string line;
    while (getline(cin, line)) { // 读取每一行输入
        if (line == "0 END") break; // 如果输入是 "0 END"，退出循环
        
        size_t space_pos = line.find(' '); // 找到空格的位置
        int target = stoi(line.substr(0, space_pos)); // 提取目标值
        string letters = line.substr(space_pos + 1); // 提取字母
        
        string result = find_combination(target, letters); // 查找最佳组合
        cout << result << endl; // 输出结果
    }

    return 0;
}
