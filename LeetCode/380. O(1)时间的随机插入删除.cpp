/**
 * @file 380. O(1)时间的随机插入删除.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet
{
private:
    std::vector<int> elements;               // 存储集合中的元素
    std::unordered_map<int, int> valToIndex; // 哈希表，映射元素到索引

public:
    // 构造函数，初始化数据结构
    RandomizedSet() {}

    // 插入元素
    bool insert(int val)
    {
        // 若元素已存在于集合中，则返回 false
        if (valToIndex.count(val))
            return false;

        // 否则将元素添加到动态数组的末尾，并更新哈希表
        elements.push_back(val);
        valToIndex[val] = elements.size() - 1;
        return true;
    }

    // 移除元素
    bool remove(int val)
    {
        // 若元素不存在于集合中，则返回 false
        if (!valToIndex.count(val))
            return false;

        // 获取要删除元素的位置
        int index = valToIndex[val];
        int lastElement = elements.back(); // 获取数组的最后一个元素

        // 将最后一个元素移到待删除元素的位置
        elements[index] = lastElement;
        valToIndex[lastElement] = index;

        // 移除数组末尾的最后一个元素，同时从哈希表中移除该元素
        elements.pop_back();
        valToIndex.erase(val);
        return true;
    }

    // 随机获取一个元素
    int getRandom()
    {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};
