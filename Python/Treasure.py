import sys

N = int(input())
result = 0
listA = sys.stdin.readline().split()
listB = sys.stdin.readline().split()

for i in range(N):
    listA[i] = int(listA[i])
    listB[i] = int(listB[i])
listA.sort()
listB.sort(reverse=True)

for i in range(N):
    result += int(listA[i]) * int(listB[i])

print(result)

================================================================

# B는 재배열 불가 조건 추가 + greedy algorithm
import sys

N = int(input())
result = 0

listA = list(map(int, sys.stdin.readline().split()))
listB = list(map(int, sys.stdin.readline().split()))
visited = [0] * N

listA.sort()

for i in range(N):
    maximum = 0
    max_idx = 0
    for j in range(N):
        if maximum < listB[j] and visited[j] == 0:
            maximum = listB[j]
            max_idx = j
    visited[max_idx] = 1
    result += maximum * listA[i]

print(result)
