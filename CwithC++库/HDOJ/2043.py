def is_secure_password(password):
    # Check password length
    if len(password) < 8 or len(password) > 16:
        return False

    # Initialize flags for different character types
    has_upper = has_lower = has_digit = has_special = False

    # Check each character in the password
    for c in password:
        if c.isupper():
            has_upper = True
        elif c.islower():
            has_lower = True
        elif c.isdigit():
            has_digit = True
        elif c in "~!@#$%^":
            has_special = True

    # Check if at least three character types are present
    char_types = has_upper + has_lower + has_digit + has_special
    return char_types >= 3

if __name__ == "__main__":
    M = int(input())
    for _ in range(M):
        password = input()
        if is_secure_password(password):
            print("YES")
        else:
            print("NO")
