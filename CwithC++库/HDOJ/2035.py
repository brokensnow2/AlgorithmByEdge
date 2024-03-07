while True:
    n, m = map(int, input().split())
    if not (n or m):
        break
    else:
    	ans = n ** m
    	print(f"{str(ans)[-3:]}")