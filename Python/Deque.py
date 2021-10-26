import sys

class Deque:
    def __init__(self):
        self.deque = []

    def print_deque(self):
        print(self.deque)

    def size(self):
        print(len(self.deque))

    def is_empty(self):
        if len(self.deque) == 0:
            return 1
        else:
            return 0

    def push_front(self, num):
        self.deque.insert(0, num)
        return self.deque

    def push_back(self, num):
        self.deque.append(num)
        return self.deque

    def pop_front(self):
        if self.is_empty():
            print('-1')
        else:
            print(self.deque.pop(0))

    def pop_back(self):
        if self.is_empty():
            print('-1')
        else:
            print(self.deque.pop())

    def front(self):
        if self.is_empty():
            print('-1')
        else:
            print(self.deque[0])

    def back(self):
        if self.is_empty():
            print('-1')
        else:
            print(self.deque[-1])



N = int(input())
deque1 = Deque()
for _ in range(N):
    inst = sys.stdin.readline().split()
    if inst[0] == 'push_front':
        deque1.push_front(inst[1])
    elif inst[0] == 'push_back':
        deque1.push_back(inst[1])
    elif inst[0] == 'pop_front':
        deque1.pop_front()
    elif inst[0] == 'pop_back':
        deque1.pop_back()
    elif inst[0] == 'size':
        deque1.size()
    elif inst[0] == 'empty':
        print(deque1.is_empty())
    elif inst[0] == 'front':
        deque1.front()
    elif inst[0] == 'back':
        deque1.back()
