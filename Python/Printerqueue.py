import sys

N = int(input())
for _ in range(N):
    num_list = []
    result = 0
    count, loc = map(int, input().split())
    num_list = list(map(int, sys.stdin.readline().split()))
    index_list = list(i for i in range(0, count))

    while True:
        flag = 0
        for i in num_list:
            if num_list[0] < i:
                num_list.append(num_list.pop(0))
                index_list.append(index_list.pop(0))
                flag = 1
        if flag == 0:
            result += 1
            num_list.pop(0)
            if loc == index_list.pop(0):
                print(result)
                break
        
