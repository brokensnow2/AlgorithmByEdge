"""
有12枚硬币。其中有11枚真币和1枚假币。假币和真
币重量不同，但不知道假币比真币轻还是重。现在，
用一架天平称了这些币三次，告诉你称的结果，请你
找出假币并且确定假币是轻是重(数据保证一定能找
出来)

输入:
注意:天平左右的硬币数总是相等的
ABCD EFGH even #右边
ABCI EFJK up #右边翘起来
ABIJ EFGH even

输出样例:
K is the counterfeit coin and it is light.

"""
def isFake(c: str,light: bool):
    if light:
        for i in range(3):
            if  test[i][2] == "even":
                if c not in test[i][0] and c not in test[i][1]:
                    pass
                else:
                    return False
            if test[i][2] == "up":
                if c in test[i][1]:
                    pass
                else:
                    return False
            if test[i][2] == "down":
                if c in test[i][0]:
                    pass
                else:
                    return False
    if not light:
        for i in range(3):
            if  test[i][2] == "even":
                if c not in test[i][0] and c not in test[i][1]:
                    pass
                else:
                    return False
            if test[i][2] == "down":
                if c in test[i][1]:
                    pass
                else:
                    return False
            if test[i][2] == "up":
                if c in test[i][0]:
                    pass
                else:
                    return False       
    return True
test = []
for i in range(3):
    str = input()
    list = str.split() #list[0] = 'ABCD';list[1] = 'EFGH';#list[2] = 'even'
    test.append(list) # test[0] = list
for i in range(ord('A'), ord('L')+1):
    c = chr(i)
    if isFake(c,True):
        print(f"{c} is the counterfeit coin and it is light.")
    if isFake(c,False):
        print(f"{c} is the counterfeit coin and it is heavy.")