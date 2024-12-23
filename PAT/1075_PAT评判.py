"""
The ranklist of PAT is generated from the status list, which shows the scores of the submissions.  
This time you are supposed to generate the ranklist for PAT.

Input Specification:
Each input file contains one test case.  
For each case, the first line contains 3 positive integers, 
N (≤10^4), the total number of users, 
K (≤5), the total number of problems, 
and M (≤10^5), the total number of submissions.  
It is then assumed that the user id's are 5-digit numbers from 00001 to N, 
and the problem id's are from 1 to K.  
The next line contains K positive integers p[i] (i=1, ..., K), 
where p[i] corresponds to the full mark of the i-th problem.  

Then M lines follow, each gives the information of a submission in the following format:
user_id problem_id partial_score_obtained
where partial_score_obtained is either −1 if the submission cannot even pass the compiler, 
or is an integer in the range [0, p[problem_id]].  
All the numbers in a line are separated by a space.

Output Specification:
For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, 
and all the users with the same total_score obtain the same rank; 
and s[i] is the partial score obtained for the i-th problem.  
If a user has never submitted a solution for a problem, 
then "-" must be printed at the corresponding position. 
If a user has submitted several solutions to solve one problem, 
then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks.  
For those who have the same rank, 
users must be sorted in nonincreasing order according to the number of perfectly solved problems.  
And if there is still a tie, then they must be printed in increasing order of their id's.  
For those who has never submitted any solution that can pass the compiler, 
or has never submitted any solution, they must NOT be shown on the ranklist.  
It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
"""

def pat_ranklist():
    N, K, M = map(int, input().split())
    full_marks = list(map(int, input().split()))
    
    # 初始化用户数据
    users = {f"{i+1:05d}": {'scores': [-1]*K, 'total_score': 0, 'perfect_solved': 0, 'has_submission': False} for i in range(N)}
    
    # 处理提交记录
    for _ in range(M):
        user_id, problem_id, score = input().split()
        problem_id = int(problem_id) - 1
        score = int(score)
        user = users[user_id]
        user['has_submission'] = True
        
        if score > user['scores'][problem_id]:
            if user['scores'][problem_id] != -1:
                user['total_score'] += score - user['scores'][problem_id]
            else:
                user['total_score'] += score
            if user['scores'][problem_id] == full_marks[problem_id]:
                user['perfect_solved'] -= 1
            user['scores'][problem_id] = score
            if score == full_marks[problem_id]:
                user['perfect_solved'] += 1
        elif score == -1:
            user['scores'][problem_id] = 0
    
    # 过滤掉没有有效提交的用户
    valid_users = [user_id for user_id, user in users.items() if user['total_score'] > 0]
    
    # 排序用户
    valid_users.sort(key=lambda x: (-users[x]['total_score'], -users[x]['perfect_solved'], x))
    
    # 生成排名列表
    rank_list = []
    current_rank = 1
    last_score = None
    
    for i, user_id in enumerate(valid_users):
        user = users[user_id]
        if user['total_score'] != last_score:
            current_rank = i + 1
            last_score = user['total_score']
        
        score_string = " ".join(f"{score}" if score != -1 else "-" for score in user['scores'])
        rank_list.append(f"{current_rank} {user_id} {user['total_score']} {score_string}")
    
    # 输出排名列表
    print("\n".join(rank_list))

# 运行函数，接收输入
pat_ranklist()
