import sys

N = int(input())
queue = []
for _ in range(N):
    inst = sys.stdin.readline().split()
    if inst[0] == 'push':
        queue.insert(0, inst[1])
    elif inst[0] == 'pop':
        if len(queue) != 0:
            print(queue.pop())
        else:
            print('-1')
    elif inst[0] == 'size':
        print(len(queue))
    elif inst[0] == 'empty':
        if len(queue) == 0:
            print('1')
        else:
            print('0')
    elif inst[0] == 'front':
        if len(queue) != 0:
            print(queue[-1])
        else:
            print('-1')
    elif inst[0] == 'back':
        if len(queue) != 0:
            print(queue[0])
        else:
            print('-1')
