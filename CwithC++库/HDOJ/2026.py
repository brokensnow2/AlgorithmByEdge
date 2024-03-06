while True:
    try:
        sentence = input()
        print(sentence.title()) # title函数会把每个单词的首字母变为大写
    except EOFError:
        break
