import heapq


def solve():
    n, m = map(int, input().split())

    # graph[u]：u 完成后，会影响哪些后继任务
    graph = [[] for _ in range(n + 1)]

    # indegree[v]：v 当前还有多少个前置任务没完成
    indegree = [0] * (n + 1)

    # 读入依赖 u -> v
    for _ in range(m):
        u, v = map(int, input().split())

        graph[u].append(v)
        indegree[v] += 1

    # 小根堆：
    # 保存当前所有“入度为 0、可以立即执行”的任务
    heap = []

    for i in range(1, n + 1):
        if indegree[i] == 0:
            heapq.heappush(heap, i)

    # 保存最终拓扑序
    order = []

    while heap:
        # 当前所有可执行任务中，
        # 取编号最小的一个，保证字典序最小
        u = heapq.heappop(heap)

        order.append(u)

        # u 已经完成，因此它指向的所有任务
        # 都少了一个未完成的前置依赖
        for v in graph[u]:
            indegree[v] -= 1

            # v 的所有前置任务都完成了
            # 现在可以加入候选集合
            if indegree[v] == 0:
                heapq.heappush(heap, v)

    # 如果没有处理完全部 n 个任务，
    # 说明剩余节点中存在环
    if len(order) != n:
        print(-1)
    else:
        print(*order)


if __name__ == "__main__":
    solve()