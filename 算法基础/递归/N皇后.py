def NQueen(k: int):
    if k == N:
        for i in range(N):
            print(queenPos[i],end=" ")
        print("\n")
        return
    else:
        for i in range(N): # 第k行逐个尝试第i列
            j = 0
            while j < k: # 与前k-1个判断是否冲突
                if queenPos[j] == i or abs(queenPos[j]-i) == abs(k-j):
                    break
                j = j + 1
            if j == k:
                queenPos[k] = i
                NQueen(k+1)
                    


N = int(input())
queenPos = [None for _ in range(N)]
NQueen(0)

