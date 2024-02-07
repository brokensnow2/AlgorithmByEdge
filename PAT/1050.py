"""
Given two strings S1 and S2, 
S=S1−S2 is defined to be the remaining string after taking all the characters in S2 from S1
. Your task is simply to calculate S1−S2
for any given strings. However, it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case. Each case consists of two lines which gives 
S1 and S2, respectively. 
The string lengths of both strings are no more than 10^4. 
It is guaranteed that all the characters are visible ASCII codes and white space, 
and a new line character signals the end of a string.

Output Specification:
For each test case, print 
S1−S2
in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
"""
def subtract_strings(S1, S2):
    S2_set = set(S2)
    S = [c for c in S1 if c not in S2_set]
    return ''.join(S)

S1 = input()
S2 = input()
print(subtract_strings(S1,S2))