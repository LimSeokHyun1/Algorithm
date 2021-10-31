import sys

my_stack = [0]
numlist = []
result = []
fail = 0
n = int(input())
for i in range(n, 0, -1):
    numlist.append(i)

for _ in range(n):
    num = int(input())
    if fail == 1:
        continue
    elif my_stack[-1] < num:
        while True:
            temp = numlist.pop()
            my_stack.append(temp)
            result.append("+")
            if temp > num:
                fail = 1
                break
            elif temp == num:
                break
        my_stack.pop()
        result.append("-")
    elif my_stack[-1] == num:
        my_stack.pop()
        result.append("-")
    else:
        fail = 1

if fail == 1:
    print("NO")
else:
    for i in result:
        print(i)
