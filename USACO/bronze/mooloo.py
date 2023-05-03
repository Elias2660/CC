"""
PYTHON SOLUTION


USACO 2023 February Contest, Bronze
Problem 3. Watching Mooloo
Link to Problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=1301
"""


N, K = map(int, input().split())
days = [int(number) for number in input().split()]


cost = K + 1


for i in range(N - 1):
    day_difference =  days[i + 1] - days[i]
    if day_difference > K :
        cost += K + 1
    if day_difference <= K:
        cost += day_difference



print(cost)
    
