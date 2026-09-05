"""
教材里的核心题面是：
给定 \(n,k,S,R\)，每个评级 \(v_i\in[1,6]\)，总和为 \(S\)；
删除其中“评级最高”的 \(k\) 件后，剩下 \(n-k\) 件的评级和为 \(R\)。
要求构造任意一个满足条件的序列，不存在则输出 -1。
如果最高评级有并列，可以从并列最高中任意删除 \(k\) 件。

核心：观察数学规律，构造一个分界值 \(t\)；
build采用下界填补法而不是均匀分配法

"""
def build(cnt, low, high, target):
    # 先全部放到允许的最低值
    arr = [low] * cnt

    # 还需要补多少总和
    remain = target - cnt * low

    for i in range(cnt):
        # 当前元素最多还能增加 high - low
        add = min(remain, high - low)
        arr[i] += add
        remain -= add

    return arr


def solve():
    n, k, S, R = map(int, input().split())

    keep_cnt = n - k
    removed_sum = S - R

    # 两组首先必须各自在 [1, 6] 中能够凑出目标和
    if not (keep_cnt <= R <= 6 * keep_cnt):
        print(-1)
        return

    if not (k <= removed_sum <= 6 * k):
        print(-1)
        return

    # t 至少要这么大，才能让 keep_cnt 个不超过 t 的数凑出 R
    low_t = max(
        1,
        (R + keep_cnt - 1) // keep_cnt
    )

    # t 至多只能这么大，否则 k 个至少为 t 的数总和会超过 removed_sum
    high_t = min(
        6,
        removed_sum // k
    )

    # 不存在整数分界值
    if low_t > high_t:
        print(-1)
        return

    # 任取一个可行分界值即可
    t = low_t

    # 保留组全部位于 [1, t]
    keep = build(
        keep_cnt,
        1,
        t,
        R
    )

    # 删除组全部位于 [t, 6]
    removed = build(
        k,
        t,
        6,
        removed_sum
    )

    print(*(keep + removed))


if __name__ == "__main__":
    solve()