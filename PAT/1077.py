"""
日语因其句子结尾助词而臭名昭著。这种粒子的个人偏好可以被认为是说话者个性的反映。这种偏好被称为“Kuchiguse”，
在动漫和漫画中经常被艺术化地夸大。例如，人造的句子结尾助词“nyan~”经常被用作猫式性格人物的刻板印象：
Itai nyan~（很疼，nyan~）
Ninjin wa iyada nyan~（我讨厌胡萝卜，nyan~）
现在给同一个角色讲几句话，你能找到她的Kuchiguse吗？
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行都是整数N（2≤N≤100）。以下是长度为0~256（含）个字符的N个文件行，每个文件行代表一个字符的口语行。口语台词区分大小写。
输出规格：
对于每个测试用例，在一行中打印字符的kuchiguse，即所有N行中最长的公共后缀。如果没有这样的后缀，写nai。
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
"""
def find_kuchiguse(N, lines):
    # 如果只有一行，那么它本身就是 kuchiguse
    if N == 1:
        return lines[0]

    # 将所有行反转，从而方便从后往前比较
    reversed_lines = [line[::-1] for line in lines]

    # 找到最短的行的长度
    min_length = min(len(line) for line in reversed_lines)

    # 逐个字符比较，直到找到不一样的字符
    kuchiguse = ""
    for i in range(min_length):
        if all(reversed_line[i] == reversed_lines[0][i] for reversed_line in reversed_lines):
            kuchiguse = reversed_lines[0][:i+1][::-1]
        else:
            break

    # 如果 kuchiguse 为空，则表示没有公共后缀
    if kuchiguse == "":
        return "nai"
    else:
        return kuchiguse

# 读取输入
N = int(input())
lines = [input() for _ in range(N)]

# 找到 kuchiguse，并输出结果
result = find_kuchiguse(N, lines)
print(result)
