"""
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format , and is a string with no more than 15 characters.HH:MM:SS

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. 
That is, the sign in time must be earlier than the sign out time for each person, 
and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
"""

num = int(input())
members = []
while num > 0 :
    member = input().split()
    members.append(member)
    num -= 1


"""
min函数：min函数是Python的内置函数，用于返回给定参数或参数序列中的最小值。
例如，min(1, 2, 3)将返回1，min([1, 2, 3])也将返回1。
你还可以提供一个key参数来自定义比较的方式。key参数应该是一个函数，这个函数会被应用到每个参数上，
如果参数是列表，就相当于把每个元素当参数传给函数，将函数返回的结果取最小的那个参数或者元素返回。
例如，min('hello', 'world', key=len)将返回'hello'，
因为'hello'的长度（len('hello')）小于'world'的长度。

lambda函数：lambda函数是一种在Python中创建小型匿名函数的方式。
lambda函数可以接受任意数量的参数，但只能有一个表达式。lambda函数的语法是：lambda arguments: expression。
这个表达式会被执行并返回。例如，lambda x: x + 1是一个接受一个参数并返回其加一的lambda函数。
你可以像使用普通函数一样使用lambda函数，例如：(lambda x: x + 1)(2)将返回3。

代码中，min函数和lambda函数一起使用，以便根据成员的签到时间找出最早签到的成员。
lambda x: x[1]是一个lambda函数，它接受一个成员（作为列表）并返回成员的签到时间（即列表的第二个元素）。
然后，min函数使用这个lambda函数作为key参数，以便根据签到时间而不是成员的ID（即列表的第一个元素）来比较成员
"""
signInID = min(members, key=lambda x: x[1])[0]
signOutID = max(members, key=lambda x: x[2])[0]
print(f"{signInID} {signOutID}")

