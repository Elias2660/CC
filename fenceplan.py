import sys
sys.stdin = open("fenceplan.in", "r")
sys.stdout = open("fenceplan.out", "w")
sys.setrecursionlimit(2000000)

n, m = map(int, input().split())
n_copy = n
d = {}
cor = []
v = []


for num in range(n):
    d[num] = []
    x, y = map(int, input().split())
    cor.append([x, y])
    v.append("unclaimed")

for _ in range(m):
    p1, p2 = map(int, input().split())
    d[p1 - 1].append(p2 - 1)
    d[p2 - 1].append(p1 - 1)


def dfs(num, loc):
    v[loc] = num
    for key in d[loc]:
        if v[key] == "unclaimed":
            dfs(num, key)

num = 0
a = []
perim = []
for cow in d:
    if v[cow] =="unclaimed":
        dfs(num, cow)
        a.append([cor[cow],[0], cor[cow][0], cor[cow][1], cor[cow][1]])
        perim.append(0)
        num += 1
    else:
        a[v[cow]][0] = min(a[v[cow]][0], cor[cow][0])
        a[v[cow]][1] = max(a[v[cow]][1], cor[cow][0])
        a[v[cow]][2] = min(a[v[cow]][2], cor[cow][1])
        a[v[cow]][3] = max(a[v[cow]][3], cor[cow][1]) 
        perim[v[cow]] =  2*(a[v[cow]][1] - a[v[cow]][0]) + 2*(a[v[cow]][3] - a[v[cow]][2])
    

print(min(perim))






