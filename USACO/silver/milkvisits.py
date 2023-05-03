"""
PYTHON SOLUTION**

Imported solution from .Yusica

USACO 2019 December Contest, Silver
Problem 3. Milk Visits

Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=968 

"""

import sys
sys.stdin = open("milkvisits.in", "r")
sys.stdout = open("milkvisits.out", "w")

N, M = map(int, input().split())
S = input()
farm_types = []
cow_connections = {}
vlist = []

end_string = ""

# sort out cow connections and farm types
for num in range(N):
    cow_connections[num+1] = []
    farm_types.append(S[num])
    vlist.append([False, False])

        
for num in range(N-1):
    a, b = map(int, input().split())
    cow_connections[a].append(b)
    cow_connections[b].append(a)

    
for _ in range(M):
    #for each visitor determine if it 
    ventry, vexit, vtype = input().split()


    q = [int(ventry)] #develop quene for breadth first search

    while True:
        node = q.pop(0)
        vlist[node - 1][0] = True #set visited to true

        if vlist[node - 1][1] == False and farm_types[node - 1] == vtype:
            vlist[node - 1][1] = True


        if node == int(vexit):
            #if found exit
            if vlist[node - 1][1] == True:
                end_string += "1"
            else:
                end_string += "0"
            vlist = [[False, False] for num in range(N)]
            break

        for i in cow_connections[node]:
            if not vlist[i - 1][0]:
                q.append(i)
                vlist[i- 1][1] = vlist[node - 1][1]
            

print(int(end_string))
        
        

            
