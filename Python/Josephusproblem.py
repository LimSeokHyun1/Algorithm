import sys

class CircularQueue:
    def __init__(self, peoplenum):
        self.peoplenum = peoplenum
        self.cqueue = list(range(1, peoplenum + 1))
        self.pointer = 0
        self.result = []

    def next_person(self, K):
        if self.pointer + K - 1 < self.peoplenum:
            self.pointer += K - 1
        else:
            self.pointer = (self.pointer + K - 1) % self.peoplenum

    def remove_people(self, K):
        for _ in range(self.peoplenum):
            self.next_person(K)
            self.result.append(self.cqueue.pop(self.pointer))
            self.peoplenum -= 1

N, K = map(int, input().split())
circularqueue = CircularQueue(N)
circularqueue.remove_people(K)

print("<", end='')
for i in range(N):
    if i != N - 1:
        print(circularqueue.result[i], end=', ')
    else:
        print(circularqueue.result[i], end='')
print(">")


