
"""http://www.usaco.org/index.php?page=viewproblem2&cpid=567"""
farmer = [int(number) for number in input().split()]
cow = [int(number) for number in input().split()]

if cow[0] > farmer[0] and cow[1] < farmer[1]:
    print(farmer[1] - farmer[0])
elif cow[0] < farmer[0] and cow[1] > farmer[1]:
    print(cow[1]-cow[0])
elif cow[1] > farmer[0] and cow[1] < farmer[0]:
    print(farmer[1]-cow[0])
elif farmer[1] > cow[0] and farmer[1] < cow[1]:
    print(cow[1]-farmer[1])
else:
    print(cow[1]-cow[0]+farmer[1]-farmer[0])