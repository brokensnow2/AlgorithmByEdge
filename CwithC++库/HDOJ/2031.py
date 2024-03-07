def convert(n, r):
    convert_string = "0123456789ABCDEF"
    if n < r:
        return convert_string[n]
    else:
        return convert(n // r, r) + convert_string[n % r]

n = int(input())
for _ in range(n):
    num, base = map(int, input().split())
    print(convert(num, base)[::-1])
