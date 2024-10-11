#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // 不加left右对齐，不然左对齐
    cout << left << setw(10) << setfill(' ') << "Hello" << endl;
	cout << "World" << endl;

	int num = 42;
    cout << setw(5) << setfill('0') << num << endl;
    cout << hex << num << endl;
    
    double pi = 3.14159;
	cout << setw(7) << setfill('0') << fixed << setprecision(3) << pi << endl;

}

/**
 * cin是C++中的一个对象，它代表标准输入流，通常是键盘。
 * 它是iostream库的一部分。

在C++中，你可以使用cin对象从标准输入读取数据。
例如，你可以使用cin >> a;从标准输入读取一个整数，并将其存储在变量a中。

cin对象的>>运算符被称为“提取运算符”。
它从输入流中提取值，并将其存储在给定的变量中。例如，cin >> a >> b;会从输入流中提取两个整数，并将它们分别存储在变量a和b中。

cin对象也有一个名为eof()的成员函数，
它可以用来检测是否已经到达文件的末尾（EOF）。
如果已经到达文件的末尾，那么eof()函数将返回true；否则，它将返回false。

在Windows和DOS中，你可以通过按下Ctrl+Z来生成EOF。
而在Linux和Unix系统中，你可以通过按下Ctrl+D来生成EOF。

注意，cin对象在遇到空白字符（空格、制表符或换行符）时，会停止读取，而不是丢弃这些字符。
这意味着，如果你使用cin对象从标准输入读取数据，然后按下回车，那么这个回车符并不会被cin对象读取，但它会留在缓冲区里。

然后，如果你接下来使用getchar()函数，那么这个函数会从缓冲区中读取下一个字符。
因为前面的回车符还在缓冲区里，所以getchar()函数会读取到这个回车符。
 * 
*/

/*
`cout` 是 C++ 标准库中的一个用于输出数据到标准输出（通常是终端或控制台）的对象。它属于输入输出流库（I/O stream library），是标准输出流（standard output stream）的代表。`cout` 的类型是 `std::ostream`，属于 `iostream` 头文件的一部分。我们来一步步分析 `cout` 的实现及其特性。

### 1. `cout` 是什么？

`cout` 是一个全局对象，表示标准输出流，定义在 `<iostream>` 头文件中。`cout` 的全称是 "character output"，用于将数据输出到标准输出设备。默认情况下，标准输出设备是控制台。

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

### 2. `<<` 运算符的工作原理

`<<` 是一种被称为**插入运算符**（insertion operator）的运算符，用来将数据插入到输出流中。其工作原理是通过重载运算符 `operator<<`，来支持不同类型的数据插入流中。

`cout` 实际上是一个 `std::ostream` 对象，而 `operator<<` 在 `ostream` 类中被多次重载，以支持多种不同类型的数据输出（如 `int`、`char`、`std::string` 等）。每次你使用 `<<` 时，C++ 会根据插入的值的类型调用合适的重载函数。

示例：
```cpp
std::cout << "Age: " << 25 << " years old." << std::endl;
```

1. `"Age: "` 是字符串，调用了 `ostream& operator<<(ostream&, const char*)`；
2. `25` 是整数，调用了 `ostream& operator<<(ostream&, int)`；
3. `" years old."` 是字符串，调用了 `ostream& operator<<(ostream&, const char*)`；
4. `std::endl` 是特殊符号，用于换行并刷新缓冲区，调用了 `ostream& operator<<(ostream&, std::ostream& (*)(std::ostream&))`。

由于 `<<` 运算符返回的是输出流对象的引用，所以多个 `<<` 可以连用。这种特性使得我们可以在一条语句中连续输出多个值。

### 3. 输出流的内部实现

C++ 的输出流通过缓冲机制将数据输出到设备（如控制台或文件）。通常，数据会先进入缓冲区，等到缓冲区满了或手动刷新时，数据才会真正输出到设备。`std::endl` 就是一种刷新缓冲区的方法。

主要步骤包括：

1. **缓冲区**：数据首先进入缓冲区。
2. **流刷新**：缓冲区满时自动刷新，或者在调用 `std::endl` 时手动刷新。
3. **输出设备**：数据从缓冲区输出到标准输出设备，如控制台。

这种机制提高了性能，因为避免了频繁的设备 I/O 操作。

### 4. `<<` 运算符的链式调用

`operator<<` 返回的是 `std::ostream&` 类型的引用。这意味着每次调用 `<<` 后，你得到的仍然是 `cout`，可以继续使用它输出下一个值。链式调用机制的实现如下：

```cpp
std::ostream& operator<<(std::ostream& os, const int value) {
    // 输出整数值到输出流中
    os.put(...);
    return os;  // 返回引用
}
```

每次调用 `<<` 后，`cout` 对象的引用被返回，从而允许后续继续使用 `<<`。

### 5. `cout` 输出到哪里？

默认情况下，`cout` 输出到标准输出设备，这通常是命令行终端。如果你想改变输出目的地，可以通过重定向标准输出到文件或其他设备。例如：

#### 重定向输出到文件
你可以使用 C++ 文件流 (`fstream`) 将输出重定向到文件：

```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << "This will be written to the file!" << std::endl;
        file.close();
    }
    return 0;
}
```

#### 使用 `freopen` 重定向 `cout`

你还可以使用 `freopen` 将 `cout` 重定向到文件：

```cpp
#include <iostream>
#include <cstdio>

int main() {
    freopen("output.txt", "w", stdout);
    std::cout << "This will be written to output.txt" << std::endl;
    return 0;
}
```

在这段代码中，`freopen` 函数将标准输出重定向到文件 `output.txt`，从而 `cout` 的所有输出将被写入文件。

### 6. 总结

- `cout` 是 C++ 标准库中的标准输出流，通常输出到控制台。
- `<<` 是插入运算符，通过运算符重载支持各种类型的数据输出，并通过返回流对象的引用支持链式调用。
- 数据先进入缓冲区，缓冲区满或调用 `std::endl` 后输出到设备。
- `cout` 可以通过文件流或 `freopen` 重定向到文件或其他输出设备。

这个机制的灵活性使得 C++ 的输入输出系统既高效又易于使用。




*/