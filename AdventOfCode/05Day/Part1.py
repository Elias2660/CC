import sys
sys.stdin = open('text.txt', 'r')

almanac = []
seeds = input().split(":")[1].strip().split(" ")

# getting the inputs
for line in sys.stdin:
    cur_index = 0

    if (line.find("map") != -1):
        almanac.append([])
        cur_index+= 1
    elif (line != "\n" and line != ""):
        almanac[cur_index].append(line.strip().split(" "))

        
print(seeds)
print(almanac)