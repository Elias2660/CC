import sys
sys.setrecursionlimit(200000)




cow_relations = {}

def cow_year(zodiac):
    if zodiac == "Ox": return 0
    if zodiac == "Tiger": return 1
    if zodiac == "Rabbit":return 2
    if zodiac == "Dragon": return 3
    if zodiac == "Snake": return 4
    if zodiac == "Horse": return 5
    if zodiac == "Goat":return 6
    if zodiac == "Monkey":return 7
    if zodiac == "Rooster":return 8
    if zodiac == "Dog":return 9
    if zodiac == "Pig":return 10
    if zodiac == "Rat": return 11


N = int(input())
for cow_relation in range(N):
    cow_statement = input().split()
    if cow_statement[4] == "previous":
        cow_relations[cow_statement[0]] = [cow_statement[-1], "previous"]
        cow_relations[cow_statement[-1]] = [cow_statement[0], "after"]
    elif cow_statement[4] == "next":
        ...

    
