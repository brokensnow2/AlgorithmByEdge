"""
N行M列，两机器人同时出发，一个从左上角走到右下角，只能向右或向下走； 
一个从右上角走到左上角，只能向左或向下走。
每个格子有一个分数，机器人经过的格子分数会被收集，他们不能停在同一个格子上，求两机器人收集的分数和最大值。

输入：
第一行：两个整数N和M，表示格子行数和列数。
接下来N行，每行M个整数，表示每个格子的分数。

输出：
一个整数，表示两机器人收集的分数和最大值。
"""


def solve():
	data = list(map(int, input().split()))
	if not data:
		return

	n, m = data
	grid = [list(map(int, input().split())) for _ in range(n)]

	# 两个机器人同步走到最后一行，状态由当前步数和两列位置决定。
	neg_inf = float("-inf")
	dp = [[neg_inf] * m for _ in range(m)]
	dp[0][m - 1] = grid[0][0] + grid[0][m - 1]

	for step in range(1, n + m - 1):
		next_dp = [[neg_inf] * m for _ in range(m)]

		for col1 in range(m):
			for col2 in range(m):
				if dp[col1][col2] == neg_inf:
					continue

				for next_col1 in (col1, col1 + 1):
					for next_col2 in (col2, col2 - 1):
						if not (0 <= next_col1 < m and 0 <= next_col2 < m):
							continue

						next_row1 = step - next_col1
						next_row2 = step - (m - 1 - next_col2)
						if not (0 <= next_row1 < n and 0 <= next_row2 < n):
							continue
						if next_row1 == next_row2 and next_col1 == next_col2:
							continue

						value = dp[col1][col2]
						value += grid[next_row1][next_col1]
						value += grid[next_row2][next_col2]
						next_dp[next_col1][next_col2] = max(
							next_dp[next_col1][next_col2], value
						)

		dp = next_dp

	print(dp[m - 1][0])


if __name__ == "__main__":
	solve()