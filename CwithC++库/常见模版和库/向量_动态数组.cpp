#include <iostream> // 引入输入输出库
#include <vector>   // 引入向量库
/**
在C++中，vector是一个类模板，它是STL（标准模板库）中的一部分。vector可以被看作是一个动态数组
! 回忆cpp的值类型和指针类型；

在C++中，创建对象的常见方式确实是 类类型 对象名(参数)，这种方式会调用类的构造函数来创建对象。
然而，对于vector，它提供了多种创建和初始化的方式。

例如，以下是一些创建和初始化vector的方式：

默认构造函数：创建一个空的vector对象，例如vector<int> myVector;。

指定大小：创建一个指定大小的vector对象，所有元素都被初始化为默认值，例如vector<int> myVector(10);。

指定大小和初始值：创建一个指定大小的vector对象，并给所有元素赋予指定的初始值，例如vector<int> myVector(10, 1);，这将创建一个包含10个元素的vector，每个元素的值都是1。

列表初始化：使用花括号 {} 包含的初始值列表来创建vector对象，例如vector<int> myVector = {1, 2, 3, 4, 5};。

复制构造函数：使用另一个vector对象来创建新的vector对象，例如vector<int> newVector(myVector);，这将创建一个与myVector具有相同元素的新vector。




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
using namespace std;

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
	
    std::vector<int> obj;  // 创建一个vector类的对象obj
	obj.push_back(1);  // 调用obj的push_back方法

	//获取元素的下标
    

    return 0; // 程序正常结束
}
