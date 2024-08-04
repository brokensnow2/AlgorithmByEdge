def decode_time(str1, str2, str3, str4):
    week = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
    day, hour, minute = None, None, None
    for i in range(min(len(str1), len(str2))):
        if str1[i] == str2[i]:
            if day is None and 'A' <= str1[i] <= 'G':
                day = week[ord(str1[i]) - ord('A')]
            elif day is not None and (('0' <= str1[i] <= '9') or ('A' <= str1[i] <= 'N')):
                hour = ord(str1[i]) - ord('0') if '0' <= str1[i] <= '9' else ord(str1[i]) - ord('A') + 10
                """ 等价
                if '0' <= str1[i] <= '9':
                    hour = ord(str1[i]) - ord('0')
                else:
                    hour = ord(str1[i]) - ord('A') + 10
                """
                break
    for i in range(min(len(str3), len(str4))):
        if str3[i] == str4[i] and str3[i].isalpha():
            minute = i
            break
    return '{} {:02d}:{:02d}'.format(day, hour, minute)

# 测试函数
str1 = input()
str2 = input()
str3 = input()
str4 = input()
print(decode_time(str1, str2, str3, str4))  # 输出 'THU 14:04'
