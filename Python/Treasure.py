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
