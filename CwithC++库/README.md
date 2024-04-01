# 说明

	使用cpp文件，但用c语言的语法实现。可以使用cpp的库；但不要使用cpp的新语法。记得在每行代码上加上注释

- 头文件模板

```
#include <cstdio> // 引入C语言的标准输入输出
#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search，min， max， max_element，count，find
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <iomanip> // 引入控制输入格式的库 io manipunation
#include <string> // 引入C++的string类
#include <vector>
#include <tuple>
#include <queue>
#include <fstream> // 文件流
/**
accumulate是C++中的一个函数，定义在<numeric>头文件中。它主要用来对指定范围内的元素进行求和，但也可以自定义一些其他操作，如范围内所有元素相乘、相除等
*/
#include <numeric> // accumulate
#include <cctype> //isalpha，isalnum，isdigit函数，参数是字符数字(其实是int型)，islower，toupper
#include <cmath> // sqrt、pow、abs

using namespace std; //使用标准命名空间，省去写std::
```