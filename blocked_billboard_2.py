"""
PYTHON SOLUTION

USACO 2018 January Contest, Bronze
Problem 1. Blocked Billboard II

Link to the problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=783 
"""
import sys
sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out","w")

mx1, my1, mx2, my2 = map(int, input().split())
cx1, cy1, cx2, cy2 = map(int, input().split())

if cx1 <= mx1 and cy1 <= my1 and cx2 >= mx2 and cy2 >= my2:
    print(0)

elif cx1 <= mx1 and cx2 >= mx2 and cy2 > my1 and cy1 <= my1:
    print((mx2-mx1)*(my2-cy2))

elif cx1 <= mx1 and cx2 >= mx2 and cy2 >= my2 and cy1 < my2:
    print((cy1-my1)*(mx2-mx1))

elif cy1 <= my1 and cy2 >= my2 and cx2 > mx1 and cx1 <= mx1:
    print((mx2-cx2)*(my2-my1))

elif cy1 <= my1 and cy2 >= my2 and cx2 >= mx2 and cx1 < mx2:
    print((cx1-mx1)*(my2-my1))

else:
    print((mx2-mx1)*(my2-my1))