"""
倍数数：124 -> 1, 24。 24是1的倍数，所以124是倍数数。 
给定x，计算[1, x]中有多少个倍数数。1 <= x <= 10^7
有T组测试数据，每组数据给出一个整数x，1 <= T <= 10^5。
"""
T = int(input())

for _ in range(T):
    x = int(input())
    if x < 10:
        print(0)
        continue
    ans = 0
    is_over = False
    # 对1~9分别计算处于十位，百位，千位时对应的解数
    n = 10 # 十位开始
    while (not is_over):
        for i in range(1, 10):
            if (i+1) * n <= x: # 满足i+1才可以
                ans += n // i
                if n % i != 0:
                    ans += 1 # 还有个0
            elif (i+1) * n == x:
                ans += n // i
                is_over = True
                if n % i != 0:
                    ans += 1 # 还有个0
                break
            else:
                # 继续处理剩余的
                ans += (x - i * n) // i
                ans += 1 # 还有个0
                is_over = True
                break
        n = n * 10
    print(ans)
    