/**
在C++中，字典通常由`std::map`或`std::unordered_map`实现。这两种类型都提供了一种有效的方式来存储键值对，其中键和值可以是任何类型。

以下是`std::map`的初始化和常用方法：

## 初始化
你可以使用多种方式来初始化一个`std::map`对象：

```cpp
std::map<int, std::string> map1;  // 默认初始化，此时map1为空
std::map<int, std::string> map2(map1);  // 使用另一个map对象map1来初始化map2
std::map<int, std::string> map3 = map1;  // 使用另一个map对象map1来初始化map3
std::map<int, std::string> map4{{1, "one"}, {2, "two"}, {3, "three"}};  // 列表初始化，map4包含元素1->"one", 2->"two", 3->"three"
```

## 常用方法
`std::map`对象提供了一系列方法来操作字典：

- `begin()`: 返回一个迭代器，指向字典中的第一个元素。
- `end()`: 返回一个迭代器，指向字典中最后一个元素的下一个位置。
- `size()`: 返回字典中元素的数量。
- `empty()`: 如果字典为空，返回`true`，否则返回`false`。
- `insert()`: 在字典中插入一个元素。元素是一个键值对，通常以`std::pair`的形式给出。
- `erase()`: 删除字典中的一个元素或一范围的元素。
- `find()`: 查找字典中是否存在某个键，如果存在，返回指向该键值对的迭代器，否则返回`end()`。
- `count()`: 返回字典中等于给定键的元素的数量。对于`map`，这个数量只能是0或1。
- `clear()`: 删除字典中的所有元素。

*/

/**
在C++中，如果你尝试访问`std::map`中不存在的键，例如`map[key1]`，那么`std::map`会自动创建一个新的键值对，键为`key1`，值为该类型的默认值。
对于大多数类型，例如`int`、`float`、`double`等，默认值为0。
对于类类型，例如`std::string`，默认值为该类型的默认构造函数创建的对象（对于`std::string`，这将是一个空字符串）。

这种行为与Python的字典有所不同。在Python中，如果你尝试访问字典中不存在的键，例如`dict[key1]`，Python会抛出一个`KeyError`异常。

这就是C++的`std::map`和Python的字典在处理不存在的键时的主要区别。在使用这两种数据结构时，需要注意这种区别，以避免出现意外的行为。

以下是一个C++的例子：

```cpp
std::map<int, std::string> m;
std::cout << m[1] << std::endl;  // 输出一个空字符串
```

以下是一个Python的例子：

```python
d = {}
print(d[1])  # 抛出KeyError异常
```

*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    // 创建一个空的映射
    map<string, int> m;

    // 插入元素
    m["apple"] = 1;
    m["banana"] = 2;
    m["cherry"] = 3;

    // 访问元素
    cout << "apple: " << m["apple"] << endl;

	for (int i = 0; i < 2; i++)
    {
        // 检查元素是否存在
    	if (m.find("banana") != m.end()) {
        	cout << "banana exists" << endl;
        	m.erase("banana");
    	} else {
        	cout << "banana does not exist" << endl;
        	m.insert({"banana", 5});
    	}
    }
    
    // 遍历元素
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    // 或者
    for (auto i : m){
        cout << i.first << endl; // map遍历时返回的是pair模板类
    }

    // 删除元素
    m.erase("cherry");

    return 0;
}

/**
 * Python 的 dict 和 set 类型是使用哈希表实现的，
 * 这使得它们在插入和查找操作上的平均时间复杂度为 O(1)
 * 
 * 相比之下，C++ 的 std::map 是一个关联容器，它存储键值对，并且键是唯一的。std::map 的键是有序的，这个顺序是通过比较函数 Compare 来定义的。
 * 在底层实现上，std::map 通常使用红黑树。
 * 红黑树是一种自平衡的二叉查找树，
 * 它的查找、插入和删除操作的时间复杂度都是对数级别的
 * 
Python 的 `dict` 和 C++ 的 `std::map` 都是关联容器，用于存储键值对。
然而，它们在实现和性能上有一些重要的区别：

- **实现**：Python 的 `dict` 是使用哈希表实现的³，
这使得它们在插入和查找操作上的平均时间复杂度为 O(1)。
相比之下，C++ 的 `std::map` 通常使用红黑树¹，这是一种自平衡的二叉查找树，
它的查找、插入和删除操作的时间复杂度都是对数级别的¹。

- **键的顺序**：由于 `std::map` 使用的是红黑树，所以它的键是有序的，
这个顺序是通过比较函数 `Compare` 来定义的¹。
而 Python 的 `dict` 在 Python 3.7 及以后的版本中，会保持插入顺序，
但这并不是由于某种内部排序，而是由于其特定的实现。

- **灵活性**：Python 的 `dict` 可以使用任何可哈希的对象作为键，这使得它在使用上更为灵活。而 C++ 的 `std::map` 需要能够对键进行排序，这就要求键必须支持比较操作¹。

总的来说，Python 的 `dict` 和 C++ 的 `std::map` 都是实现键值对存储的有效工具，但由于它们的实现差异，它们在性能和使用上有一些不同。
 * 
*/
