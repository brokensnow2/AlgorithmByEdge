"""
输入规格：
每个输入文件都包含一个测试用例。
对于每种情况，第一行都包含 2 个正数：N (≤10^4，硬币总数）和M (≤10^2，伊娃必须支付的金额）。
第二行包含硬币的面值，这些面值都是正数。一行中的所有数字都用空格分隔。

输出规格：
对于每个测试用例，在一行中打印面值V1≤V2≤⋯ ≤Vk。V1+V2+⋯+Vk=M.
所有数字必须用空格分隔，行尾不得有多余的空格。
如果此类解决方案不是唯一的，则输出最小的序列。如果没有解决方案，则输出“No Solution”。

注意：如果存在i<k时 A[i]=B[i]  , k≥1时 A[k] < B[k]，则称序列 {A[1]， A[2]， ...} 比序列 {B[1]， B[2]， ...} “小”。

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
"""
def find_min_coins(N, M, coins):
    dp = [False] * (M + 1)
    dp[0] = True  # 用0个硬币可以凑成0元
    path = [-1] * (M + 1)  # 记录每个金额的最后一个硬币索引
    last_coin = [-1] * (M + 1)  # 记录每个金额最后一个硬币的值

    coins.sort()  # 排序以确保字典序最小
    
    for i in range(N):
        for j in range(M, coins[i] - 1, -1):
            if dp[j - coins[i]]:
                dp[j] = True
                if last_coin[j] == -1 or coins[i] < last_coin[j]:
                    path[j] = j - coins[i]
                    last_coin[j] = coins[i]

    if dp[M]:
        result = []
        while M > 0:
            result.append(last_coin[M])
            M = path[M]
        result.sort()  # 最后排序以确保输出顺序正确
        print(" ".join(map(str, result)))
    else:
        print("No Solution")

# 读取输入
N, M = map(int, input().split())
coins = list(map(int, input().split()))

# 求解并输出结果
find_min_coins(N, M, coins)



"""
DFS, 超时：
def dfs(coins, target, index, path, result):
    if target == 0:
        result.append(path[:])
        return
    if target < 0:
        return
    for i in range(index, len(coins)):
        if i > index and coins[i] == coins[i-1]:  # 避免重复
            continue
        path.append(coins[i])
        dfs(coins, target - coins[i], i + 1, path, result)
        path.pop()

def find_min_coins(N, M, coins):
    coins.sort()
    result = []
    dfs(coins, M, 0, [], result)
    
    if result:
        # 找到的第一个解就是字典序最小的解，因为我们已经排过序
        print(" ".join(map(str, result[0])))
    else:
        print("No Solution")

# 读取输入
N, M = map(int, input().split())
coins = list(map(int, input().split()))

# 求解并输出结果
find_min_coins(N, M, coins)


"""