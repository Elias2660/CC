import sys
sys.stdin = open("test.txt", 'r')

t_count = 0

for line in sys.stdin:
    count = 0
    while(line.find("  ") != -1):
        line = line.replace("  ", " ")
    win = line.split(":")[1].split("|")[0].strip().split(" ")
    mine = line.split(":")[1].split("|")[1].strip().split(" ")
    print(win)
    print(mine)
    for w in win:
        for c in mine:
            if w == c:
                mine.remove(c)
                count = 1 if count == 0 else count   * 2
        
                

    t_count += count
    # print(count)
    count = 0
    
print(t_count)
    