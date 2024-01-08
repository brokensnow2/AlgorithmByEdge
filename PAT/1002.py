str1 = input()
str2 = input()
list1 = str1.split()
list2 = str2.split()
maxDegreeA = list1[0]
exponentsA = []
coefficientsA = []

for i in range(int(maxDegreeA)):
    exponentsA.append(int(list1[2*i+1]))
    coefficientsA.append(float(list1[2*i+2]))

maxDegreeB = list2[0]
exponentsB = []
coefficientsB = []

for i in range(int(maxDegreeB)):
    exponentsB.append(int(list2[2*i+1]))
    coefficientsB.append(float(list2[2*i+2]))
i = 0
j = 0
count = 0
exponents = []
coefficients = []

while i < int(maxDegreeA) and j < int(maxDegreeB):
    if exponentsA[i] > exponentsB[j]:
        exponents.append(exponentsA[i])
        coefficients.append(coefficientsA[i])
        i += 1
        count += 1
    elif exponentsA[i] < exponentsB[j]:
        exponents.append(exponentsB[j])
        coefficients.append(coefficientsB[j])
        j += 1
        count += 1
    else:
        sum_coef = coefficientsA[i] + coefficientsB[j]
        if sum_coef != 0.0:
            exponents.append(exponentsA[i])
            coefficients.append(sum_coef)
            count += 1
        i += 1
        j += 1

while i < int(maxDegreeA):
    exponents.append(exponentsA[i])
    coefficients.append(coefficientsA[i])
    i += 1
    count += 1

while j < int(maxDegreeB):
    exponents.append(exponentsB[j])
    coefficients.append(coefficientsB[j])
    j += 1
    count += 1

print(count, end="")
for i in range(count):
    print(" {} {:.1f}".format(exponents[i], coefficients[i]), end="")
