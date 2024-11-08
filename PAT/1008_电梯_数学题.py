"""
The highest building in our city has only one elevator. 
A request list is made up with N positive numbers. 
The numbers denote at which floors the elevator will stop, in specified order.
 It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
 The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor 
when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, 
followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41
"""
def elevator_time(requests):
    time = 0
    current_floor = 0
    for floor in requests:
        if floor > current_floor:
            time += (floor - current_floor) * 6
        else:
            time += (current_floor - floor) * 4
        current_floor = floor
        time += 5  # 停留时间
    return time

# 示例输入
requests = input().split()
requests = list(map(int,requests))
print(elevator_time(requests[1:]))
