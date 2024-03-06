n = int(input())
vowels = 'aeiou'
for _ in range(n):
    s = input()
    for v in vowels:
        count = s.count(v)
        print(f'{v}:{count}')
    if _ != n - 1:
        print()
