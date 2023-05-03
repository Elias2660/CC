"""
PYTHON SOLUTION

USACO 2023 February Contest, Bronze
Problem 1. Hungry Cow
Link to Problem
http://www.usaco.org/index.php?page=viewproblem2&cpid=1299 
"""


N, T = map(int, input().split())

total_eaten,  time_elapsed = 0, 0

last_time, remaining_bales = map(int, input().split())

    
for _ in range(N - 1):
    cur_time, number = map(int, input().split())
    
    time_elapsed = cur_time - last_time

    if remaining_bales >= time_elapsed:
        remaining_bales -= time_elapsed
        total_eaten += time_elapsed

    elif time_elapsed > remaining_bales:
        total_eaten += remaining_bales
        remaining_bales = 0

    remaining_bales += number
    last_time = cur_time


if remaining_bales >= T - last_time:
    total_eaten += T - last_time + 1

elif T - last_time > remaining_bales:
    total_eaten += remaining_bales



print(total_eaten)

    






