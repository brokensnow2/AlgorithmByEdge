# 说明

	使用cpp文件，但用c语言的语法实现。可以使用cpp的库；但不要使用cpp的新语法。记得在每行代码上加上注释

- 头文件模板

```
extern "C" {
#include <stdio.h> // 引入C标准输入输出库：scanf，printf
#include <string.h> // 引入字符串处理库：strcat，strcmp
}

#include <sstream> // 引入字符串流库：istringstream iss()
#include <algorithm> // 引入C++的算法库：sort，binary_search
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <vector>
#include <tuple>
#include <queue>

using namespace std; //使用标准命名空间，省去写std::
```