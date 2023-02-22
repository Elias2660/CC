"""
PYTHON SOLUTION

USACO 2020 December Contest, Bronze
Problem 1. Do You Know Your ABCs?

Link to problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
"""
# import sys

cow_nums = sorted([int(number) for number in input().split()])


print(cow_nums[0], cow_nums[1], cow_nums[6] - cow_nums[0] - cow_nums[1])


