"""
加入了两个剪枝条件，确保左边宽度大于等于右边，上边高度大于等于下边。这样可以有效减少计算量，提高算法效率。
过了
"""

def solve(w, h, knife, memo):
    if knife == 0:
        return w * h

    if memo[knife][w][h] != -1:
        return memo[knife][w][h]

    SV = [INF]
    SH = [INF]

    for left_w in range(1, w):
        for left_knife in range(knife):
            if w - left_w >= left_w:  # 剪枝：确保左边的宽度大于等于右边
                SV.append(max(solve(left_w, h, left_knife, memo), solve(w - left_w, h, knife - 1 - left_knife, memo)))

    for up_h in range(1, h):
        for up_knife in range(knife):
            if h - up_h >= up_h:  # 剪枝：确保上边的高度大于等于下边
                SH.append(max(solve(w, up_h, up_knife, memo), solve(w, h - up_h, knife - 1 - up_knife, memo)))

    memo[knife][w][h] = min(min(SV), min(SH))
    return memo[knife][w][h]


w, h, m = map(int, input().split())
ans = []
INF = float('inf')

while w != 0 and h != 0 and m != 0:
    memo = [[[-1 for _ in range(h + 1)] for _ in range(w + 1)] for _ in range(m)]
    ans.append(solve(w, h, m - 1, memo))
    w, h, m = map(int, input().split())

for i in ans:
    print(i)

