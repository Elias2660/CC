"""
PYTHON SOLUTION

USACO 2023 February Contest, Bronze
Problem 2. Stamp Grid
"""


T = int(input())

def check(painting, stamp, N, K):
    canvas = [["." for _ in range(N)] for _ in range(N)]
    for x in range(N - K + 1):
        for y in range(N - K + 1):
            painting_subsection = [r[x:x+K] for r in painting[y:y+K]]
            canvas_subsection = [r[x:x+K] for r in canvas[y:y+K]]
            for _ in range(4):
                if stampable(stamp, painting_subsection):
                    update(canvas, stamp, y, x, K)
                stamp = [list(item) for item in zip(*stamp[::-1])]

            if painting == canvas:
                return True
    

    if painting == canvas:
        return True
    else:
        return False
    
    
def update(canvas, stamp, x, y, k):
    for xval in range(x, x + k ):
        for yval in range(y, y+k):
            if canvas[xval][yval] != "*":
                canvas[xval][yval] =  stamp[xval - x][yval - y]



def stampable(stamp, painting_subsection):
    for x in range(len(painting_subsection)):
        for y in range(len(painting_subsection)):
            if stamp[x][y] == "*" and painting_subsection[x][y] == ".":
                return False
    return True


for case in range(T):
    x = input()
    N = int(input())
    painting = []
    for _ in range(N):
        painting.append(list(input()))

    K = int(input())
    stamp = []
    for _ in range(K):
        stamp.append(list(input()))


    if check(painting, stamp, N, K):
        print("YES")
    else:
        print("NO")

    