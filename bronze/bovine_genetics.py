"""
PYTHON SOLUTION

USACO 2017 US Open Contest, Bronze
Problem 2. Bovine Genomics
Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=736
"""



# import sys
# sys.stdin = open("cownomics.in", "r")
# sys.stdout = open("cownomics.out", "w")


n, m = map(int, input().split())
spotty_genomes = [[list(genome) for genome in input()] for number in range(n)]
plain_genomes = [[list(genome) for genome in input()] for number in range(n)]
n_locations = 0


for genome_location in range(m):
    found_error = False

    for spotty_genome in  spotty_genomes:
        for plain_genome in  plain_genomes:
            if spotty_genome[genome_location] == plain_genome[genome_location]:
                found_error = True
                break

    if found_error == False:
        n_locations += 1

print(n_locations)

