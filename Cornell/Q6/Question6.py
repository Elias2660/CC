i = input().split()
for x in range(len(i)):
    i[x] = int(i[x])
arr = [x+1 for x in range(i[0])]
for _ in range(i[1]):
    j = input().split()
    j[0] = int(j[0])-1
    j[1] = int(j[1])-1
    arr = arr[:j[0]] + list(reversed(arr[j[0]:j[1]+1])) + arr[j[1]+1:]
for _ in range(i[2]):
    print(arr[int(input())-1])