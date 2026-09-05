
n = int(input())

s = input().split()

d = {} # 记录i最后出现位置
dist = {} #记录间隔
count = {}
error = set() # 

for index, i in enumerate(s):
    # 加入新字符
    if i not in d:
        d[i] = index
        count[i] = 1
    # 判断间隔
    else:
        current_dist = dist.get(i, -1)
        if i not in error:
            if current_dist != -1: 
                if current_dist != index - d[i]:
                    error.add(i)
                    dist.pop(i)
                    count.pop(i)
                else:
                    count[i] += 1
            else:
                dist[i] = index - d[i]
                count[i] += 1
    d[i] = index

candidates = [value for value in count if count[value] >= 3]

if candidates:
    answer = max(candidates, key=lambda value: count[value])
    print(answer, count[answer], dist[answer])
else:
    print(-1)

