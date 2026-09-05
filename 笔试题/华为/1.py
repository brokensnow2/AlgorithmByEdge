"""
胡牌

给出13张牌，判断是否再加一张牌可以胡。胡：3n+2的牌型，n个顺子或刻子+1对将牌。
顺子：三张同花色连续的牌。刻子：三张相同的牌。将牌：两张相同的牌。
牌有三种，万、条、筒。分别是1-9, a-i, A-I。每种牌有四张。
只能有1或2种花色的牌，不能有3种花色的牌。
可以的话输出胡牌的牌型，输出-1表示不能胡。

输入：
123456789abcde
输出：
-1

输入：
1234456789aa
输出：
a

解题思路：
还差一张，就枚举那9*3张牌，同时得考虑到14张该怎么组合得到3n+2的牌型。
普通得判断看起来不行。
可以用回溯法/DFS，先选一张牌作为将牌，然后再去找顺子和刻子。注意要考虑花色的限制。
DFS的终止条件是所有牌都用完了，且已经选过将牌。
"""

from functools import cache


s = input()
tiles = "123456789abcdefghiABCDEFGHI" # 所有牌
cnt = [0] * 27 # 计数每种牌的数量
ans = []

for c in s:
    cnt[tiles.index(c)] += 1

@cache
def dfs(cnt, pair_ok=False):
    if sum(cnt) == 0: # 所有牌都用完了
        return pair_ok # 如果已经选过将牌，则可以胡
    cnt = list(cnt) # 转换为列表，方便修改
    for i in range(27):
        if cnt[i] > 0:
            # 尝试选这张牌作为将牌
            if not pair_ok and cnt[i] >= 2:
                cnt[i] -= 2
                if dfs(tuple(cnt), True):
                    return True
                cnt[i] += 2
            
            # 尝试选这张牌作为刻子
            if cnt[i] >= 3:
                cnt[i] -= 3
                if dfs(tuple(cnt), pair_ok):
                    return True
                cnt[i] += 3
            
            # 尝试选这张牌作为顺子
            if i % 9 < 7 and cnt[i+1] > 0 and cnt[i+2] > 0:
                cnt[i] -= 1
                cnt[i+1] -= 1
                cnt[i+2] -= 1
                if dfs(tuple(cnt), pair_ok):
                    return True
                cnt[i] += 1
                cnt[i+1] += 1
                cnt[i+2] += 1
            
            break # 每次只尝试一种牌型，避免重复计算
    
    return False

def can_win(cnt):
    dfs.cache_clear() # 清除缓存
    return dfs(tuple(cnt), False)

for i in range(27):
    if cnt[i] < 4: # 还可以再加一张牌
        cnt[i] += 1 # 假设加上这一张牌
        
        kind = 0
        for k in range(3): # Python 的 for 没有块级作用域, 不要再用i
            if sum(cnt[k*9:(k+1)*9]) > 0:
                kind += 1
        if kind <= 2 and can_win(cnt):
            ans.append(tiles[i])
            
        cnt[i] -= 1 # 恢复计数
    else:
        continue
        
print(''.join(ans) if ans else -1)