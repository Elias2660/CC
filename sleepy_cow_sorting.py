number_of_cows = int(input())
cows = [int(number.replace(" ", "")) for number in input().split()]


for number in range(number_of_cows, 0, -1):
    if cows[number-1] < cows[number - 2]:
        print(number-1)
        break
   
