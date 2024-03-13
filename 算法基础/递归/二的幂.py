"""
描述
任何一个正整数都可以用2的幂次方表示。例如：
    137=27+23+20
同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：
    2(7)+2(3)+2(0)
进一步：7=22+2+20（21用2表示）
        3=2+20
所以最后137可表示为：
    2(2(2)+2+2(0))+2(2+2(0))+2(0)
又如：
    1315=210+28+25+2+1
所以1315最后可表示为：
    2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
输入
一个正整数n（n≤20000）。
输出
一行，符合约定的n的0，2表示（在表示中不能有空格）。

"""

def power_of_two(n):
    if n == 0:
        return "0"
    elif n == 1:
        return "2(0)"
    elif n == 2:
        return "2"
    elif n == 3:
        return "2+2(0)"
    else:
        power = len(bin(n)) - 3 # 减去0b，而且因为第n位是n-1次方
        remainder = n - 2 ** power
        if remainder == 0:
            return "2(" + power_of_two(power) + ")"
        else:
            return "2(" + power_of_two(power) + ")+" + power_of_two(remainder)

n = int(input())
print(power_of_two(n))
