"""
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. 
When a customer starts connecting a long-distance call, the time will be recorded,
and so will be the time when the customer hangs up the phone. Every calendar month, 
a bill is sent to the customer for each minute called (at a rate determined by the time of day).
Your job is to prepare the bills for each month, given a set of phone call records.
Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00,
 the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), 
followed by N lines of records. 
Each phone call record consists of the name of the customer (string of up to 20 characters without space), 
the time and date (MM:dd:HH:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month.
Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record.
Any on-line records that are not paired with an off-line record are ignored, 
as are off-line records not paired with an on-line record. 
It is guaranteed that at least one call is well paired in the input. 
You may assume that no two records for the same customer have the same time. 
Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, 
first print in a line the name of the customer and the month of the bill in the format shown by the sample. 
Then for each time period of a call, print in one line the beginning and ending time and date (dd:HH:mm), 
the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. 
Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
"""

# 实在不知道题意是什么。。。
from collections import defaultdict

def getTime(start, over):
    # 将时间字符串转换为分钟数
    start_day, start_hour, start_minute = map(int, start.split(':'))
    over_day, over_hour, over_minute = map(int, over.split(':'))
    start_total = start_day * 24 * 60 + start_hour * 60 + start_minute
    over_total = over_day * 24 * 60 + over_hour * 60 + over_minute
    return over_total - start_total

def getFee(start, over,rates):
    # 计算通话费用
    start_day, start_hour, start_minute = map(int, start.split(':'))
    over_day, over_hour, over_minute = map(int, over.split(':'))
    fee = 0
    while (start_day, start_hour, start_minute) < (over_day, over_hour, over_minute):
        fee += rates[start_hour]
        start_minute += 1
        if start_minute == 60:
            start_minute = 0
            start_hour += 1
        if start_hour == 24:
            start_hour = 0
            start_day += 1
    return fee


def main():
    # 比率下标对应0-23点
    rates = list(map(int, input().split()))
    n = int(input())
    records_on = []
    records_off = []
    customers = defaultdict(list)
    for _ in range(n):
        name, time, status = input().split()
        if status == "on-line":
            records_on.append((name, time))
        else:
            records_off.append((name, time))
    records_on.sort()
    records_off.sort()
    i = 0
    j = 0
    while i < len(records_on) and j < len(records_off):
        # 同一个人
        if records_on[i][0] == records_off[j][0]:
            # 合理
            if records_on[i][1] < records_off[j][1]:
                # online找与offline最近的那条,即online找小于offline中最大的
                if i < len(records_on)-1:
                    if records_on[i+1][1] < records_off[j][1] and records_on[i+1][0] == records_off[j][0]:
                        i += 1
                    else:
                    # 字典： key是名字，值是列表，列表中是一对一对的时间
                        customers[records_on[i][0]].append((records_on[i][1], records_off[j][1]))
                        last_name = records_on[i][0]
                        i += 1
                        j += 1
                else:
                    # 字典： key是名字，值是列表，列表中是一对一对的时间
                    customers[records_on[i][0]].append((records_on[i][1], records_off[j][1]))
                    last_name = records_on[i][0]
                    i += 1
                    j += 1
            # 找下一个匹配的
            else:
                j += 1
        # 不是同一个人,考虑一个人有两条online，三条offline：i,j同时移动，i先指向下个人
        # 考虑一个人有3条online，2条offline：i,j同时移动，j先指向下个人
        else:
            if records_on[i][0] != last_name:
                j += 1
            elif records_off[i][0] != last_name:
                i += 1
    # 姓名key，记录是值，records是列表，可能有多个元组
    for name, records in customers.items():
        # 打印姓名和月份
        print(f"{name} {records[0][0][0:2]}")
        totalFee = 0
        for i in records:
            # 打印对应的人所有记录
            start = i[0][3:]
            over = i[1][3:]
            time = getTime(start,over)
            fee = getFee(start,over,rates)
            print(f"{start} {over} {time} ${fee/100 :.2f}")
            totalFee += fee
        print(f"Total amount: ${totalFee/100 :.2f}")


main()
