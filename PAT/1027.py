"""
火星上的人在他们的电脑中以与地球人相似的方式表示颜色。
也就是说，颜色由一个6位数表示，其中前两位数字表示红色，中间两位数字代表绿色，最后两位数字则表示蓝色。
唯一的区别是它们使用基数13（0-9和A-C）而不是16。
现在，给定三个十进制数字（每个数字在0到168之间）的颜色，您应该输出它们的Mars RGB值。
输入规范：
每个输入文件包含一个测试用例，该测试用例占用一行，该行包含三个十进制颜色值。
输出规格：
对于每个测试用例，您应该以以下格式输出Mars RGB值：首先输出#，然后后跟一个6位数的数字，
其中所有英文字符都必须大写。如果单个颜色只有1位数长，则必须在其左侧打印0。
Sample Input:
15 43 71
Sample Output:
#123456

"""
emum = {
    0:'0',
    1:'1',
    2:'2',
    3:'3',
    4:'4',
    5:'5',
    6:'6',
    7:'7',
    8:'8',
    9:'9',
    10:'A',
    11:'B',
    12:'C'
}

R,G,B = map(int,input().split())
print(f"#{emum[int(R/13)]}{emum[R%13]}{emum[int(G/13)]}{emum[G%13]}{emum[int(B/13)]}{emum[B%13]}")