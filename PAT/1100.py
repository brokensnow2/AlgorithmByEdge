"""
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", 
respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. 
In order to help communication between people from these two planets, 
you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<100). 
Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:
For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
"""

# 定义地球和火星的数字系统
# 对于地球的数字系统，我们使用十进制数
# 对于火星的数字系统，我们使用特定的单词来表示数字
earth_low = [str(i) for i in range(0, 13)] # 地球的低位数字（0-12）
mars_low = ['tret', 'jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jly', 'aug', 'sep', 'oct', 'nov', 'dec'] # 火星的低位数字（0-12）
earth_high = [''] + [str(i*13) for i in range(1, 13)] # 地球的高位数字（13的倍数）
mars_high = [''] + ['tam', 'hel', 'maa', 'huh', 'tou', 'kes', 'hei', 'elo', 'syy', 'lok', 'mer', 'jou'] # 火星的高位数字（13的倍数）

# 地球到火星的转换函数
def earth_to_mars(num):
    high, low = divmod(num, 13) # 使用divmod函数获取数字的高位和低位
    # 根据高位和低位的值返回对应的火星数字
    if high and low:
        return mars_high[high] + ' ' + mars_low[low]
    elif high:
        return mars_high[high]
    else:
        return mars_low[low]

# 火星到地球的转换函数
def mars_to_earth(s):
    words = s.split() # 将火星数字字符串分割成单词
    # 根据单词的数量和内容返回对应的地球数字
    if len(words) == 2:
        return mars_high.index(words[0]) * 13 + mars_low.index(words[1])
    elif words[0] in mars_high:
        return mars_high.index(words[0]) * 13
    else:
        return mars_low.index(words[0])

# 主函数
def main():
    N = int(input()) # 读取输入的行数
    for _ in range(N):
        # strip()是一个字符串方法，用于删除字符串开头和结尾的空格或指定字符。如果没有给定任何参数，strip()将默认删除空格。
        s = input().strip() # 读取每一行的输入
        # 根据输入的内容调用相应的转换函数，并打印结果
        if s.isdigit():
            print(earth_to_mars(int(s)))
        else:
            print(mars_to_earth(s))

main() # 调用主函数
