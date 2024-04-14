N, M = list(map(int, input().split()))
starts = []
ends = []

for _ in range(M):
    i, j = input().split()
    starts.append(int(i))
    ends.append(int(j))

starts.sort()
ends.sort()

index_start, index_end, f, n, last = 0, 0, 0, 0, 0
while True:
    if (
        starts[index_start] < ends[index_end]
    ):
        if n == 0:
            f += starts[index_start] - last
        last = starts[index_start]
        index_start += 1
        n += 1
    elif starts[index_start] > ends[index_end]:
        last = ends[index_end]
        index_end += 1
        n -= 1
    else:
        last = ends[index_end]
        index_end += 1
        index_start += 1

  
    if (index_end == len(ends)):
        break
    elif index_start == len(starts):
        last = ends[index_end]
        index_end += 1
        n -= 1
        break
    

print(f + N - ends[len(ends) - 1])
