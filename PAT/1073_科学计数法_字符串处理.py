"""
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. 
The notation matches the regular expression [+-][1-9].[0-9]+E[+-][0-9]+ 
which means that the integer portion has exactly one digit, 
there is at least one digit in the fractional portion, 
and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, 
you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:
Each input contains one test case. For each case, there is one line containing the real number A in scientific notation. 
The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:
For each test case, print in one line the input number A in the conventional notation, 
with all the significant figures kept, including trailing zeros.

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
"""

def scientific_to_conventional(A :str):
    # 将输入字符串分成基数部分和指数部分
    base, exponent = A.split('E')
    
    # 提取基数的符号和去除符号后的数字部分
    sign = base[0]
    digits = base[1:]
    
    # 将指数部分转换为整数
    exp = int(exponent)
    
    # 找出小数点在数字部分的位置
    decimal_pos = digits.find('.')
    
    # 去除数字部分中的小数点
    digits = digits.replace('.', '')
    
    # 计算应用指数后小数点的新位置
    new_decimal_pos = decimal_pos + exp
    
    # 初始化结果字符串，并添加符号
    if sign == '+':
        result = ''
    else:
        result = sign
    
    if new_decimal_pos <= 0:
        # 如果新小数点位置在第一个数字前面，添加'0.'并在其后添加相应数量的零
        result += '0.' + '0' * (-new_decimal_pos) + digits
    elif new_decimal_pos >= len(digits):
        # 如果新小数点位置在最后一个数字后面，直接在数字后面添加相应数量的零
        result += digits + '0' * (new_decimal_pos - len(digits))
    else:
        # 否则，在新位置插入小数点
        result += digits[:new_decimal_pos] + '.' + digits[new_decimal_pos:]
    
    # 输出最终结果
    print(result)

# 示例输入输出

scientific_to_conventional(input())
