def is_triangle(a, b, c):
    # 按从小到大排序
    sides = sorted([a, b, c])
    smallest, middle, largest = sides
    
    # 判断是否满足三角形条件
    return smallest + middle > largest

if __name__ == "__main__":
    M = int(input())
    for _ in range(M):
        A, B, C = map(int, input().split())
        if is_triangle(A, B, C):
            print("YES")
        else:
            print("NO")
