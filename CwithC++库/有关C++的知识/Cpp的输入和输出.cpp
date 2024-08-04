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