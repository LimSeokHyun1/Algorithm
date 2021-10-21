N = int(input())
numbers = [0] * N
for i in range(N):
    numbers[i] = (int(input()))
numbers.sort()
for i in range(N):
    print(numbers[i])
