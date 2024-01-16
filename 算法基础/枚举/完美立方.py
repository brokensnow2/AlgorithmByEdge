"""
形如a3= b3 + c3 + d3的等式被称为完美立方等式。例如
12^3=6^3+8^3+10^3。编写一个程序，对任给的正整数N
(N≤100)，寻找所有的四元组(a，b，c，d)，使得a^3 =
b^3 + c^3+ d^3，其中a,b,c,d 大于1，小于等于N，且
b<=c<=d。
输入:
一个正整数N (N≤100)。
输出:
每行输出一个完美立方。输出格式为:
Cube = a，Triple = (b,c,d)
其中a,b,c,d所在位置分别用实际求出四元组值代入。
"""
N = int(input("请输入一个整数："))
for a in range(2, N):
    for b in range(2, a):
        for c in range(b, a):
            for d in range(c, a):
                if a**3 == b**3+c**3+d**3:
                    print(f"Cube is {a},Triple is {b},{c},{d}")