def solve():
    n, K, W = map(int, input().split())

    tasks = []
    for _ in range(n):
        w, v = map(int, input().split())
        tasks.append((w, v))

    # NEG 表示“这个状态目前不可达”
    NEG = float("-inf")

    # dp[j][t]:
    # 恰好选 j 个任务，总耗时恰好为 t 时的最大收益
    dp = [
        [NEG] * (W + 1)
        for _ in range(K + 1)
    ]

    # 什么任务都没选、耗时为 0，收益为 0
    dp[0][0] = 0

    # 逐个处理任务
    for w, v in tasks:

        # j 必须倒序，防止当前任务被重复使用
        for j in range(K, 0, -1):

            # t 也必须倒序，同样是 0/1 背包的要求
            for t in range(W, w - 1, -1):

                # 来源状态必须是可达的
                if dp[j - 1][t - w] == NEG:
                    continue

                # 选当前任务
                dp[j][t] = max(
                    dp[j][t],
                    dp[j - 1][t - w] + v
                )

    # 必须恰好选 K 个，
    # 但耗时只要求 <= W，所以在 0~W 中取最大值
    ans = max(dp[K])

    if ans == NEG:
        print(-1)
    else:
        print(ans)


if __name__ == "__main__":
    solve()