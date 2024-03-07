def generate_pascal_triangle(num_rows):
    # 开辟了二维列表
    triangle = [[1]*i for i in range(1, num_rows+1)]
    # 从第三行开始，反正1，2行都是1
    for i in range(2, num_rows):
        # 每行的第一个和最后一个元素都是1，所以跳过
        for j in range(1, i):
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
    return triangle

lst = map(int, input().split())
for i in lst:
    triangle = generate_pascal_triangle(i)
    for row in triangle:
        print(' '.join(str(num) for num in row))
    print()
