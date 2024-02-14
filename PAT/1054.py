"""
在计算机内存的幕后，颜色总是被认为是每个像素24位信息的一系列。
在图像中，比例面积最大的颜色称为主色。严格意义上的主色占总面积的一半以上。
现在给定一个分辨率为M乘N的图像（例如，800×600），你应该指出严格的主色。
输入规范：
每个输入文件包含一个测试用例。对于每种情况，第一行包含2个正数：M（≤800）和N（≤600），它们是图像的分辨率。
接下来是N行，每行包含[0,2^24]范围内的M种数字颜色. 
保证了对于每个输入图像存在严格的主色。一行中的所有数字都用空格隔开。
输出规格：
对于每个测试用例，只需在一行中打印主色即可。

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
"""
from collections import Counter

# 读取图像的分辨率
M, N = map(int, input().split())

# 读取图像的颜色数据
colors = []
for _ in range(N):
    colors.extend(map(int, input().split()))

# 计算每种颜色的数量
counter = Counter(colors)

# 找到数量最多的颜色
'''
most_common(1) 方法返回数量最多的1种颜色及其数量，结果是一个列表，
列表中的每个元素都是一个元组，元组的第一个元素是颜色，第二个元素是数量。
[0][0] 用于获取列表中第一个元组的第一个元素，即数量最多的颜色。
'''
main_color = counter.most_common(1)[0][0]

# 打印主色
print(main_color)

"""
def find_major_color(M, N, pixels):
    total_pixels = M * N
    color_count = {}
    
    for row in pixels:
        for color in row:
            if color in color_count:
                color_count[color] += 1
            else:
                color_count[color] = 1
    
    for color, count in color_count.items():
        if count > total_pixels / 2:
            return color

# 读取输入
M, N = map(int, input().split())
pixels = []
for _ in range(N):
    pixels.append(list(map(int, input().split())))

# 打印输出
print(find_major_color(M, N, pixels))

"""
