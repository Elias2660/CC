out = 0
for x in range(int(input())):
    l = input().split()
    for y in range(len(l)):
        if y != x:
            out += int(l[y])
print(out)