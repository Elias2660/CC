"""
PYTHON SOLUTION**

**Solution not tested

USACO 2016 February Contest, Silver
Problem 2. Load Balancing

link to problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=668
 """


n = int(input())

d = {}
m = []
v = []
max_num = 0 

for num in range(n):
    x, y, z = map(int,input().split())
    m.append([x, y, z])
    d[num] = []
    v.append(False)

for cn in range(n - 1):
    for tn in range(cn, n):
        c, t = m[cn], m[tn]
        if c != t:
            distance = (abs(c[0]- t[0])**2 + abs(c[1]-t[1])**2) 
            if distance <= c[2] ** 2:
                d[cn].append(tn)
            if distance <= t[2] ** 2:
                d[tn].append(cn)

def dfs(cow_num):
    v[cow_num] = True
    for c in d[cow_num]:
        if v[c] == False:
            dfs(c)

for c in d:
    n = 0
    dfs(c)
    for w in v:
        if w == True:
            n += 1
            v[v.index(True)] = False
    
    max_num = max(n, max_num)

    

print(max_num)
    



