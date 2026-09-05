import heapq


class Fenwick:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    def add(self, i, delta):
        """
        把逻辑数组第 i 个位置增加 delta。

        本题中：
        +1 表示该压缩坐标从“不存在”变成“存在”
        -1 表示从“存在”变成“不存在”
        """
        while i <= self.n:
            self.tree[i] += delta
            i += i & -i

    def query(self, i):
        """
        返回前 i 个位置的和。

        本题中相当于：
        前 i 个压缩坐标中有多少个有效锚点位置。
        """
        s = 0

        while i > 0:
            s += self.tree[i]
            i -= i & -i

        return s

    def kth(self, k):
        """
        返回“第 k 个有效位置”的压缩下标。

        要求：
        1 <= k <= 当前有效位置总数
        """
        pos = 0

        # 不超过 n 的最大 2 的幂
        step = 1 << (self.n.bit_length() - 1)

        while step:
            nxt = pos + step

            # 如果走到 nxt 后，
            # 前缀中仍然没有达到第 k 个有效位置，
            # 就可以继续向右跳。
            if nxt <= self.n and self.tree[nxt] < k:
                pos = nxt
                k -= self.tree[nxt]

            step >>= 1

        return pos + 1


def solve():
    n, q = map(int, input().split())

    # anchors[i] 表示第 i 个锚点当前的真实坐标
    anchors = list(map(int, input().split()))

    queries = []

    # 坐标压缩需要提前知道所有可能出现的坐标
    all_coords = anchors[:]

    for _ in range(q):
        i, x = map(int, input().split())

        # 转成 Python 的 0-based 下标
        i -= 1

        queries.append((i, x))
        all_coords.append(x)

    # 排序 + 去重
    coords = sorted(set(all_coords))

    m = len(coords)

    # 真实坐标 -> 1-based 压缩下标
    pos_to_idx = {
        x: i + 1
        for i, x in enumerate(coords)
    }

    # cnt[idx]：
    # 当前这个真实坐标上有多少个锚点
    cnt = [0] * (m + 1)

    for x in anchors:
        cnt[pos_to_idx[x]] += 1

    # Fenwick 只维护“这个位置是否存在”
    bit = Fenwick(m)

    for idx in range(1, m + 1):
        if cnt[idx] > 0:
            bit.add(idx, 1)

    # heap 保存所有曾经加入过的 gap 的负数，
    # 从而用 Python 小根堆模拟最大堆。
    heap = []

    # 普通 dict 即可：
    # gap_count[g] = 当前长度为 g 的有效 gap 数量
    gap_count = {}

    def add_gap(g):
        if g <= 0:
            return

        gap_count[g] = gap_count.get(g, 0) + 1

        # 存负数模拟最大堆
        heapq.heappush(heap, -g)

    def remove_gap(g):
        if g <= 0:
            return

        # 只做逻辑删除，不立即从 heap 中找它
        gap_count[g] -= 1

    def get_max_gap():
        """
        清理已经失效的堆顶元素，
        返回当前实际存在的最大 gap。
        """
        while heap:
            g = -heap[0]

            # 这种长度的 gap 已经全部失效
            if gap_count.get(g, 0) == 0:
                heapq.heappop(heap)
            else:
                return g

        # 只有一个不同锚点位置时，没有 gap
        return 0

    def predecessor(idx):
        """
        找严格小于 idx 的最近有效压缩位置。
        """
        # idx 左边一共有几个有效位置
        k = bit.query(idx - 1)

        if k == 0:
            return None

        # 最后一个就是第 k 个有效位置
        return bit.kth(k)

    def successor(idx):
        """
        找严格大于 idx 的最近有效压缩位置。
        """
        # <= idx 的有效位置数量
        k = bit.query(idx)

        # 当前有效位置总数
        total = bit.query(m)

        if k == total:
            return None

        # 下一个就是第 k+1 个有效位置
        return bit.kth(k + 1)

    # -----------------------------------
    # 初始化所有相邻 gap
    # -----------------------------------

    active_positions = [
        coords[idx - 1]
        for idx in range(1, m + 1)
        if cnt[idx] > 0
    ]

    for i in range(1, len(active_positions)):
        add_gap(
            active_positions[i] - active_positions[i - 1]
        )

    # -----------------------------------
    # 删除一个锚点
    # -----------------------------------

    def remove_position(x):
        idx = pos_to_idx[x]

        # 如果这个位置还有其他锚点，
        # 删除一个不会改变有效位置集合。
        if cnt[idx] > 1:
            cnt[idx] -= 1
            return

        # cnt[idx] == 1：
        # 这是这个坐标的最后一个锚点。

        left_idx = predecessor(idx)
        right_idx = successor(idx)

        if left_idx is not None:
            left = coords[left_idx - 1]
            remove_gap(x - left)
        else:
            left = None

        if right_idx is not None:
            right = coords[right_idx - 1]
            remove_gap(right - x)
        else:
            right = None

        # 原来：
        #
        # left --- x --- right
        #
        # 删除 x 后变成：
        #
        # left --------- right
        if left is not None and right is not None:
            add_gap(right - left)

        # 这个真实坐标现在完全不存在
        cnt[idx] = 0

        # Fenwick 中把这个位置从 1 改成 0
        bit.add(idx, -1)

    # -----------------------------------
    # 插入一个锚点
    # -----------------------------------

    def add_position(x):
        idx = pos_to_idx[x]

        # 如果这个位置原本已经有锚点，
        # 只增加重复数量即可。
        if cnt[idx] > 0:
            cnt[idx] += 1
            return

        # x 还是不存在的，
        # 因此可以从旧集合中找前驱和后继。
        left_idx = predecessor(idx)
        right_idx = successor(idx)

        if left_idx is not None:
            left = coords[left_idx - 1]
        else:
            left = None

        if right_idx is not None:
            right = coords[right_idx - 1]
        else:
            right = None

        # 原来：
        #
        # left --------- right
        #
        # 插入 x 后这个 gap 消失。
        if left is not None and right is not None:
            remove_gap(right - left)

        # 新增：
        #
        # left --- x
        if left is not None:
            add_gap(x - left)

        # 新增：
        #
        # x --- right
        if right is not None:
            add_gap(right - x)

        cnt[idx] = 1

        # Fenwick 中把这个位置从 0 改成 1
        bit.add(idx, 1)

    # -----------------------------------
    # 处理每一次移动
    # -----------------------------------

    answers = []

    for i, new_x in queries:
        old_x = anchors[i]

        # 原地不动时根本不需要修改数据结构
        if old_x != new_x:
            remove_position(old_x)
            add_position(new_x)

            anchors[i] = new_x

        # 当前最大的相邻锚点距离
        max_gap = get_max_gap()

        # 整数点的最大最近距离
        answers.append(max_gap // 2)

    print("\n".join(map(str, answers)))


if __name__ == "__main__":
    solve()