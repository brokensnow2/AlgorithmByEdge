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

    // 检查元素是否存在
    if (m.find("banana") != m.end()) {
        cout << "banana exists" << endl;
    } else {
        cout << "banana does not exist" << endl;
    }

    // 遍历元素
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // 删除元素
    m.erase("cherry");

    return 0;
}
