import sys

N = int(input())
numbers = [0] * 10000
for i in range(N):
    numbers[int(sys.stdin.readline()) - 1] += 1

for i in range(10000):
    for j in range(numbers[i]):
        print(i + 1)

