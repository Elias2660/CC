"""
TODO: Create actual solution

PYTON SOLUTION**

USACO 2017 US Open Contest, Silver
Problem 2. Bovine Genomics

link to problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=739

**TLE for 6/10 test cases
"""



n, m = map(int, input().split())
spotty_genomes = [[list(genome) for genome in input()] for number in range(n)]
plain_genomes = [[list(genome) for genome in input()] for number in range(n)]
n_locations = 0


for pos_1 in range(m-2):

    for pos_2 in range(pos_1+1, m-1):

        for pos_3 in range(pos_2+1, m):
            found_error = False

            for spotty_genome in spotty_genomes:
                for plain_genome in plain_genomes:
                    if spotty_genome[pos_1] == plain_genome[pos_1] and spotty_genome[pos_2] == plain_genome[pos_2] and spotty_genome[pos_3] == plain_genome[pos_3]:
                        found_error = True
                        break


            if found_error == False:
                n_locations += 1

print(n_locations)
                


