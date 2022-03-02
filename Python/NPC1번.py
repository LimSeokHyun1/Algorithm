import sys
import collections

entire_students, jo_room_num, feel_good_num, dorm_period = map(int, sys.stdin.readline().split())
score = [0] * entire_students
room = []
for i in range(entire_students):
    room.append(i)
hong = 0
jo = jo_room_num - 1

if abs(jo - hong) <= feel_good_num:
    num_of_feel_good = 1
    max_feel_good = 1
    temp = 1
    temp_origin = 1
else:
    num_of_feel_good = 0
    max_feel_good = 0
    temp = 0
    temp_origin = 0

swap_temp = 0
for _ in range(dorm_period - 1):

    bonus_points = sys.stdin.readline().split()
    minus_points = sys.stdin.readline().split()

    for i in range(entire_students):
        bonus_points[i] = int(bonus_points[i])
        minus_points[i] = int(minus_points[i])

    for i in range(entire_students):
        num = 0
        for j in range(entire_students):
            if room[j] == i:
                num = j
                break
        score[num] = bonus_points[i] - minus_points[i]

    for i in range(entire_students - 1):
        swap_flag = 0
        if score[i] >= 0 and score[i + 1] >=0:
            if score[i + 1] - score[i] >= 2:
                score[i + 1] = score[i] + 2
                room[i], room[i+1] = room[i+1], room[i]
                swap_flag = 1
        elif score[i] < 0 and score[i + 1] >= 0:
            score[i + 1] = score[i] + 2
            room[i], room[i+1] = room[i+1], room[i]
            swap_flag = 1
        elif score[i] < 0 and score[i + 1] < 0:
            if score[i + 1] - score[i] >= 4:
                score[i + 1] = score[i] + 2
                room[i], room[i+1] = room[i+1], room[i]
                swap_flag = 1
        
        if swap_flag == 1:
            if i == hong:
                hong += 1
            elif i + 1 == hong:
                hong -= 1
            if i == jo:
                jo += 1
            elif i + 1 == jo:
                jo -= 1


    if abs(jo - hong) <= feel_good_num:
        num_of_feel_good += 1
        temp += 1
    else:
        temp = 0

    if temp > max_feel_good:
        max_feel_good = temp
        
if num_of_feel_good == 0:
    max_feel_good = 0
print(num_of_feel_good, max_feel_good)
