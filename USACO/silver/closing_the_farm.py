"""
PYTHON SOL, but tles b/c python

USACO 2016 US Open Contest, Silver
Problem 3. Closing the Farm
Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=644

"""



#just usaco basics
import sys
sys.stdin = open("closing.in", "r")
sys.stdout = open("closing.out","w")

#getting the libraries together
HIGHEST = 3001
connections = [[] for _ in range(HIGHEST)]
visited = [False]*HIGHEST
removed = [False]*HIGHEST
removal_order = []

count = 0

#get m and n
N, M = map(int, input().split())


#dfs
def dfs(key):
    global count
    visited[key] = True
    count += 1
    for element in connections[key]:
        if not visited[element] and not removed[element]:
            dfs(element)

#get connections
for farm in range(M):
    c1, c2 = map(int, input().split())
    connections[c1].append(c2)
    connections[c2].append(c1)


#get order of removal
for removal in range(N):
    removal_order.append(int(input()))


for index in range(N):

    for i in range(N+1):
        visited[i] = False


    count = index
    dfs(removal_order[N-1])

    #check if it is correct
    if count == N:
        print("YES")
    else:
        print ("NO")
    

    removed[removal_order[index]] = True
        