import sys
import collections

N = int(input())
max = 0
rope = collections.deque()
for _ in range(N):
    rope.append(int(sys.stdin.readline()))

rope = sorted(rope)

for i in range(N):
    if max < rope[i] * (N-i):
        max = rope[i] * (N-i)
print(max)
