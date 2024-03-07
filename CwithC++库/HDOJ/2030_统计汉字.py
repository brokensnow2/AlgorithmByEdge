def count_chinese(s):
    return sum('\u4e00' <= c <= '\u9fa5' for c in s)

n = int(input())
for _ in range(n):
    s = input().strip()
    print(count_chinese(s))
