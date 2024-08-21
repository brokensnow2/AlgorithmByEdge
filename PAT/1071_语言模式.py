"""
人们通常对同一个词的同义词有偏好。
例如，有些人可能更喜欢“警察”，而另一些人可能更喜欢“帽子”。
分析这些模式有助于缩小说话者的身份范围，这在验证时很有用，例如，验证在线头像背后是否仍然是同一个人。
现在给定一段从某人演讲中采样的文本，你能找到这个人最常用的单词吗？

输入规格：
每个输入文件包含一个测试用例。对于每个案例，有一行长度不超过1048576个字符的文本，以回车符结尾。
输入包含至少一个字母数字字符，即集合[]中的一个字符。0-9 A-Z a-z

输出规格：
对于每个测试用例，在一行中打印输入文本中最常见的单词，后跟一个空格和它在输入中出现的次数。
如果有多个这样的单词，请打印字典顺序上最小的单词。
该单词应以所有小写字母打印。这里“单词”定义为由非字母数字字符或开始/结束行分隔的字母数字字符的连续序列。

请注意，单词不区分大小写。

Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5
"""
import re
from collections import Counter

def most_common_word(text):
    # 将文本转换为小写
    text = text.lower()
    
    # 使用正则表达式提取单词
    words = re.findall(r'\b\w+\b', text)
    
    # 统计单词频率
    word_count = Counter(words)
    
    # 找到出现次数最多的单词（字典顺序最小的）
    most_common = min(word_count.items(), key=lambda x: (-x[1], x[0]))
    
    # 输出结果
    print(f"{most_common[0]} {most_common[1]}")

# 测试样例
text = input()
most_common_word(text)
