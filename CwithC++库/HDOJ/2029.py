def is_palindrome(s):
    return s == s[::-1]

n = int(input())
for _ in range(n):
    s = input().strip()
    print("yes" if is_palindrome(s) else "no")
