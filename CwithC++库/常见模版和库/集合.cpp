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

/**
在C++中，集合是一种重要的数据结构，它可以存储多个元素，但每个元素只能出现一次。C++标准模板库(STL)提供了多种集合类型，包括`set`、`multiset`、`unordered_set`和`unordered_multiset`等。

下面我们主要讨论`set`这种集合类型的初始化和常用方法：

## 初始化
在C++中，你可以使用多种方式来初始化一个`set`对象：

```cpp
std::set<int> s1;  // 默认初始化，此时s1为空
std::set<int> s2(s1);  // 使用另一个set对象s1来初始化s2
std::set<int> s3 = s1;  // 使用另一个set对象s1来初始化s3
std::set<int> s4{1, 2, 3};  // 列表初始化，s4包含元素1、2、3
```

## 常用方法
`set`对象提供了一系列方法来操作集合：

- `begin()`: 返回一个迭代器，指向集合中的第一个元素。
- `end()`: 返回一个迭代器，指向集合中最后一个元素的下一个位置。
- `size()`: 返回集合中元素的数量。
- `empty()`: 如果集合为空，返回`true`，否则返回`false`。
- `insert()`: 在集合中插入一个元素。
- `erase()`: 删除集合中的一个元素或一范围的元素。
- `find()`: 查找集合中是否存在某个元素，如果存在，返回指向该元素的迭代器，否则返回`end()`。
- `count()`: 返回集合中等于给定值的元素的数量。对于`set`，这个数量只能是0或1。
- `clear()`: 删除集合中的所有元素。

这只是`set`的一部分方法，还有更多的方法可以用来操作集合。
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
