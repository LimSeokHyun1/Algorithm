import sys
import collections

flag = 0

class AC:
    def __init__(self):
        self.toggle = True

    def reverse(self, numbers):
        self.toggle = not self.toggle

    def discard(self, numbers):
        if not numbers:
            print('error')
            global flag
            flag = 1
        else:
            if self.toggle == True:
                numbers.popleft()
            else:
                numbers.pop()
    def printnum(self, numbers):
        print('[', end='')
        if self.toggle == True:
            for i in range(len(numbers)):
                if i == len(numbers) - 1:
                    print(numbers[i], end='')
                else:
                    print(numbers[i], end=',')
        else:
            for i in range(len(numbers)):
                if i == len(numbers) - 1:
                    print(numbers[len(numbers) - i - 1], end='')
                else:
                    print(numbers[len(numbers) - i - 1], end=',')
        print(']')



T = int(input())
my_ac = AC()
for _ in range(T):
    func = list(sys.stdin.readline().rstrip())
    num_count = int(input())
    my_ac.toggle = True
    if num_count == 0:
        numbers = sys.stdin.readline()
        numbers = []
    else:
        numbers = collections.deque(map(int, sys.stdin.readline().strip('[').strip(']\n').split(',')))#list로 풀면 4056ms, deque으로 풀면 808ms
    for i in func:
        if i == 'R':
            my_ac.reverse(numbers)
        else:
            my_ac.discard(numbers)
            if flag == 1:
                break
    if flag == 0:
        my_ac.printnum(numbers)
    flag = 0
