"""
1037 Magic Coupon
简而言之：
N个优惠券，有正有负
M个商品，价值有正有负
并且每个优惠券和每个产品最多可以选择一次。
优惠券可以乘以商品得到一个数字；
你的任务是选择商品并使用合适的优惠券使数字最大
4 ：优惠券数
1 2 4 -1 ：优惠券的值
4 ：商品数
7 6 -2 -3 ：商品的价值
Sample Output:
43 =  4*7 + 2*6 + -1*-3

PS:根据案例；好像商品必须和优惠券一起使用
"""

"""
思路：贪心：
商品价值正的一组从大到小排序；乘以从大到小的正的优惠券
商品价值负的一组从小到大排序；乘以从小到大的负的优惠券
"""
# 优惠券数
N = int(input())
# 优惠券的值
coupons = list(map(int,input().split()))
# 商品数
M = int(input())
# 商品的价值
products = list(map(int,input().split()))

# 分类和排序
couponsPositive = []
couponsNegative = []
for i in coupons:
    if i > 0:
        couponsPositive.append(i)
    elif i < 0:
        couponsNegative.append(i)

prodPos = []
prodNeg = []
for i in products:
    if i > 0:
        prodPos.append(i)
    elif i < 0:
        prodNeg.append(i)

couponsPositive.sort(reverse=True)
couponsNegative.sort()
prodPos.sort(reverse=True)
prodNeg.sort()

# 计算
sum = 0
i = 0
j = 0
while i < len(couponsPositive) and i < len(prodPos):
    sum += couponsPositive[i] * prodPos[i]
    i += 1
while j < len(couponsNegative) and j < len(prodNeg):
    sum += couponsNegative[j] * prodNeg[j]
    j += 1

# 输出
print(sum)