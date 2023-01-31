"""solution for this problem"""

# import sys
from typing import List

# sys.stdin = open('backforth.in', 'r')
# sys.stdout = open('backforth.out', 'w')

possible = set()

def get_possible(
	day: int,
	a_tank: int, a_buckets: List[int],
	b_tank: int, b_buckets: List[int]
) -> None:
	# Last day, add the amount of milk in the first tank.
	if day == 4:
		possible.add(a_tank)
		return
		
	# This transfers every possible bucket from barn x to barn y.
	for i in range(len(a_buckets)):
		# Bucket to transfer.
		t = a_buckets[i]

		# Creates a new copy of available buckets, and transfers the ith one.
		new_a = a_buckets.copy()
		del new_a[i]
		new_b = b_buckets.copy()
		new_b.append(t)

		# Recursively call the function with the new buckets and tank amounts.
		get_possible(day + 1, b_tank + t, new_b, a_tank - t, new_a)

a = list(map(int, input().split()))
b = list(map(int, input().split()))

get_possible(0, 1000, a, 1000, b)

print(len(possible))




        