from enum import unique
import sys

while True:
    num_of_diff_char = int(sys.stdin.readline())
    if num_of_diff_char == 0:
        break
    command = list(sys.stdin.readline())
    length = len(command) - 1 # \n
    start = 0
    if length >= num_of_diff_char:
        max = num_of_diff_char
        end = num_of_diff_char
        result = num_of_diff_char
    else:
        max = length
        end = length
        result = length

    char_appear_num = [0]*300
    unique_char_num = 0
    for i in range(start, end):
        if char_appear_num[ord(command[i])] < 1:
            unique_char_num += 1
        char_appear_num[ord(command[i])] += 1

    #print(max, unique_char_num, start, end)
    #solve by brute
    while True:

        if end > length - 1:
            break
        
        max += 1

        if char_appear_num[ord(command[end])] < 1:
            unique_char_num += 1
        char_appear_num[ord(command[end])] += 1

        if unique_char_num > num_of_diff_char:
            if char_appear_num[ord(command[start])] == 1:
                unique_char_num -= 1
            char_appear_num[ord(command[start])] -= 1
            start += 1
            max -= 1
        end += 1

        if result < max:
            result = max

    print(result)
