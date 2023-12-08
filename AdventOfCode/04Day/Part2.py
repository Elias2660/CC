import sys
sys.stdin = open("test.txt", 'r')

t_count = 0
wins, mine = [], []
times = []

for line in sys.stdin:
    count = 0
    while(line.find("  ") != -1):
        line = line.replace("  ", " ")
    wins.append(line.split(":")[1].split("|")[0].strip().split(" "))
    mine.append(line.split(":")[1].split("|")[1].strip().split(" "))
    times.append(1)
    
    
for index in range(len(wins)):
    win = wins[index]
    me = mine[index]
    count = 0
    next_num = 1
    for w in win:
        for c in me:
                if w == c:
                    me.remove(c)
                    count += 1
                    if(index + next_num < len(times)):
                        times[index + next_num] += 1 * times[index]
                        next_num += 1
    # print(count)
    t_count += count * times[index]
    print(times)
    next_num = 1
    

#     t_count += count
#     # print(count)
#     count = 0
    
print(sum(times))
    