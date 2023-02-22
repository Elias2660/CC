
"""
PYTHON SOLUTION**

**Solution not tested

USACO 2016 February Contest, Silver
Problem 2. Load Balancing

Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=619
"""

# import sys
# sys.stdin = open("balancing.in", "r")
# sys.stdout = open("balancing.out", "w")





n, size = map(int, input().split())
cow_x = [0] * n
cow_y = [0] * n
for cow in range(n):
    cow_x[cow], cow_y[cow] = map(int, input().split())

value = n


def number_of_cows(a, b):
    quad_1 = 0
    quad_2 = 0
    quad_3 = 0
    quad_4 = 0
    for cloc in range(n):
        if cow_x[cloc] > a and cow_y[cloc] > b:
            quad_1 += 1
        elif cow_x[cloc] > a and cow_y[cloc] < b:
            quad_4 += 1
        elif cow_x[cloc] < a and cow_y[cloc] > b:
            quad_2 += 1
        elif cow_x[cloc] < a and cow_y[cloc] < b:
            quad_3 +=1

    return max([quad_1, quad_2, quad_3, quad_4])


for a in cow_x:
    if a == size:
        continue
    for b in cow_y:
        if b == size:
            continue
        value = min(value, number_of_cows(a +1, b+1))

print(value)