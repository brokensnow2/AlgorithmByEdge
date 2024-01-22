from heapq import *
from collections import deque

class Player:
    def __init__(self, arrive_time, play_time, is_vip):
        self.arrive_time = arrive_time
        self.start_time = 0
        self.play_time = play_time
        self.is_vip = is_vip
        self.wait_time = 0

class Tables:
    def __init__(self, table_num,vip_table_num,vip_tables :list):
        self.table_num = table_num
        self.vip_table_num = vip_table_num
        self.vip_tables = vip_tables

def time_to_int(time):
    h, m, s = map(int, time.split(':'))
    return h * 3600 + m * 60 + s

def int_to_time(time):
    h = time // 3600
    m = (time % 3600) // 60
    s = time % 60
    return "{:02d}:{:02d}:{:02d}".format(h, m, s)


def solve():
    print()

N = int(input())
players = []
for _ in range(N):
    arrive_time, play_time, is_vip = input().split()
    arrive_time = time_to_int(arrive_time)
    play_time = min(int(play_time) * 60, 2 * 3600)
    is_vip = int(is_vip)
    players.append(Player(arrive_time, play_time, is_vip))
players.sort(key=lambda player: player.arrive_time)
K, M = map(int, input().split())
vip_tables = list(map(int, input().split()))
table = Tables(K,M,vip_tables)
solve()