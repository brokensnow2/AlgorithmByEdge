# 使用for循环读取输入，直到文件结束
for line in sys.stdin:
    # 使用split函数将输入行分割为两个字符串
    A, B = line.split()
    # 使用int函数将十六进制字符串转换为十进制数
    numA = int(A, 16)
    numB = int(B, 16)
    # 计算两个数的和
    sum = numA + numB
    # 输出和，以十六进制格式，字母部分大写
    print(f"{sum:X}\n")
