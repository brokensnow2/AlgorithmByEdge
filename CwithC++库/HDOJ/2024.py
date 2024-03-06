def is_valid_identifier(s):
    if not s[0].isalpha() and s[0] != '_':
        return "no"
    for char in s:
        if not char.isalnum() and char != '_':
            return "no"
    return "yes"

n = int(input())
for _ in range(n):
    s = input()
    print(is_valid_identifier(s))
