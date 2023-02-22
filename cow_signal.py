"""
PYTHON SOLUTION

USACO 2016 December Contest, Bronze
Problem 3. The Cow-Signal

link for the problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=665
"""

# import sys
# sys.stdin = open("cowsignal.in","r")
# sys.stdout = open("cowsignal.out", "w")


dimensions = [int(number) for number in input().split()]
original_picture = [input() for number in range(dimensions[0])]


for line in original_picture:
    to_be_added = ""
    split_line = list(original_picture[original_picture.index(line)])

    for character in split_line:
        for scale in range(dimensions[2]):
            to_be_added += character

    for scale in range(dimensions[2]):
        print(to_be_added)


