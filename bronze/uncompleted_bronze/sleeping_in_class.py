# import sys
# sys.stdin
# sys.stdout
"""
PYTHON SOLUTION**

**Solution not tested

USACO 2022 February Contest, Bronze
Problem 1. Sleeping in Class

link the the problem: 
http://usaco.org/index.php?page=viewproblem2&cpid=1203
"""

num_cases = int(input())
case_lens = []
cases = []

for number in range(num_cases):
    case_lens.append(int(input()))
    cases.append([int(number) for number in input().split()])

modifications = []

for case in cases:
    divs = []
    cur_range = []
    sum_case = sum(case)
    #create list of factors
    for number in range(max(case), sum_case + 1):
        if sum_case == 0:
            modifications.append(0)

        elif sum_case % number == 0:
            target_factor = number
            cur_sum = 0
            possible = True
            for nap in case:
                cur_sum += nap
                if cur_sum > target_factor:
                    possible = False
                    break
                elif cur_sum == target_factor:
                    cur_sum = 0
            
            if possible == True:
                modifications.append(len(case) - sum_case/target_factor)
                break

for item in modifications:
    print(int(item))