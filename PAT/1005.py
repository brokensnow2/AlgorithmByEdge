# 定义一个字典，将0-9的整数映射到对应的英文单词
num_to_word = {
    0: "zero",
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine"
}

# 读取输入的大整数
N = input().strip()

# 计算N的各位数字之和
s = sum(int(digit) for digit in N)

# 将和s的每一位数字转换为英文单词，并用空格连接
chr_num = []
for digit in str(s):
    chr_num.append(num_to_word[int(digit)])

# result = ' '.join(num_to_word[int(digit)] for digit in str(s)) # 使用生成器表达式
result = ' '.join(chr_num)
# 打印结果
print(result)

