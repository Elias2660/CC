import sys
sys.stdin = open('text.txt', 'r')

almanac = []
seeds = input().split(":")[1].strip().split(" ")

# getting the inputs
for line in sys.stdin:
    cur_index = 0
    if (line != "\n"):
        almanac[0].append(line.strip().split(" "))
    if (line.find("map") != -1):
        almanac.append([])
        cur_index+= 1
        
print(seeds)
print(almanac)