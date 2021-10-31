T = int(input())
for _ in range(T):
    parenthesis = list(sys.stdin.readline().rstrip())
    parent_len = len(parenthesis)
    right_num = 0
    fail = 0
    for _ in range(parent_len):
        if parenthesis.pop() == ')':
            right_num += 1
        else:
            if right_num == 0:
                fail = 1
            right_num -= 1
    if right_num == 0 and fail == 0:
        print("YES")
    else:
        print("NO")
