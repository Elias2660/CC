"""link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=712"""

# import sys
# sys.stdin = open("circlecross.in", "r")
# sys.stdout = open("circlecross.out", "w")

points = list(input())
alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
number_pairs = 0
checked_list = []
check_list = []



for letter_index in range(52):
    if points[letter_index] not in checked_list:
        checked_list.append(points[letter_index])

        for other_letter_index in range(letter_index+1, 52):

            if points[letter_index] == points[other_letter_index]:
                check_list = []
                for check_letter_index in range(letter_index+1, other_letter_index):
                    if points[check_letter_index] not in check_list and alphabet.index(points[check_letter_index]) > alphabet.index(points[letter_index]):
                        check_list.append(points[check_letter_index])
                    elif points[check_letter_index] in check_list:
                        check_list.remove(points[check_letter_index])
                
                number_pairs += len(check_list)


print(number_pairs)
