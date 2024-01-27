"""
给定数字{0，1，2，…，N−1}的任何排列，很容易按递增顺序对它们进行排序。但是，如果Swap（0，*）是唯一允许使用的操作，该怎么办？例如，为了对｛4，0，2，1，3｝进行排序，我们可以按以下方式应用交换操作：
交换（0，1）=>｛4，1，2，0，3｝
交换（0，3）=>｛4，1，2，3，0｝
交换（0，4）=>｛0，1，2，3，4｝
现在，我们要求您找到对前N个非负整数的给定排列进行排序所需的最小交换次数。
输入规范：
每个输入文件包含一个测试用例，给出正N（≤10^5)然后是{0，1，…，N−1}的置换序列。一行中的所有数字都用空格隔开。
输出规格：
对于每种情况，只需在一行中打印对给定排列排序所需的最小交换次数。
毫无疑问：最后一步是将0和第一个元素交换--因为0肯定是第一个元素，所以0应该处在第一个元素该在的位置才能成功。
        所以0要和处在第一个元素的该在位置的那个元素交换
"""


