#include <iostream> // 引入输入输出库
#include <vector>   // 引入向量库
/**
在C++中，`std::vector`是一种动态数组，它可以在运行时改变大小。下面是一些基本的`std::vector`用法：

1. **创建vector**：你可以使用`std::vector<T>`来创建一个类型为`T`的向量，其中`T`可以是任何类型，例如`int`，`double`，`std::string`等。

    ```cpp
    std::vector<int> v; // 创建一个空的整型向量
    ```

2. **添加元素**：你可以使用`push_back`函数来在向量的末尾添加一个元素。

    ```cpp
    v.push_back(10); // 在向量v的末尾添加一个元素10
    ```

3. **访问元素**：你可以使用下标运算符`[]`来访问向量中的元素。

    ```cpp
    int x = v[0]; // 获取向量v中的第一个元素
    ```

4. **获取向量的大小**：你可以使用`size`函数来获取向量中的元素数量。

    ```cpp
    int n = v.size(); // 获取向量v中的元素数量
    ```

5. **遍历向量**：你可以使用for循环或者迭代器来遍历向量中的所有元素。

    ```cpp
    // 使用for循环遍历向量
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }

    // 使用迭代器遍历向量
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << ' ';
    }
    ```

6. **删除元素**：你可以使用`erase`函数来删除向量中的元素。

    ```cpp
    v.erase(v.begin()); // 删除向量v中的第一个元素
    ```

7. **清空向量**：你可以使用`clear`函数来删除向量中的所有元素。

    ```cpp
    v.clear(); // 删除向量v中的所有元素
    ```

*/
int main() {
    // 创建一个2x3的二维向量
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 输出二维向量的内容
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0; // 程序正常结束
}
