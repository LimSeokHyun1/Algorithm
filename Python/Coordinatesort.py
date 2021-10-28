import sys

N = int(input())
pointlist = list()
for _ in range(N):
    x, y = map(int, input().split())
    pointlist.append((x, y))
pointlist = sorted(pointlist, key=lambda point: point[1])
pointlist = sorted(pointlist, key=lambda point: point[0])
for i in range(N):
    print(pointlist[i][0], pointlist[i][1])
