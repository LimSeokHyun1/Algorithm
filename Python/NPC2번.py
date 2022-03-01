import sys
import collections


capsaicin = int(sys.stdin.readline())
base_capsaicin = [1]
spicy_level = []
for i in base_capsaicin:
    if capsaicin >= 7 * i:
        base_capsaicin.append(7*i)
sort = len(base_capsaicin)

cnt = 0
for i in base_capsaicin:
    temp_cnt = cnt
    if capsaicin == i:
        print(cnt + 1)
        break
    spicy_level.append(i)
    cnt += 1
    for j in range(temp_cnt):
        if capsaicin == i + spicy_level[j]:
            print(cnt + 1)
            break
        spicy_level.append(i + spicy_level[j])
        cnt += 1
    if capsaicin == 2*i:
        print(cnt + 1)
        break
    spicy_level.append(2*i)
    cnt += 1
    for j in range(temp_cnt):
        if capsaicin == 2*i + spicy_level[j]:
            print(cnt + 1)
            break
        spicy_level.append(2*i + spicy_level[j])
        cnt += 1
