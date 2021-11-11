import collections
import sys

A, B, V = map(int, sys.stdin.readline().split())

res = (V-A) // (A-B) + 1
if A == V:
    res = 1
    print(res)
else:
    if (V-A) % (A-B) != 0:
        res += 1
    print(res)
