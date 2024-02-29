#include <set>
#include <iostream>

/**
C++中有类似Python集合的数据结构。
在C++标准库中，std::set和std::unordered_set类提供了类似Python集合的功能。

std::set：这是一个有序集合，它会自动对元素进行排序。
std::set中的元素必须是唯一的，也就是说，同一个值只能在集合中出现一次。
std::unordered_set：这是一个无序集合，它不会对元素进行排序。
std::unordered_set中的元素也必须是唯一的
*/

int main() {
    std::set<int> s;

    // 插入元素
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // 检查集合是否为空
    if (!s.empty()) {
        std::cout << "Set is not empty\n";
    }

    // 获取集合的大小
    std::cout << "Size of set: " << s.size() << '\n';

    // 查找元素
    /**
    s.find(2) != s.end()这个表达式用于检查元素2是否存在于集合s中。

	s.find(2)是一个函数调用，它会在集合s中查找元素2。
    如果找到了元素2，那么find函数就会返回一个指向该元素的迭代器。
    如果没有找到元素2，那么find函数就会返回s.end()，
	这是一个特殊的迭代器，表示集合s的“结束位置”，
    也就是集合s中最后一个元素之后的位置。

	!=是一个比较运算符，用于比较两个迭代器是否不相等。
	s.end()返回一个指向集合s的“结束位置”的迭代器。

	所以，s.find(2) != s.end()这个表达式的意思是：
    “在集合s中查找元素2，如果找到了
    （也就是说，find函数返回的迭代器不等于s.end()），
    那么结果为true；如果没有找到
    （也就是说，find函数返回的迭代器等于s.end()），那么结果为false”
    */
    if (s.find(2) != s.end()) {
        std::cout << "Element 2 found in set\n";
    }

    // 删除元素
    s.erase(2);

    // 遍历集合
    for (int i : s) {
        std::cout << i << ' ';
    }

    // 清空集合
    s.clear();

    return 0;
}
