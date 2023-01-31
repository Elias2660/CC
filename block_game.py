"""
link to code: http://www.usaco.org/index.php?page=viewproblem2&cpid=664
"""

# import sys
# sys.stdin = open("blocks.in", "r")
# sys.stdout = open("blocks.out", "w")


alphabet = "a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z"
alphabet = [letter.replace(" ", "").replace(",", "") for letter in alphabet.split()]
alphabet_dict = {}
number_needed = [0 for number in range(26)]

for number in range(26):
    alphabet_dict[alphabet[number]] = number 

numberblocks = int(input())

blocks = [[word.replace(" ","") for word in input().split()] for number in range(numberblocks)]


for block in blocks:
    for letter in set(list(block[0] + block[1])):
        number_needed[alphabet_dict[letter]] += max(list(block[0]).count(letter), list(block[1]).count(letter))

for number in number_needed:
    print(number)



