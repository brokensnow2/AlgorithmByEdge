"""
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，
而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入:
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出:
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1 s2 ... sk , T = t1 t2 ... tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立
样例输入
abc
样例输出
abc
acb
bac
bca
cab
cba

分析：如果循环：第一层从小到大
第二层除了第一层的那个字母，再从小到大
第三层除了第一，第二层字母，再从小到大

如果用递归 ？
"""
"""
def remove_common_elements_from_other_list(list1, list2):
    return [element for element in list1 if element not in list2]

def remove_common_elements(list,str):
    return [element for element in list if element != str]

def printOthers(str):
    for i in str:
        if len(str) == 1:
            print(i,end='\n')
            return
        else:
            print(i,end="")
            otherChr = remove_common_elements(str,i)
            printOthers(otherChr)
        

str = list(input())
for i in str: # 处理前缀字符时有问题，比如先打印了a,调用printOthers是会打印bc,cd；但a只打印了一次；结果就会abc,下一行只有cb
    print(i,end="")
    otherChr = remove_common_elements(str,i)
    printOthers(otherChr)

"""

""""""
def remove_common_elements(str, char):
    return [element for element in str if element != char]

def printOthers(str, prefix=""):
    if len(str) == 1:
        print(prefix + str[0])
    else:
        for i in range(len(str)):
            printOthers(remove_common_elements(str, str[i]), prefix + str[i])

str = list(input())
printOthers(str)
