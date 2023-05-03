"""
PYTHON SOLUTION

USACO 2016 January Contest, Bronze
Problem 2. Angry Cows

link to problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=592
"""

# import sys
# sys.stdin = open("angry.in", "r")
# sys.stdout = open("angry.out", "w")


n = int(input())
locs = []
for _ in range(n):
    locs.append(int(input()))


max_d = 0

for loc in locs:
    time = 1
    all_d = 1
    locs_copy = locs.copy()
    locs_copy.remove(loc)
    new_d = True
    upper_bound,lower_bound = loc, loc


    while new_d:

        exploding = []
        

        for loc in locs_copy:
            if loc <= (upper_bound + time) and loc >= (lower_bound - time):
                exploding.append(loc)

        if len(exploding) == 0:
            new_d = False
            max_d = max(max_d, all_d)

        else:
            all_d += len(exploding)
            lower_bound = min(exploding)
            upper_bound = max(exploding)
            for item in exploding:
                locs_copy.remove(item)
            time += 1

print(max_d)