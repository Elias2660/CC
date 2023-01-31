# Source: https://usaco.guide/general/io
"""source to question: http://www.usaco.org/index.php?page=viewproblem2&cpid=963"""


import sys
sys.stdin = open("gymnastics.in", "r")
sys.stdout = open("gymnastics.out", "w")

number_sessions, number_cows = map(int, input().split())
session_list = [[int(number) for number in input().split()] for session in range(number_sessions)]
comparison_dict = {}
total_consistient = 0

for number in range(1, number_cows+1):
    for second_number in range(number+1, number_cows+1):
        comparison_dict[str(number) + " " + str(second_number)] = "null"


for session in session_list:
    for key in comparison_dict:
        first_cow, second_cow = map(int, key.split())
        comparison = session.index(first_cow) - session.index(second_cow)

        if comparison_dict[key] == "null":
            comparison_dict[key] = comparison
        elif comparison_dict[key] != "false" and comparison_dict[key]/comparison < 0:
            comparison_dict[key] = "false" 
             


for key in comparison_dict:
    if comparison_dict[key] != "false":
        total_consistient += 1

print(total_consistient)
    