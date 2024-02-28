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
int main()
{
    int num;
    int array[20];
    int i = 0;
    while (scanf("%d",&num) != EOF)
    {
        array[i] = num;
        i++;
    }
    for(int j = 0; j < i; j++)
    {
        printf("%d ",array[j]);
    }
    return 0;
}
