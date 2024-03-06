while True:
    try:
        str_input = input()
        max_char = max(str_input)
        for char in str_input:
            if char == max_char:
                print(f"{char}(max)", end="")
            else:
                print(char, end="")
        print()
    except EOFError:
        break
