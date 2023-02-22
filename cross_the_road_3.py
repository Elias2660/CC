"""
PYTHON SOLUTION

USACO 2017 February Contest, Bronze
Problem 3. Why Did the Cow Cross the Road III

Link to Problem:
http://www.usaco.org/index.php?cpid=713&page=viewproblem2
"""


# import sys
# sys.stdin = open("cowqueue.in", "r")
# sys.stdout = open("cowqueue.out", "w")



n = int(input())
l = {}


for cow in range(n):
    arrival, wait = map(int, input().split())
    l[arrival] = wait if arrival not in l else l[arrival] + wait

sorted_dict_list = sorted(l)

wait = 0
for key in sorted_dict_list:
    wait = max(key, wait)
    wait += l[key]


print(wait)
