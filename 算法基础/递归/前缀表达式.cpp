#include <stdio.h>
#include <cstdlib>
double exp(){
    char s[20];
    /**
     * 这是因为在C语言中，scanf函数会从标准输入（通常是键盘）读取数据。
     * 在程序中，scanf函数被配置为读取一个字符串，直到遇到空格、制表符或换行符。
     * 当输入+ 2 3并按下回车键时，scanf函数首先读取+，然后由于遇到了空格，它停止读取并将+存储在字符串s中。
     * 然后，当exp函数递归调用自身时，scanf函数再次被调用，这次它读取2，因为2后面又是一个空格，所以scanf函数停止读取并将2存储在字符串s中。
     * 这就是为什么在第一次递归调用exp函数时，scanf函数读取的是2。
     * 
     */
    scanf("%s",s);
    switch (s[0])
    {
        case '+':
            return exp()+exp();
        case '-':
            return exp()-exp();
        case '/':
            return exp()/exp();   
        case '*':
            return exp()*exp(); 
        default: return atof(s);
        break;
    }
}
int main()
{
    printf("%lf",exp());
    return 0;
}