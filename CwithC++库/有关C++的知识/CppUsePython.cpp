#include <Python.h>
#include <iostream>

int main() {
    // 初始化 Python 解释器
    Py_Initialize();

    // 定义要调用的 Python 脚本和函数
    PyObject* pName = PyUnicode_DecodeFSDefault("script");  // 脚本名（不带 .py 后缀）
    PyObject* pModule = PyImport_Import(pName);             // 加载 Python 模块
    Py_DECREF(pName);                                       // 减少引用计数

    if (pModule != nullptr) {
        // 获取 Python 函数
        PyObject* pFunc = PyObject_GetAttrString(pModule, "hello");  // Python 函数名
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* pValue = PyObject_CallObject(pFunc, nullptr);  // 调用 Python 函数
            if (pValue != nullptr) {
                std::cout << "Function returned successfully!" << std::endl;
                Py_DECREF(pValue);
            }
            else {
                PyErr_Print();  // 打印 Python 错误
            }
        }
        else {
            PyErr_Print();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
    }

    // 关闭 Python 解释器
    Py_Finalize();
    return 0;
}

/**
 * @brief 
 * 
GPT: 是的，你可以在 C++ 程序中调用用 Python 写的功能。有几种方法可以实现这种跨语言调用，最常见的方式包括以下几种：

### 1. 使用 `system()` 函数调用 Python 脚本

这是最简单的方法，C++ 可以通过 `system()` 函数直接调用 Python 解释器来运行一个 Python 脚本。你可以在 Python 脚本中实现你想要的功能，然后通过 `system()` 函数在 C++ 程序中调用它。

#### 示例：
假设有一个 Python 脚本 `script.py`，其内容如下：

```python
# script.py
def hello():
    print("Hello from Python!")

if __name__ == "__main__":
    hello()
```

你可以通过 C++ 中的 `system()` 函数调用它：

```cpp
#include <cstdlib>  // system 函数
#include <iostream>

int main() {
    std::cout << "Calling Python script from C++..." << std::endl;
    system("python3 script.py");
    return 0;
}
```

这种方法的优点是简单直接，但它的局限性在于：无法直接从 C++ 获取 Python 函数的返回值。如果需要进一步的交互或传递复杂数据，这种方式可能不够灵活。

### 2. 使用 Python C API

Python 提供了一个 C API，允许你在 C 或 C++ 代码中嵌入 Python 解释器并调用 Python 函数。这种方式可以更好地与 Python 进行交互，甚至可以在 C++ 中捕获 Python 函数的返回值。

#### 使用 Python C API 的步骤：

1. 包含 `Python.h` 头文件。
2. 初始化 Python 解释器。
3. 调用 Python 函数。
4. 获取返回值（如果需要）。
5. 关闭 Python 解释器。

#### 示例：

首先，确保你的 C++ 编译器能够找到 Python 头文件和库。你可能需要链接 Python 库，使用 `-lpython3.x` 标志（根据你的 Python 版本，`3.x` 可能是 `3.8`、`3.9` 等）。

```cpp
#include <Python.h>
#include <iostream>

int main() {
    // 初始化 Python 解释器
    Py_Initialize();

    // 定义要调用的 Python 脚本和函数
    PyObject* pName = PyUnicode_DecodeFSDefault("script");  // 脚本名（不带 .py 后缀）
    PyObject* pModule = PyImport_Import(pName);             // 加载 Python 模块
    Py_DECREF(pName);                                       // 减少引用计数

    if (pModule != nullptr) {
        // 获取 Python 函数
        PyObject* pFunc = PyObject_GetAttrString(pModule, "hello");  // Python 函数名
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* pValue = PyObject_CallObject(pFunc, nullptr);  // 调用 Python 函数
            if (pValue != nullptr) {
                std::cout << "Function returned successfully!" << std::endl;
                Py_DECREF(pValue);
            }
            else {
                PyErr_Print();  // 打印 Python 错误
            }
        }
        else {
            PyErr_Print();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
    }

    // 关闭 Python 解释器
    Py_Finalize();
    return 0;
}
```

在上面的例子中，`script.py` 文件中应该定义一个 `hello()` 函数：

```python
# script.py
def hello():
    print("Hello from Python via C++!")
```

这段代码使用 Python C API 来调用 Python 函数 `hello()`，并且可以根据需要捕获返回值。C++ 程序加载并执行 Python 模块，然后调用指定函数。

### 3. 使用 Boost.Python

`Boost.Python` 是 Boost 库的一部分，它简化了在 C++ 中调用 Python 的过程。它提供了一个高层次的接口，便于 C++ 与 Python 互操作。

#### 示例：

首先，你需要安装 Boost.Python，并确保 C++ 编译器能够找到相应的头文件和库。

```cpp
#include <boost/python.hpp>
#include <iostream>

int main() {
    // 初始化 Python 解释器
    Py_Initialize();

    try {
        namespace python = boost::python;

        // 加载 Python 模块
        python::object script = python::import("script");

        // 调用 Python 函数
        script.attr("hello")();
    }
    catch (python::error_already_set const &) {
        PyErr_Print();
    }

    // 关闭 Python 解释器
    Py_Finalize();
    return 0;
}
```

对应的 Python 脚本 `script.py`：

```python
# script.py
def hello():
    print("Hello from Boost.Python!")
```

`Boost.Python` 封装了大量细节，使 C++ 调用 Python 更加简洁和易于管理。

### 4. 使用 `pybind11`

`pybind11` 是一个非常轻量的库，专门用于在 C++ 中嵌入 Python 代码或将 C++ 函数导出给 Python 使用。它比 `Boost.Python` 更轻量，且不依赖 Boost 库。

#### 示例：

安装 `pybind11` 后，你可以在 C++ 代码中直接调用 Python 函数。

```cpp
#include <pybind11/embed.h>  // 包含 pybind11 头文件
#include <iostream>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // 启动解释器并保持活动状态

    py::exec(R"(
        def hello():
            print("Hello from pybind11!")
        hello()
    )");

    return 0;
}
```

`pybind11` 是一个更加现代化的选项，它对 C++11 和更高版本的标准有良好支持，使用简单，性能高效。

### 总结

- 如果你只是简单地想调用 Python 脚本，可以使用 `system()`。
- 如果需要更多交互，特别是获取 Python 函数返回值，可以使用 Python C API 或者 `Boost.Python`、`pybind11` 等库。
- `Boost.Python` 提供了强大的功能，但需要安装 Boost 库。
- `pybind11` 是一个轻量、高效的现代化选择，推荐用于现代 C++ 程序。

根据你的需求和项目规模选择合适的方式。
 * 
=========================================================================
=========================================================================
=========================================================================

正在执行任务: D:\mingw64\bin\g++.exe -Wall -Wextra -g3 -IC:/Users/hanyi/AppData/Local/Programs/Python/Python310/include -LC:/Users/hanyi/AppData/Local/Programs/Python/Python310/libs -lpython310 d:\AlgorithmByEdge\CwithC++库\有关C++的知识\CppUsePython.cpp -o d:\AlgorithmByEdge\CwithC++库\有关C++的知识\output\CppUsePython.exe 

C:\Users\hanyi\AppData\Local\Temp\ccht2xiB.o: In function `_Py_DECREF':
C:/Users/hanyi/AppData/Local/Programs/Python/Python310/include/object.h:500: undefined reference to `__imp__Py_Dealloc'
C:\Users\hanyi\AppData\Local\Temp\ccht2xiB.o: In function `main':
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:6: undefined reference to `__imp_Py_Initialize'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:9: undefined reference to `__imp_PyUnicode_DecodeFSDefault'        
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:10: undefined reference to `__imp_PyImport_Import'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:15: undefined reference to `__imp_PyObject_GetAttrString'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:16: undefined reference to `__imp_PyCallable_Check'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:17: undefined reference to `__imp_PyObject_CallObject'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:23: undefined reference to `__imp_PyErr_Print'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:27: undefined reference to `__imp_PyErr_Print'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:33: undefined reference to `__imp_PyErr_Print'
d:/AlgorithmByEdge/CwithC++库/有关C++的知识/CppUsePython.cpp:37: undefined reference to `__imp_Py_Finalize'
collect2.exe: error: ld returned 1 exit status

 *  终端进程“D:\mingw64\bin\g++.exe '-Wall', '-Wextra', '-g3', '-IC:/Users/hanyi/AppData/Local/Programs/Python/Python310/include', '-LC:/Users/hanyi/AppData/Local/Programs/Python/Python310/libs', '-lpython310', 'd:\AlgorithmByEdge\CwithC++库\有关C++的知识\CppUsePython.cpp', '-o', 'd:\AlgorithmByEdge\CwithC++库\有关C++的知识\output\CppUsePython.exe'”已终止，退出代码: 1。



GPT: 从错误信息来看，尽管你已经在编译过程中指定了 Python 的头文件和库文件路径，但链接器仍然提示 "undefined reference" 错误。这通常是由于在 Windows 上使用 MinGW 时，链接的 `.lib` 文件与 MinGW 生成的可执行文件不兼容。Python 的 `.lib` 文件是为 Microsoft Visual Studio (MSVC) 编译器生成的，而不是为 MinGW/gcc 编译器生成的。

### 解决方法：

#### 1. 使用 `python310.dll.a` 文件

MinGW 需要与 Python 的动态库 `.dll` 直接链接，而不是链接 `.lib` 文件。你需要找到或生成一个适合 MinGW 使用的 `python310.dll.a` 文件，这是 `.dll` 的导入库。

1. **找到 `python310.dll.a` 文件**：
   在 `C:\Users\hanyi\AppData\Local\Programs\Python\Python310\libs` 下，看看是否已经存在 `python310.dll.a` 文件。如果存在，可以直接使用它进行链接。

2. **手动生成 `python310.dll.a` 文件**：
   如果你的 Python 安装目录中没有此文件，你可以通过 MinGW 提供的工具生成它。具体步骤如下：
   
   - 找到 `python310.dll` 文件，它应该位于 `C:\Users\hanyi\AppData\Local\Programs\Python\Python310\` 或 `C:\Windows\System32\` 目录中。
   - 使用 `gendef` 和 `dlltool` 命令生成适用于 MinGW 的导入库。

   ```bash
   gendef python310.dll
   dlltool -D python310.dll -d python310.def -l libpython310.dll.a
   ```

   这将生成一个 `libpython310.dll.a` 文件，然后你可以在编译时使用它。

#### 2. 更新编译命令

当你有了 `python310.dll.a` 文件之后，更新编译命令：

```bash
g++ CppUsePython.cpp -IC:/Users/hanyi/AppData/Local/Programs/Python/Python310/include -LC:/path/to/libpython310.dll.a -lpython310 -o CppUsePython.exe
```

注意，将 `C:/path/to/libpython310.dll.a` 替换为 `libpython310.dll.a` 文件的实际路径。

#### 3. 使用 MSYS2 或 WSL 环境

如果以上方法不能解决问题，另一个可靠的选择是使用 **MSYS2** 或 **WSL (Windows Subsystem for Linux)**，它们提供更好的兼容性，特别是在编译与 Python 相关的 C++ 程序时。

### 总结：

- Windows 上的 `.lib` 文件可能不兼容 MinGW，你需要使用 `.dll.a` 文件进行链接。
- 如果没有 `.dll.a` 文件，可以手动生成，确保链接 Python 动态库。
- 如果继续遇到问题，考虑使用 MSYS2 或 WSL 环境，这些提供了更好的 POSIX 支持。
 * 
 */