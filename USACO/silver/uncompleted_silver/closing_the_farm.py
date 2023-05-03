"""
TODO: Finish Problem


USACO 2016 US Open Contest, Silver
Problem 3. Closing the Farm

Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=644

"""


# #just usaco basics
import sys
sys.stdin = open("closing.in", "r")
sys.stdout = open("closing.out","w")

#get m and n
n, m = map(int, input().split())

l = {}
visited = []

#initialize list and dictionary
for number in range(n):
    l[number+1] = []
    visited.append(False)

#create dfs stuff
for num in range(m):
    c1, c2 = map(int, input().split())
    l[c1].append(c2)
    l[c2].append(c1)

#dfs search
def dfs(location):
    visited[location  - 1] = True
    for path in l[location]:
        if visited[path - 1]  == False:
            dfs(path)

#cleanup
def cleanup():
    answer = "YES"
    for item in l:
        x = visited[item -1]
        if x == False:
            answer = "NO"
        if x == True:
            visited[item -1] = False
    
    print(answer)


#run program
for num in range(n):
    choose = 0
    while visited[choose] == "closed":
        choose += 1

    dfs(choose + 1)
    cleanup()



    r = int(input())
    visited[r - 1] = "closed"
    del l[r]



    