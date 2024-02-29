# include <stdio.h>
/**
scanf()函数是C语言中的一个输入函数，它从标准输入（通常是键盘）读取数据。

在Windows和DOS中，终端不会产生EOF（End Of File）。
当你从键盘输入数据时，应用程序会知道数据源是一个终端（或者其他“字符设备”），
并将一个已知的保留的字符或序列解释为文件结束的指示。最普遍的说法是，
它是ASCII码中的替换字符（Control-Z，代码）。

在Linux和Unix系统中，你可以通过按下Ctrl+D来生成EOF。

scanf()函数的返回值等于成功读入的数据项数。
如果读入数据时遇到了“文件结束”，则返回EOF。
例如，scanf("%d %d",&a,&b);如果a和b都被成功读入，
那么scanf的返回值就是2；如果只有a被成功读入，返回值为1

*/

/*
在C语言中，scanf("%d %d",&a,&b);和scanf("%d%d",&a,&b);
在功能上没有区别。
这两个函数都会从输入中读取两个整数，并将它们分别存储在变量a和b中
*/

/*
freopen用来重定向输入和输出
freopen函数是C标准库的一部分。它用于将一个新文件与给定的打开流关联，同时关闭与该流关联的旧文件。
以下是freopen函数的声明
FILE *freopen(const char *filename, const char *mode, FILE *stream);

filename：这是一个C字符串，包含要打开的文件的名称。

mode：这是一个C字符串，包含文件访问模式。它可以是：
"r"：打开一个现有文件进行读取。
"w"：创建一个空文件进行写入。如果已存在同名文件，其内容将被丢弃。
"a"：向文件追加。写操作在文件末尾追加数据。如果文件不存在，则创建文件。
"r+"：打开一个现有文件进行读写。
"w+"：创建一个空文件进行读写。如果已存在同名文件，其内容将被丢弃。
"a+"：打开一个文件进行读写。所有写操作在文件末尾追加数据。如果文件不存在，则创建文件。

stream：这是一个指向FILE对象的指针，该对象标识要重新打开的流。
如果文件成功打开，函数返回一个指向标识流的对象的指针。否则，它返回一个空指针。
*/
int main()
{
    int num;
    int array[20];
    int i = 0;
    freopen("/root/AlgorithmByEdge/CwithC++库/常见模版/C_Read.txt","r",stdin);
    while (scanf("%d",&num) != EOF)
    {
        array[i] = num;
        i++;
    }
    for(int j = 0; j < i; j++)
    {
        printf("%d ",array[j]);
    }
	printf("\n")
	
	//去往标准输出的输出被重定向到名为myfile.txt的文件。
    freopen("./myfile.txt", "w", stdout);
    printf("This sentence is redirected to a file.");
    fclose(stdout);
    return 0;
}
