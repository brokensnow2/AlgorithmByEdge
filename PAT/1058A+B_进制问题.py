"""
If you are a fan of Harry Potter, you would know the world of magic has its own currency system 
-- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, 
it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of Galleon.
Sickle.Knut (Galleon is an integer in [0,10^7], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
"""
A, B = input().split()
Galleon_A, Sickle_A, Knut_A = A.split('.')
Galleon_B, Sickle_B, Knut_B = B.split('.')
# 存放结果的列表
result = []

Knuts = int(Knut_A) + int(Knut_B)
KnutQuotient = Knuts // 29
KnutRemainder = Knuts % 29
result.append(str(KnutRemainder))

Sickles = int(Sickle_A) + int(Sickle_B) + KnutQuotient
SickleQuotient = Sickles // 17
SickleRemainder = Sickles % 17
result.append(str(SickleRemainder))

Galleons = int(Galleon_A) + int(Galleon_B) + SickleQuotient
result.append(str(Galleons))

print('.'.join(result[::-1]))