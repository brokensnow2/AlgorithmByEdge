"""
给定一个包含 \(n\) 个整数的数组 nums，其中 \(n\) 为偶数且 \(n\le30\)。

需要将这 \(n\) 个整数划分成两个集合 \(A\) 和 \(B\)，要求：

$$ |A|=|B|=\frac n2 $$

求：

$$ \left|\sum A-\sum B\right| $$

的最小可能值。

思路：暴力枚举超时，采用MITM（Meet in the Middle）思想，
将数组分成两半，分别计算每一半的所有子集和，然后在两半的子集和中寻找最接近总和一半的组合，
从而得到最小的差值。
"""
from bisect import bisect_left


def get_sums(arr):
    n = len(arr)

    # buckets[k] 保存：
    # 从 arr 中恰好选择 k 个元素时，所有可能的子集和。
    buckets = [[] for _ in range(n + 1)]

    # mask 从 0 到 2^n - 1，枚举 arr 的所有子集。
    for mask in range(1 << n):

        # 当前子集选择了多少个元素。
        cnt = mask.bit_count()

        # 当前子集的元素总和。
        total = 0

        # 检查 arr 中每个位置是否被 mask 选中。
        for i in range(n):

            # 如果 mask 的第 i 位为 1，
            # 就说明 arr[i] 属于当前子集。
            if (mask >> i) & 1:
                total += arr[i]

        # 按“选了几个元素”放进对应桶中。
        buckets[cnt].append(total)

    return buckets


def solve():
    n = int(input())

    # 读取 n 个整数。
    nums = list(map(int, input().split()))

    # 所有数的总和。
    total_sum = sum(nums)

    # 因为 n 是偶数，
    # 最终两个集合都必须恰好包含 n/2 个元素。
    half = n // 2

    # 把原数组从中间拆成左右两半。
    left = nums[:half]
    right = nums[half:]

    # 枚举左右两边所有子集，
    # 并按照“选了几个元素”分桶。
    left_sums = get_sums(left)
    right_sums = get_sums(right)

    # 后面需要在右侧桶中二分查找，
    # 因此把右侧每个桶分别排序。
    for bucket in right_sums:
        bucket.sort()

    # 答案初始化为无穷大。
    ans = float("inf")

    # k 表示：
    # 最终选出的 half 个元素中，
    # 有 k 个来自左半边。
    for k in range(half + 1):

        # 那么右半边必须恰好选择 half-k 个。
        need = half - k

        # 取出对应的右侧桶。
        right_bucket = right_sums[need]

        # 枚举左侧恰好选 k 个元素时的所有子集和。
        for x in left_sums[k]:

            # 最终选出的这一组总和记作 s=x+y。
            #
            # 我们希望：
            # s ≈ total_sum / 2
            #
            # 所以希望：
            # y ≈ total_sum / 2 - x
            target = total_sum / 2 - x

            # 找到右侧桶中第一个 >= target 的位置。
            pos = bisect_left(right_bucket, target)

            # 检查二分位置本身。
            if pos < len(right_bucket):
                y = right_bucket[pos]

                # 一组和为 x+y，
                # 另一组和就是 total_sum-(x+y)。
                #
                # 两组差：
                # |(x+y) - (total_sum-x-y)|
                # = |2(x+y)-total_sum|
                diff = abs(2 * (x + y) - total_sum)

                ans = min(ans, diff)

            # 同时检查二分位置左边的元素。
            if pos > 0:
                y = right_bucket[pos - 1]

                diff = abs(2 * (x + y) - total_sum)

                ans = min(ans, diff)

    print(ans)


if __name__ == "__main__":
    solve()