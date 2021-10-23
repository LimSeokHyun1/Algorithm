import sys

N = int(input())
numDB = [0]*10000000
numcards = sys.stdin.readline().split()
for i in range(N):
    if(numDB[abs(int(numcards[i]))] == 0):
        if int(numcards[i]) >= 0:
            numDB[abs(int(numcards[i]))] = 1
        else:
            numDB[abs(int(numcards[i]))] = 2
    else:
        numDB[abs(int(numcards[i]))] = 3

M = int(input())
numbers = sys.stdin.readline().split()
for i in range(M):
    if int(numbers[i]) > 0:
        if numDB[abs(int(numbers[i]))] == 1 or numDB[abs(int(numbers[i]))] == 3:
            print('1')
        else:
            print('0')
    else:
        if numDB[abs(int(numbers[i]))] == 2 or numDB[abs(int(numbers[i]))] == 3:
            print('1')
        else:
            print('0')
            
'''
Binary Search 사용하면 nlogn으로 풀 수 있음.
'''
