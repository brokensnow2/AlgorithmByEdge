def findMaxIndex(array):
    maxValue = max(array)
    index = array.index(maxValue)
    return index

dic = {
    0:'W',
    1:'T',
    2:'L'
}


WTL = []
for _ in range(3):
    WTL.append(list(map(float,input().split())))

index1 = findMaxIndex(WTL[0])
index2 = findMaxIndex(WTL[1])
index3 = findMaxIndex(WTL[2])
sum = (WTL[0][index1] * WTL[1][index2] * WTL[2][index3] * 0.65 - 1) * 2
print(f"{dic[index1]} {dic[index2]} {dic[index3]} {sum:.2f}")
