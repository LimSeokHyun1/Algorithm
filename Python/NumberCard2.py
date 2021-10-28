import sys

numberdb = [0]*20000001
N = int(input())
numbers = list(map(int, input().split()))
for i in range(N):
    if numbers[i] < 0:
        numberdb[numbers[i] + 10000000] += 1
    else:
        numberdb[numbers[i] + 10000000] += 1
M = int(input())
target = list(map(int, input().split()))
for i in range(M):
    if numbers[i] < 0:
        print(numberdb[target[i] + 10000000], end=' ')
    else:
        print(numberdb[target[i] + 10000000], end=' ')
