"""
PYTHON SOLUTION**

**Solution Source: https://usaco.guide/general/io

USACO 2015 December Contest, Bronze
Problem 2. Speeding Ticket
link for then problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=568
"""


# import sys
# sys.stdin = open("speeding.in", "r")
# sys.stdout = open("speeding.out", "w")

dimensions = [int(number) for number in input().split()]
road_signs = [[int(sign) for sign in input().split()] for number in range(dimensions[0])]
actual_journey = [[int(sign) for sign in input().split()] for number in range(dimensions[1])]

overspeed = 0
total_speed = 100
expanded_road = []
expanded_driving = []

for direction in road_signs:
    for number in range(direction[0]):
        expanded_road.append(direction[1])


for direction in actual_journey:
    for number in range(direction[0]):
        expanded_driving.append(direction[1])




for number in range(100):
    overspeed = max(overspeed, expanded_driving[number] - expanded_road[number])

print(overspeed)