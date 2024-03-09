def get_triangle_area(b_x, b_y, c_x, c_y):
    return (b_x * c_y - c_x * b_y) / 2.0

while True:
    n = int(input())
    if n == 0:
        break

    coordinates = []
    for _ in range(n):
        x, y = map(int, input().split())
        coordinates.append((x, y))

    total_area = 0.0
    for i in range(1, n - 1):
        area = get_triangle_area(coordinates[i][0] - coordinates[0][0],
                                 coordinates[i][1] - coordinates[0][1],
                                 coordinates[i + 1][0] - coordinates[0][0],
                                 coordinates[i + 1][1] - coordinates[0][1])
        total_area += area

    print(f"{abs(total_area):.1f}")
