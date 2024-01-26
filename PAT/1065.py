count = int(input())
results = []
for _ in range(count):
    A,B,C = map(int,input().split())
    if A+B>C:
        results.append("true")
    else:
        results.append("false")
for i in range(1,count+1):
    print(f"Case #{i}: {results[i-1]}")