import sys
import collections

N, M = map(int, sys.stdin.readline().split())
plate = [sys.stdin.readline().rstrip() for _ in range(N)]

def make_surround(weight):
    surround = []
    for i in range(-1 * weight, weight + 1):
        surround.append([weight, i])
        if weight != i:
            surround.append([i, weight])
    for i in range(-1*(weight - 1), weight):
        surround.append([-1*weight, i])
        surround.append([i, -1*weight])
    surround.append([-1*weight, -1*weight])
    return surround

hit_blank = []
for i in range(N):
    for j in range(M):
        if plate[i][j] == '1':
            hit_blank.append([i, j])

for i, j in hit_blank:
    fail_flag = 0
    for a in range(9):
        check = 0
        flag = 0
        move = make_surround(a+1)
        for dx, dy in move:
            if i+dx >= 0 and j+dy >= 0 and i+dx < N and j+dy < M:
                #print(i+dx, j+dy)
                if plate[i+dx][j+dy] == '1':
                    #print(i, j, a, "일 때: ", i+dx, i+dy)
                    if check == 1: # check = 1일때, 즉 찾았을 때 더찾으면 flag = 1
                        flag = 1
                        break
                    else: #찾으면 check = 1  => 정상적이면 check = 1이고 flag = 0
                        check = 1
        if check == 0 or flag == 1: # 한 중심 정해서 드가는 도중 한 weight가 실패하면 break
            fail_flag = 1
            break
    if fail_flag != 1:
        print(i, j)
        break
if fail_flag == 1:
    print('-1')
