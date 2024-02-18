"""
给定一个数字段的集合，您应该从中恢复最小的数字。
例如，给定 { 32, 321, 3214, 0229, 87 }，我们可以根据不同顺序的组合恢复许多数字，例如 
32-321-3214-0229-87 或 0229-32-87-321-3214这些段，最小的数字是0229-321-3214-32-87。

输入规格：
每个输入文件包含一个测试用例。每种情况给出一个正整数 N (≤10^4) 后跟 N 个数字段。
每个段包含一个不超过8位的非负整数。一行中的所有数字均以空格分隔。

输出规格：
对于每个测试用例，在一行中打印最小的数字。请注意，第一位数字不能为零。

输入示例：
5 32 321 3214 0229 87
示例输出：
229 321 3214 32 87
"""
from functools import cmp_to_key

def compare(a, b):
    """
    判断两个数字串在组合时哪个应该在前面。
    这个比较函数的工作方式是，对于两个数字串 A 和 B，如果 AB < BA，则 A 应该在 B 前面，否则 B 应该在 A 前面。
    """
    """
    假如32 321 3214 0229 87 这个排序用冒泡函数 根据题意我们要从后往前：

        229 和 87 比： 87229 > 22987 : 所以229小
        229 和 3214 比： 2293214 < 3214229 ：所以229小, 229前移
        229 和 321 ： 229321 < 321229 ：所以229在321前面, 229前移
        32 和 229 ： 32229 < 22932 ： 所以229 在 32 前面, 229前移
        所以229移到最前面
        。。。

        证明：很明显：反证法：
        如果229不在最前面，那么比如87在最前：
        假设min数是229 ***** 87 ***，那么***** 87***小于87*** *****，说明***** 最高位不可能大于8，次高位不可能大于7。。。
        那么229 ***** 小于 ***** 229，说明***** 最高位不可能小于2。。。
        （对于两个数字串 A 和 B，这个显而易见。）
        所以如果87在最前：87 ***** 229 *** > 229 ***** 87 ***,不成立
        上面的例子不明显(不需要借助*****判断)，这个例子更明显（要借助*判断）：假如min数是：321 *** 3214 ，说明***=321（***是3位未知数字，它和321和3214能组成的最小数字如果是321***3214，那么***是321）
        如果3214在最前，3214 *** 321 > 321 *** 3214
        还有一个事实，就是无论怎么组合，总位数相同
    """
    return int(a + b) - int(b + a)

def solve(nums):
    # cmp_to_key将传统的比较函数（comparison function）转化为关键字函数（key function）
    """
    在Python 2中，排序函数如sort()可以接受一个比较函数cmp作为参数，这个比较函数接受两个参数进行比较，并根据比较结果返回负值、零或正值。
    但在Python 3中，比较函数被移除，取而代之的是关键字函数,。
    关键字函数接受一个参数，并返回一个可以用作排序关键字的值。
    这样做的好处是，关键字函数只需要调用一次，而比较函数可能需要多次调用，因此使用关键字函数可以提高排序操作的效率。
    Q:为什么关键字函数只需要调用一次？
    A：在Python的排序操作中，如果我们提供了一个关键字函数（key function），那么这个函数会在排序开始时被调用一次，
    为列表中的每个元素生成一个键值。
    然后，排序操作会根据这些键值进行，而不是直接根据元素的值。
    这样做的好处是，关键字函数只需要为每个元素调用一次，而不是在每次元素比较时都调用，这可以提高排序操作的效率。
    """

    """
    举个例子，假设我们有一个包含字符串的列表，我们想要按照字符串的长度进行排序。
    我们可以定义一个关键字函数，这个函数接受一个字符串，并返回这个字符串的长度。然后，我们可以将这个关键字函数作为sort()函数的key参数：

    def length(string):
        return len(string)

    fruits = ['apple', 'banana', 'cherry', 'date']
    fruits.sort(key=length)

    在这个例子中，length函数就是我们的关键字函数。
    当我们调用sort()函数时，length函数会为列表中的每个元素调用一次，并生成一个键值（也就是字符串的长度）。
    然后，sort()函数会根据这些键值对元素进行排序
    """

    # 回到cmp_to_key函数来；cmp_to_key函数的作用就是将一个接受两个参数的比较函数转换为一个接受一个参数的键函数。
    # 它实现这一点的方式是，返回一个对象，这个类K的对象可以用作排序函数（如sort()）的键函数。这个函数对象在内部调用原始的比较函数。

    # 回忆上文提到的关键字函数只需要为每个元素调用一次：key=cmp_to_key(compare)，然后cmp_to_key(compare)会为每个元素返回一个K对象
    # 所以其实sort()函数是比较K对象的大小，而比较对象的大小要用到__lt__（小于），__gt__（大于）等重载函数
    """
    回顾：
    __lt__在Python中被称为魔术方法或特殊方法，它对应于小于运算符 <。当在Python代码中使用 < 运算符比较两个对象时，Python会自动调用这两个对象的__lt__方法。
    如果你有一个自定义的类，并且你想要能够使用 < 运算符来比较这个类的实例，你可以在你的类中定义一个__lt__方法。
    这个__lt__方法应该接受一个参数（除了self），并返回一个布尔值，表示self是否小于这个参数
    """
    # 在排序过程中，sort()函数会使用这些K类的实例的__lt__、__gt__等方法来比较元素的大小，从而确定它们的顺序。

    nums.sort(key=cmp_to_key(compare))
    return ''.join(nums)

nums = input().split()[1:]
print(int(solve(nums)))
