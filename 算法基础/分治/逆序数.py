"""
例题:求排列的逆序数
考虑1,2,.,n (n <= 100000)的排列i，i2，...，in，如果其中存在j,k，满足
j < k且ij> ik， 那么就称(ij, ik)是这个排列的一个逆序。
一个排列含有逆序的个数称为这个排列的逆序数。例如排列263451 含有8个
逆序(2, 1), (6,3), (6,4), (6,5), (6,1), (3, 1), (4,1), (5, 1)，因此该排列的逆
序数就是8。


"""
