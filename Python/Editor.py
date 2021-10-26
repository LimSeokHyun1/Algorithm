import sys

class Node():
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next


class DoublyLinkedList():
    def __init__(self):
        self.head = Node('head', None, None)
        self.tail = Node('tail', self.head, None)
        self.cursor = self.tail
        self.head.next = self.tail

    def move(self, inst):
        if inst == 'L':
            if self.cursor.prev.data != 'head':
                self.cursor = self.cursor.prev
        if inst == 'D':
            if self.cursor.data != 'tail':
                self.cursor = self.cursor.next

    def delete(self):
        if self.cursor.prev.data != 'head':
            self.cursor.prev = self.cursor.prev.prev
            self.cursor.prev.next = self.cursor

    def append(self, data):
        node = Node(data, self.cursor.prev, self.cursor)
        self.cursor.prev.next = node
        self.cursor.prev = node
    def print(self):
        if self.tail.prev.data == 'head':
            print("[ ]")
        else:
            p = self.head.next
            while p != self.tail:
                print(p.data, end= '')
                p = p.next
            print("")

init = list(sys.stdin.readline().rstrip())
M = int(input())
mylinkedlist = DoublyLinkedList()

for i in init:
    mylinkedlist.append(i)

for _ in range(M):
    inst = sys.stdin.readline().split()
    if inst[0] == 'L':
        mylinkedlist.move('L')
    elif inst[0] == 'D':
        mylinkedlist.move('D')
    elif inst[0] == 'B':
        mylinkedlist.delete()
    elif inst[0] == 'P':
        mylinkedlist.append(inst[1])
mylinkedlist.print()
